#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <strings.h>
#include <stdlib.h> // converting const char * to int . used for parsing the port number -- atoi(const char * x) method
#include <stdio.h>


void printsin(struct sockaddr_in *sin, char *str1, char *str2) {
    printf("SINK: %s ip= %s\n", str2, inet_ntoa(sin->sin_addr));
    // inet_ntoa function converts binary ip address to dot separated storing notation
    // sin->sin_addr is and struct in_addr type inside sockaddr_in type .
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("<port> is required as argument\n");
    } else {
        int socket_fd, cc, fsize;
        struct sockaddr_in s_in, from;
        struct {
            char head;
            u_long body;
            char tail;
        } msg;

        socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

        bzero((char *) &s_in, sizeof(s_in));

        s_in.sin_family = (short) AF_INET;
        s_in.sin_addr.s_addr = htonl(INADDR_ANY);
        s_in.sin_port = htons((u_short) atoi((const char *) argv[1]));

        printsin(&s_in, "RECV_UDP", "Local socket is:"); // calling the function
        fflush(stdout);

        bind(socket_fd, (struct sockaddr *) &s_in, sizeof(s_in));

        for (;;) {
            fsize = sizeof(from);
            cc = recvfrom(socket_fd, &msg, sizeof(msg), 0, (struct sockaddr *) &from, &fsize);
            printsin(&from, "recv_udp: ", "Packet from:"); // calling the function
            printf("Got data: %c%ld%c\n\n", msg.head, (long) ntohl(msg.body), msg.tail);
            fflush(stdout);
        }
    }
    return 0;
}

