NOTE: Extend the txt file or open it in full-screen to see it correctly :) 

 ▄████▄ 	  ▒█████  	 ███▄ ▄███▓  ██▓███  	 █    ██ 	▄▄▄█████▓	▓█████   ██▀███   	   ███▄    █	 ▓█████	▄▄▄█████▓	  █     █░	 ▒█████  	 ██▀███  	 ██ ▄█▀	 ██▓	 ███▄    █     ▄████ 
▒██▀ ▀█ 	 ▒██▒  ██▒	▓██▒▀█▀ ██▒ ▓██░  ██▒	 ██  ▓██▒	▓  ██▒ ▓▒	▓█   ▀  ▓██ ▒ ██▒ 	   ██ ▀█   █	 ▓█   ▀	▓  ██▒ ▓▒	 ▓█░ █ ░█░	▒██▒  ██▒	▓██ ▒ ██▒	 ██▄█▒ 	▓██▒	 ██ ▀█   █    ██▒ ▀█▒
▒▓█    ▄	 ▒██░  ██▒	▓██    ▓██░ ▓██░ ██▓▒	▓██  ▒██░	▒ ▓██░ ▒░	▒███    ▓██ ░▄█ ▒ 	  ▓██  ▀█ ██	▒▒███  	▒ ▓██░ ▒░	 ▒█░ █ ░█ 	▒██░  ██▒	▓██ ░▄█ ▒	▓███▄░ 	▒██▒	▓██  ▀█ ██▒  ▒██░▄▄▄░
▒▓▓▄ ▄██	▒▒██   ██░	▒██    ▒██  ▒██▄█▓▒ ▒	▓▓█  ░██░	░ ▓██▓ ░ 	▒▓█  ▄  ▒██▀▀█▄   	  ▓██▒  ▐▌██	▒▒▓█  ▄	░ ▓██▓ ░ 	 ░█░ █ ░█ 	▒██   ██░	▒██▀▀█▄  	▓██ █▄ 	░██░	▓██▒  ▐▌██▒  ░▓█  ██▓
▒ ▓███▀ 	░░ ████▓▒░	▒██▒   ░██▒ ▒██▒ ░  ░	▒▒█████▓ 	  ▒██▒ ░ 	░▒████▒ ░██▓ ▒██▒ 	  ▒██░   ▓██	░░▒████	▒ ▒██▒ ░ 	 ░░██▒██▓ 	░ ████▓▒░	░██▓ ▒██▒	▒██▒ █▄	░██░	▒██░   ▓██░  ░▒▓███▀▒
░ ░▒ ▒  	░░ ▒░▒░▒░ 	░ ▒░   ░  ░ ▒▓▒░ ░  ░	░▒▓▒ ▒ ▒ 	  ▒ ░░   	░░ ▒░ ░ ░ ▒▓ ░▒▓░ 	  ░ ▒░   ▒ ▒	 ░░ ▒░ 	░ ▒ ░░   	 ░ ▓░▒ ▒  	░ ▒░▒░▒░ 	░ ▒▓ ░▒▓░	▒ ▒▒ ▓▒	░▓  	░ ▒░   ▒ ▒    ░▒   ▒ 
  ░  ▒  	   ░ ▒ ▒░ 	░  ░      ░ ░▒ ░     	░░▒░ ░ ░ 	    ░    	 ░ ░  ░   ░▒ ░ ▒░ 	  ░ ░░   ░ ▒	░ ░ ░  	░   ░    	   ▒ ░ ░  	  ░ ▒ ▒░ 	  ░▒ ░ ▒░	░ ░▒ ▒░	 ▒ ░	░ ░░   ░ ▒░    ░   ░ 
░       	 ░ ░ ░ ▒  	░      ░    ░░       	 ░░░ ░ ░ 	  ░      	   ░      ░░   ░  	     ░   ░ ░	    ░  	  ░      	   ░   ░  	░ ░ ░ ▒  	  ░░   ░ 	░ ░░ ░ 	 ▒ ░	   ░   ░ ░   ░ ░   ░ 
░ ░     	     ░ ░  	       ░             	   ░     	         	   ░  ░    ░      	           ░	    ░  	░        	     ░    	    ░ ░  	   ░     	░  ░   	 ░  	         ░         ░ 
░
NOTE: Extend the txt file or open it in full-screen to see it correctly :)   	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

+-----------------------------------------------+
|  Main Problems Explanation        		|
+-----------------------------------------------+
In this project, we faced problems from two main Topics: UDP and TCP programming.

UDP programming contained two different problems:
	Problem 1: Learn to use datagram sockets by example.
	Problem 2: Create a gateway process that simulates datagram loss.
	
TCP programming contained two parts; each part had a different problem:
	Part A: IP addresses, hostnames, and... HTTP
	Part B: A simple web client
	
<----------------------------------------------------------------------------------------->
	
+-----------------------------------------------+
|  Folder files - What Each Folder Contains     |
+-----------------------------------------------+
1) .c files: Uncompiled files with completed coding in each file.
	send_udp.c, resv_udp.c, sink.c, gateway.c, source.c, net_server.c, net_client.c, nslookup.c, http_client.c
	
2) Makefile: Can compile all the .c files above separately, which allows running the files, and also allows to get rid of objects and executable files.
	+----------------------+	
	| Makefile: HOW TO RUN |
	+----------------------+
	2.1) Open CMD/Terminal at the project folder (Where the Makefile is located).
	2.2.1) To compile the files: Type the Command 'Make all' (without the quotes).
	2.2.2) To get rid of the compiled files: Type the Command 'Make clean' (without the quotes).
	
3) "Problem 1: Learn to use Datagram sockets" folder: Contains the compiled .c files that are relevant to the UDP Programming - problem 1 and a screencast simulation of how to run the code.
	[recv_udp, send_udp, send+recv UDP.mov]

4) "Problem 2: Create a gateway process for datagram loss" folder: Contains the compiled .c files that are relevant to the UDP Programming - problem 2 and a screencast simulation of how to run the code.
	[sink, gateway, source, sink+gateway+source.mov]

5) "Part A: IP Addresses, Hostnames, and ... HTTP" folder: Contains the compiled .c files that are relevant to the TCP Programming - Part A, Original .c files that are relevant for the first section of the problem, TCPDUMP caption from Wireshark application, Makefile for the .c files, and screenshots folder that contains screenshots for each solution part of the given problem.
	[net_server, net_client, nslookup, org_net_server.c, org_net_client.c, org_nslookup.c, TCPDUMP.pcapng, Makefile, Screenshots]

6) "Part B: A simple Web Client" folder: Contains the compiled .c file that is relevant to the TCP Programming - Part B, an HTML file that was created via the Command: 'wget http://www.yahoo.com' (without the quotes), and a screenshot + screencast simulation of how to run the code.
	[http_client, index.html, http_client.png, HTTP vs HTTPS.mov]
	
<----------------------------------------------------------------------------------------->

+-----------------------------------------------+
|  Solution Explanation File         		|
+-----------------------------------------------+
In the project's main folder, there is a "Solution Explanation.pdf" file that handles every problem and explains its solution, as well as all the commands for how to run the .c files properly.
I suggest reading it.

<----------------------------------------------------------------------------------------->
<----------------------------------------------------------------------------------------->
