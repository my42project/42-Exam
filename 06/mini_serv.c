#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 1024
#define MAX_MSG_SIZE 1024

typedef struct {
    int id;
    char msg[MAX_MSG_SIZE];
} Client;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }

    int sockfd, client_sockets[MAX_CLIENTS], n_id = 0, max_fd = 0;
    struct sockaddr_in servaddr, cli;
    socklen_t len;

    fd_set sockets, w_sock, r_sock;
    Client c[MAX_CLIENTS];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Fatal error");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1 || listen(sockfd, 10)) {
        perror("Fatal error");
        exit(EXIT_FAILURE);
    }

    len = sizeof(cli);

    FD_ZERO(&sockets);
    FD_SET(sockfd, &sockets);

    while (1) {
        r_sock = w_sock = sockets;

        if (select(max_fd + 1, &r_sock, &w_sock, NULL, NULL) < 0) {
            continue;
        }

        for (int fd = 0; fd <= max_fd; fd++) {
            if (FD_ISSET(fd, &r_sock) && fd == sockfd) {
                int cfd;

                if ((cfd = accept(sockfd, (struct sockaddr *)&cli, &len)) != -1) {
                    c[cfd].id = n_id++;
                    max_fd = (cfd > max_fd) ? cfd : max_fd;
                    FD_SET(cfd, &sockets);
                    dprintf(cfd, "server: client %d just arrived\n", c[cfd].id);
                }

                break;
            }

            if (FD_ISSET(fd, &r_sock) && fd != sockfd) {
                int res = recv(fd, c[fd].msg, sizeof(c[fd].msg), 0);

                if (res == -1) {
                    dprintf(fd, "server: client %d just left\n", c[fd].id);
                    FD_CLR(fd, &sockets);
                    close(fd);
                } else {
                    c[fd].msg[res] = '\0';

                    for (int i = 0, j = strlen(c[fd].msg); i < res; i++, j++) {
                        if (c[fd].msg[j] == '\n') {
                            c[fd].msg[j] = '\0';
                            dprintf(fd, "client %d: %s\n", c[fd].id, c[fd].msg);
                            memset(c[fd].msg, 0, sizeof(c[fd].msg));
                            j = -1;
                        }
                    }
                }

                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
