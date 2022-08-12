# Makefile for all files

TARGET = org_net_client org_net_server org_nslookup

all: $(TARGET)

org_net_client: org_net_client.c	
	gcc -Wall -o org_net_client org_net_client.c
	
org_net_server: org_net_server	
	gcc -Wall -o org_net_server org_net_server.c
	
org_nslookup: org_nslookup.c
	gcc -Wall -o org_nslookup org_nslookup.c

clean:
	rm -f *.o $(TARGET)
