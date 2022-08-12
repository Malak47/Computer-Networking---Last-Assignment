# Makefile for all files

TARGET = gateway http_client net_client net_server nslookup recv_udp send_udp sink source

all: $(TARGET)

gateway: gateway.c
	gcc -Wall -o gateway gateway.c
	
http_client: http_client.c
	gcc -Wall -o http_client http_client.c
	
net_client: net_client.c	
	gcc -Wall -o net_client net_client.c
	
net_server: net_server.c
	gcc -Wall -o net_server net_server.c
	
nslookup: nslookup.c
	gcc -Wall -o nslookup nslookup.c
	
recv_udp: recv_udp.c
	gcc -Wall -o recv_udp recv_udp.c

send_udp: send_udp.c
	gcc -Wall -o send_udp send_udp.c
	
sink: sink.c
	gcc -Wall -o sink sink.c
	
source: source.c
	gcc -Wall -o source source.c

clean:
	rm -f *.o $(TARGET)
