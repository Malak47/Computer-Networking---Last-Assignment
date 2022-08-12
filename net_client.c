#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SIM_LENGTH 10
//#define IP_ADDRESS "?????" // IP address was not defined should be replaced with local IP address 192.168.0.108
#define IP_ADDRESS "10.0.2.15"

#define PORT 9999

//int main(void) // command line argument was not handled initially
int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in cli_name;
    int count;
    int value;

    char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int i;
    for (i = 0; argv[1][i] != '\0'; ++i) {
        hostbuffer[i] = argv[1][i];
    }
    hostbuffer[i] = '\0';
    host_entry = gethostbyname(hostbuffer);
    if (host_entry == NULL) exit(1);

    // To convert an Internet network
    // address into ASCII string
    IPbuffer = inet_ntoa(*((struct in_addr *)
            host_entry->h_addr_list[0])); // taking the first ip address from the list of ip addresses associated with the hostname
    if (IPbuffer == NULL) exit(1);
    printf("+");
    i=0;
    while(i<38+strlen(hostbuffer)+strlen(IPbuffer)){
        printf("-");
        i++;
    }
    printf("+");
    printf("\n| Server hostname: <%s> with address: <%s> |\n", hostbuffer, IPbuffer);
    i=0;
    printf("+");
    while(i<38+strlen(hostbuffer)+strlen(IPbuffer)){
        printf("-");
        i++;
    }
    printf("+\n");
    // hostaddr = inet_ntoa(saddr->sin_addr); // converting the IP address to dot separated string

    printf("Client is alive and establishing socket connection.\n");

    sock = socket(AF_INET, SOCK_STREAM, 0); // SOCK_STREAM indicating TCP connection oriented protocol
    if (sock < 0) {
        perror("Error opening channel");
        printf("%d", sock);
        close(sock);
        exit(1);
    }


    bzero(&cli_name, sizeof(cli_name)); // initiating socket structures with null
    cli_name.sin_family = AF_INET; // socket family TCP/UDP
    // cli_name.sin_addr.s_addr = inet_addr(IP_ADDRESS); // COMPILATION : warning: implicit declaration of function ‘inet_addr’ [-Wimplicit-function-declaration]
    // library required #include <arpa/inet.h>  to solve the problem
    cli_name.sin_addr.s_addr = inet_addr(IPbuffer);
    cli_name.sin_port = htons(PORT); // setting port parameter on socket structure


    if (connect(sock, (struct sockaddr *) &cli_name, sizeof(cli_name)) <
        0) // connection to tcp socket success for failure
    {
        perror("Error establishing communications");
        close(sock); // closing the client connection socket
        exit(1);
    }


    for (count = 1; count <= SIM_LENGTH; count++) {
        read(sock, &value,
             4); // waiting to receive 4 bytes . on receiving 4 bytes it will be stored to and integer variable . given address &value
        printf("Client has received %d from socket.\n", value); // printing on console for confirmation
    }

    printf("Exiting now.\n");

    close(sock); // closing the client connection socket
    exit(0); // exiting with error code 0 . mean successful run . returning back the control to OS
} 
