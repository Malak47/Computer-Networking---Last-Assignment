
#include <unistd.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define SIM_LENGTH 10
#define IP_ADDRESS "10.0.2.15" // IP address was not defined should be replaced with local IP address 192.168.0.108
#define PORT 80

//int main(void) // command line argument was not handled initially

int parse_url(char *x, char *r) {
    int countered = 0;
    int port = PORT;
    char p[10];
    int i, k, j;
    for (i = 0, j = 0, k = 0; x[i] != '\0'; ++i) {
        if (x[i] == '/' || x[i] == ':') {
            countered++;
            continue;
        }
        if (countered == 3 && x[i] != ':') {
            r[j] = x[i];
            ++j;
        } else if (countered == 3 && x[i] != '/') {
            r[j] = x[i];
            ++j;
        }
        if (countered == 4 && x[i] == ':') {
            p[k] = x[++i];
            ++k;
        }
    }
    p[k] = '\0';
    r[j] = '\0';
    if (k) {
        port = atoi(p);
    }
    return port;
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in cli_name;

    char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int i;
    for (i = 0; argv[1][i] != '\0'; ++i) {
        hostbuffer[i] = argv[1][i];
    }
    hostbuffer[i] = '\0';
    char parsed_host[256];
    int Port = parse_url(hostbuffer, parsed_host);
    printf("%s\n", parsed_host);
    host_entry = gethostbyname(parsed_host);
    if (host_entry == NULL) exit(1);

    for (int k = 0; host_entry->h_addr_list[k] != NULL; ++k) {
        // To convert an Internet network
        // address into ASCII string
        IPbuffer = inet_ntoa(*((struct in_addr *)
                host_entry->h_addr_list[k])); // taking the first ip address from the list of ip addresses associated with the hostname
        if (IPbuffer == NULL) exit(1);
        printf("Server host name %s with address %s\n", hostbuffer, IPbuffer);
        // hostaddr = inet_ntoa(saddr->sin_addr); // converting the IP address to dot separated string
    }
    printf("Client is alive and establishing socket connection.\n");
    printf("Connecting to %s:%d\n", IPbuffer, PORT);
    sock = socket(AF_INET, SOCK_STREAM, 0); // SOCK_STREAM indicating TCP connection oriented protocol
    // getting stuck here when connection to the ip address of www.yahoo.com 202.165.107.49
    if (sock < 0) {
        perror("Error opening channel");
        printf("%d", sock);
        close(sock);
        exit(1);
    }

    printf("Connecting to %s:%d\n", IPbuffer, PORT);
    bzero(&cli_name, sizeof(cli_name)); // initiating socket structures with null
    cli_name.sin_family = AF_INET; // socket family TCP/UDP
    // cli_name.sin_addr.s_addr = inet_addr(IP_ADDRESS); // COMPILATION : warning: implicit declaration of function ‘inet_addr’ [-Wimplicit-function-declaration]
    // library required #include <arpa/inet.h>  to solve the problem
    // cli_name.sin_addr.s_addr = inet_addr(IPbuffer);
    cli_name.sin_addr = *(struct in_addr *) host_entry->h_addr_list[0];
    cli_name.sin_port = htons(Port); // setting port parameter on socket structure
    if (connect(sock, (struct sockaddr *) &cli_name, sizeof(cli_name)) <
        0) // connection to tcp socket success for failure
    {
        perror("Error establishing communications");
        close(sock); // closing the client connection socket
        exit(1);
    }
    printf("Connection Established with %s:%d\n", IPbuffer, PORT);
    char req[512];
    char get[] = "GET ";
    char http_head[] = " HTTP/1.0\n";
    char hostName[] = "HOST: ";
    i = 0;
    for (int j = 0; get[j] != '\0'; ++i, ++j) {
        req[i] = get[j];
    }
    for (int j = 0; hostbuffer[j] != '\0'; ++i, ++j) {
        req[i] = hostbuffer[j];
    }
    for (int j = 0; http_head[j] != '\0'; ++i, ++j) {
        req[i] = http_head[j];
    }
    for (int j = 0; hostName[j] != '\0'; ++i, ++j) {
        req[i] = hostName[j];
    }
    for (int j = 0; IPbuffer[j] != '\0'; ++i, ++j) {
        req[i] = IPbuffer[j];
    }
    req[i++] = '\n';
    req[i++] = '\n';
    req[i++] = '\0';
    printf("Sending http header\n");
    write(sock, &req, i);
    printf("waiting for http response\n");
    char received[8192];
    i = 0;
    char rc;
    while (1) {
        if (read(sock, &rc, 1)) { // reading each character one by one
            received[i++] = rc;
        } else // indicated no data available
            break;
    }
    received[i] = '\0'; // adding the null character
    // { read(sock, &received, 4096); // waiting to receive 2048 bytes .
    printf("Client has received :\n%s\n", received); // printing on console for confirmation
    printf("Received Length : %d\n", i - 1);
    printf("Exiting now.\n");

    close(sock); // closing the client connection socket

    exit(0); // exiting with error code 0 . mean successful run . returning back the control to OS
} 
