
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h> //. to strcpy function

int main(int argc, char *argv[]) {
    struct addrinfo *res;
    char *hostname;
    char *hostaddr;
    struct sockaddr_in *saddr;

    if (argc != 2) { // checking command line argument count as will use argument as hostname
        perror("Usage: hostnamelookup <hostname>\n"); // error message to notify use to put right hostname as argument
        exit(1); // exiting the process with status code 1
    }

    hostname = argv[1]; // taking the 2nd argument as hostname . 1st argument is the name of the program by default

    if (0 != getaddrinfo(hostname, NULL, NULL, &res)) { // getting address with given hostname
        fprintf(stderr, "Error in resolving hostname %s\n",
                hostname); // unable to resolve the host with the local nslookup
        exit(1); // exiting the process with status code 1
    }

    saddr = (struct sockaddr_in *) res->ai_addr; // explicitly doing the type casting from addrinfo to sockaddr_in
    hostaddr = inet_ntoa(saddr->sin_addr); // converting the IP address to dot separated string

    printf("Address for %s is %s\n", hostname, hostaddr); // stdout hostname and address

    char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int i;
    for (i = 0; argv[1][i] != '\0'; ++i) {
        hostbuffer[i] = argv[1][i];
    }
    hostbuffer[i] = '\0';
    host_entry = gethostbyname(hostbuffer); // using gethostbyname to get host address informat list from the host name
    if (host_entry == NULL) exit(0);

    // To convert an Internet network
    // address into ASCII string
    IPbuffer = inet_ntoa(*((struct in_addr *)
            host_entry->h_addr_list[0]));
    if (IPbuffer == NULL) exit(0);
    printf("Address for %s is %s\n", hostname, IPbuffer);
    exit(0); // successful execution . returning back the control to OS with execution status 0
}
