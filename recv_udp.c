#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <strings.h>
#include <stdio.h>


void printsin(struct sockaddr_in *sin, char *str1, char *str2) {
    printf("%s\n%s ip= %s, port= %d\n",str1, str2, inet_ntoa(sin->sin_addr), sin->sin_port);
    // inet_ntoa function converts binary ip address to dot separated storing notation
    // sin->sin_addr is and struct in_addr type inside sockaddr_in type .
}


int main(int argc, char *argv[]) {
    //Define variables
    int socket_fd, cc, fsize;
    struct sockaddr_in s_in, from;
    struct {
        char head;
        u_long body;
        char tail;
    } msg;

    //Creating a UDP socket for communication
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    //Memory cleanup
    bzero((char *) &s_in, sizeof(s_in));
    //Declare the type of IP/ports address
    s_in.sin_family = (short) AF_INET;
    //Binds the sockets to all available interfaces
    s_in.sin_addr.s_addr = htonl(INADDR_ANY);
    //Converts from host byte to network byte
    s_in.sin_port = htons((u_short) 0x3333);

    printsin(&s_in, "RECV_UDP:", "Local socket is:"); // calling the function
    fflush(stdout);
    //Binds the unbound socket to the address given
    bind(socket_fd, (struct sockaddr *) &s_in, sizeof(s_in));

    for (;;) {
        fsize = sizeof(from);
        //Enable receiving message from the socket
        cc = recvfrom(socket_fd, &msg, sizeof(msg), 0, (struct sockaddr *) &from, &fsize);
        printsin(&from, "RECV_UDP:", "Packet from:"); // calling the function
        //Prints the process ID that was sent from the socket
        printf("Got data: %c%ld%c\n", msg.head, (long) ntohl(msg.body), msg.tail);
        fflush(stdout);
    }

    return 0;
}

