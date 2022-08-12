#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Define Variables
    int socket_fd;
    struct sockaddr_in dest;
    struct hostent *hostptr;
    struct {
        char head;
        u_long body;
        char tail;
    } msgbuf;

    //Creating a UDP socket for communication
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    //Memory cleanup
    bzero((char *) &dest, sizeof(dest));
    //Copy the hostnet for the provided host name
    hostptr = gethostbyname(argv[1]);
    //Define the type of IP/ports address family
    dest.sin_family = (short) AF_INET;
    //Copying the date in hostptr to the dest address
    bcopy(hostptr->h_addr, (char *) &dest.sin_addr, hostptr->h_length);
    //Converts from host byte to network byte
    dest.sin_port = htons((u_short) 0x3333);
    //Part of the body of the message
    msgbuf.head = '<';
    //Obtain the process ID
    msgbuf.body = htonl(getpid());
    //Part of the body of the message
    msgbuf.tail = '>';
    //Prints the data/message
    sendto(socket_fd, &msgbuf, sizeof(msgbuf), 0, (struct sockaddr *) &dest,
           sizeof(dest));

    return 0;
}
