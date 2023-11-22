#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

typedef struct
{
    int id;
    char msg[1024];
} Client;

void miniserv(int port) {
    int sockfd, connfd, next_id = 0, max_fd = 0;
	struct sockaddr_in servaddr, cli;
    fd_set sockets, w_sock, r_sock;
    Client c[1024];
    socklen_t len = sizeof(cli);

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        write(2, "Fatal error\n", 13);
        exit(EXIT_FAILURE);
    }
	bzero(&servaddr, sizeof(servaddr)); 
    bzero(c, sizeof(c));

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) || listen(sockfd, 10)) { 
        write(2, "Fatal error\n", 13);
        exit(EXIT_FAILURE);
	}
    max_fd = sockfd;
    FD_ZERO(&sockets);
    FD_SET(sockfd, &sockets);
    while (1)
    {
        r_sock = w_sock = sockets;
        if (select(max_fd + 1, &r_sock, &w_sock, 0, 0) == -1)
            continue;
        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (FD_ISSET(fd, &r_sock))
            {
                if (fd == sockfd)
                {
                    if ((connfd = accept(sockfd, (struct sockaddr *)&cli, &len)) < 0)
                        continue;
                    c[connfd].id = next_id++;
                    max_fd = connfd > max_fd ? connfd : max_fd;
                    FD_SET(connfd, &sockets);
                    char buff[120000];
                    sprintf(buff, "server: client %d just arrived\n", c[connfd].id);
                    for (int i = 0; i <= max_fd; i++)
                        if (FD_ISSET(i, &w_sock) && i != connfd)
                            write(i, buff, strlen(buff));
                }
                else {
                    int res;
                    char read[120000];
                    if ((res = recv(fd, read, 65536, 0)) <= 0)
                    {
                        char buff[120000];
                        sprintf(buff, "server: client %d just left\n", c[fd].id);
                        for (int i = 0; i <= max_fd; i++)
                            if (FD_ISSET(i, &w_sock) && i != fd)
                                write(i, buff, strlen(buff));
                        FD_CLR(fd, &sockets);
                        close(fd);
                    }
                    else
                    {
                        for (int i = 0, j = strlen(c[fd].msg); i < res; i++, j++)
                        {
                            c[fd].msg[j] = read[i];
                            if (c[fd].msg[j] == '\n')
                            {
                                c[fd].msg[j] = '\0';
                                char buff[120000];
                                sprintf(buff, "client %d: %s\n", c[fd].id, c[fd].msg);
                                for (int i = 0; i <= max_fd; i++)
                                    if (FD_ISSET(i, &w_sock) && i != fd)
                                        write(i, buff, strlen(buff));
                                bzero(&c[fd].msg, sizeof(c[fd].msg));
                                j = -1;
                            }
                        }
                    }
                }
                break ;
            }
        }
    }
   
}

int main(int ac, char **av) {
	if (ac != 2) {
        write(2, "Wrong number of arguments\n", 26);
        exit(EXIT_FAILURE);
    }
    miniserv(atoi(av[1]));
    return (EXIT_SUCCESS);
}
