#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct
{
    int id;
    char msg[1024];
} Client;


int main(int ac, char **av) {
    if (ac != 2) {
        fprintf(stderr, "Wrong number of arguments\n");
        exit(1);
    }
	int sockfd, connfd, next_id = 0, max_fd = 0;
	struct sockaddr_in servaddr, cli;

    fd_set sockets, w_sock, r_sock;
    Client c[1024];

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) {
        perror("Fatal error");
		exit(1);
	} 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) || listen(sockfd, 10)) { 
        perror("Fatal error");
		exit(1);
	}

    FD_ZERO(&sockets);
    FD_SET(sockfd, &sockets);

    while (1) {
        r_sock = w_sock = sockets;
        if (select(max_fd + 1, &r_sock, &w_sock, 0, 0) == -1)
            continue ;
        for (int fd = 0; fd <= max_fd; fd++) {
            if (FD_ISSET(fd, &r_sock)) {
                if (sockfd == fd) {
                    if ((connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t *)sizeof(cli))) != -1) {
                        c[fd].id = next_id++;
                        max_fd = (connfd > max_fd) ? connfd : max_fd;
                        FD_SET(connfd, &sockets);
                        dprintf(connfd, "server: client %d just arrived\n", c[fd].id);
                    }
                    break;
                } else {
                    int res;
                    if ((res = recv(fd, c[fd].msg, sizeof(c[fd].msg), 0)) == -1) {
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
    }
}
