#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9999
#define SIM_LENGTH 10 // was not declared at the beginning issue solved

int main(void) {
    int sock;
    int connect_sock;
    struct sockaddr_in serv_name;
    size_t len;
    int count;

    sock = socket(AF_INET, SOCK_STREAM, 0);  // SOCK_STREAM indicating TCP connection oriented protocol

    bzero(&serv_name, sizeof(serv_name));
    serv_name.sin_family = AF_INET; // socket family TCP/UDP
    serv_name.sin_port = htons(PORT);

    bind(sock, (struct sockaddr *) &serv_name, sizeof(serv_name)); // binding host with associated socket

    listen(sock, 1); // listen on 1 maximum number of connection

    len = sizeof(serv_name);

    // connect_sock = accept(sock, (struct sockaddr *)&serv_name, &len); // parameter len is of type size_t * but required is socklen_t *
    connect_sock = accept(sock, (struct sockaddr *) &serv_name, (socklen_t *) &len);
    for (count = 1; count <= SIM_LENGTH; count++) // SIM_LENGTH was undeclared . solved by declaring at the beginning
    {
        write(connect_sock, &count, 4); // sending a single integer number with is of size 4 bytes . thus, 4 was given as 3rd parameter
        printf("Server has written %d to socket.\n", count); // printing on console for confirmation
    }
    close(connect_sock); // closing the connection .
    close(sock); // closing the socket .
    //if skips without closing the socket the port resource will be acquired and cannot be reused
    //unless other wise specified explicitly to reuse the port .

}
