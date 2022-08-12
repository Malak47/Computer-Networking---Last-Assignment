#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <strings.h>
#include <stdio.h> // for printing on the console
#include <stdlib.h> // for random() function

void printsin(struct sockaddr_in *sin, char *str1, char *str2) {
    printf("GATEWAY: %s IP= %s\n", str2, inet_ntoa(sin->sin_addr));
    // inet_ntoa function converts binary ip address to dot separated storing notation
    // sin->sin_addr is and struct in_addr type inside sockaddr_in type .
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("<host> <port> is required as argument\n");
    } else {
        int given_port = atoi((const char *) argv[2]);
        srandom(given_port); // using the port number as random seed
        int socket_fd_forwarding_agent;
        struct sockaddr_in dest;
        struct hostent *hostptr;
        struct {
            char head;
            u_long body;
            char tail;
        } msgbuf;

        socket_fd_forwarding_agent = socket(AF_INET, SOCK_DGRAM, 0);
        bzero((char *) &dest, sizeof(dest));
        hostptr = gethostbyname(argv[1]);
        dest.sin_family = (short) AF_INET;
        bcopy(hostptr->h_addr, (char *) &dest.sin_addr, hostptr->h_length);
        dest.sin_port = htons((u_short) (given_port + 1)); // forwarding destination port is P+1

        int socket_fd_receiver, cc, fsize;
        struct sockaddr_in s_in, from;
        struct {
            char head;
            u_long body;
            char tail;
        } msg;

        socket_fd_receiver = socket(AF_INET, SOCK_DGRAM, 0);

        bzero((char *) &s_in, sizeof(s_in));

        s_in.sin_family = (short) AF_INET;
        s_in.sin_addr.s_addr = htonl(INADDR_ANY);
        s_in.sin_port = htons((u_short) given_port); // using given port P from command line

        printsin(&s_in, "RECV_UDP", "Local socket is:"); // calling the function
        fflush(stdout);

        bind(socket_fd_receiver, (struct sockaddr *) &s_in, sizeof(s_in));

        for (;;) {
            fsize = sizeof(from);
            cc = recvfrom(socket_fd_receiver, &msg, sizeof(msg), 0, (struct sockaddr *) &from, &fsize);
            printsin(&from, "recv_udp: ", "Packet from:"); // calling the function
            printf("Got data: %c%ld%c\n", msg.head, (long) ntohl(msg.body), msg.tail);
            float send_probability =
                    ((float) random()) / ((float) RAND_MAX); // generating the decision parameter send_probability
            printf("Probability to send: %.2f\n", send_probability);
            if (send_probability > 0.5) { // comparing or taking the decision whether to send or not
                msgbuf.head = msg.head;
                msgbuf.body = msg.body;
                msgbuf.tail = msg.tail;
                // now forwarding the packet to the given port+1 with the same host address
                printf("Forwarding packet: %c%ld%c\n\n", msg.head, (long) ntohl(msg.body), msg.tail);
                sendto(socket_fd_forwarding_agent, &msgbuf, sizeof(msgbuf), 0, (struct sockaddr *) &dest,
                       sizeof(dest));
            } else { // probability is less than or equal 0.5 thus dumping the packet
                printf("Dumping the packet\n\n");
            }
            fflush(stdout);
        }
    }
    return 0;
}
