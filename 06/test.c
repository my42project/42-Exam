#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_client {
    int id;
    char msg[1024];
}   t_client;

t_client c[1024 * 4];
int n_id = 0, max_fd = 0;
fd_set sockets, w_sock, r_sock;

char b_read[12000], b_write[12000];

void    ft_err(const char *m) {
    write(2, m, strlen(m));
    exit(EXIT_FAILURE);
}

void    send_all(int not){
    for (int i = 0; i <= max_fd; i++)
        if (FD_ISSET(i, &w_sock) && i != not)
            send(i, b_write, strlen(b_write), 0);
}

int main(int ac, char **av) {
    if (ac != 2)
        ft_err("Wrong number arguments\n");

	int sockfd, cfd; // remove len
	struct sockaddr_in servaddr, cli; 

    socklen_t len; //create len

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
        ft_err("Fatal error\n");

	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); //port change
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) || listen(sockfd, 10))
        ft_err("Fatal error\n");

    len = sizeof(cli);
    
    // create
    max_fd = sockfd;
    FD_ZERO(&sockets);
    FD_SET(sockfd, &sockets);
    bzero(c, sizeof(c));

    while (1) {
        r_sock = w_sock = sockets;
        if (select(max_fd + 1, &r_sock, &w_sock, 0, 0 ) < 0)
            continue ;
        for (int fd = 0; fd < max_fd; fd++) {
            if (FD_ISSET(fd, &r_sock) && fd == sockfd) {
	            if ((cfd = accept(sockfd, (struct sockaddr *)&cli, &len)) == -1) // into for
                    continue ;
                c[cfd].id = n_id++;
                max_fd = cfd > max_fd ? cfd : max_fd;
                FD_SET(cfd, &sockets);
                sprintf(b_write, "server: client %d just arrived\n", c[cfd].id);
                send_all(cfd);
                break ;
            }
            if (FD_ISSET(fd, &r_sock) && fd != sockfd) {
                int res;
                if ((res = recv(fd, b_read, 65536, 0)) == -1) {
                    sprintf(b_write, "server: client %d just left\n", c[fd].id);
                    send_all(fd);
                    FD_CLR(fd, &sockets);
                    close(fd);
                    break ;
                } else {
                    for (int i = 0, j = strlen(c[fd].msg); i < res; i++, j++) {
                        c[fd].msg[j] = b_read[i];
                        if (c[fd].msg[j] == '\n') {
                            c[fd].msg[j] = '\0';
                            sprintf(b_write, "client %d: %s\n", c[fd].id, c[fd].msg);
                            send_all(fd);
                            bzero(&c[fd].msg, sizeof(c[fd].msg));
                            j = -1;
                        }
                    }
                    break ;
                }
            }
        }
    }
    return(EXIT_SUCCESS);
}
