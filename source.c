#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h> // sleep function defined here
#include <stdlib.h> // converting const char * to int . used for parsing the port number -- atoi(const char * x) method
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("<host> <port> is required as argument\n");
    } else {
        int socket_fd;
        struct sockaddr_in dest;
        struct hostent *hostptr;
        struct {
            char head;
            u_long body;
            char tail;
        } msgbuf;

        socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
        bzero((char *) &dest, sizeof(dest));
        hostptr = gethostbyname(argv[1]);
        dest.sin_family = (short) AF_INET;
        bcopy(hostptr->h_addr, (char *) &dest.sin_addr, hostptr->h_length);
        dest.sin_port = htons(
                (u_short) atoi((const char *) argv[2])); // you can hardcode this with your assigned port also
        // currently taking the assigned port from command line
        printf("Entering an infinite loop for sending packets to:\n\n");
        printf("to Host: %s \n", inet_ntoa(dest.sin_addr));
        int packet_number = 1;
        for (;;) {
            printf("SOURCE: Sending <%d>\n\n", packet_number);
            printf("to Host: %s \n", inet_ntoa(dest.sin_addr));
            msgbuf.head = '<';
            msgbuf.body = htonl(packet_number++);
            msgbuf.tail = '>';

            sendto(socket_fd, &msgbuf, sizeof(msgbuf), 0, (struct sockaddr *) &dest,
                   sizeof(dest));
            sleep(1);
        }
    }
    return 0;
}
