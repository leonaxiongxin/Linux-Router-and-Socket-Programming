 Linux-Router-and-Socket-Programming

1. (10%) As shown in the above figure, set up a 2-port Linux PC Router first and then install Linux open source VoIP (Asterisk) and video streaming server (Darwin) on PC1 and PC2. Use microphones and MPEG-4 clips to examine whether you have installed Asterisk and Darwin successfully.        
Note: you need two Ethernet cards and two crossover UTP cables to form a router network.

2. (40%) Write down client/server programs by using TCP socket. Your client/server programs must work with Asterisk and Darwin and it must allow two users to send and receive English/Chinese text messages to each other. 

3. (50%) Performance measurements:  
NOTE: Three streams (Asterisk, Darwin, and client/server) must be transmitted simultaneously.  
I. On Linux router:       
 (1) (20%) Write down a backdoor program on router to measure the average packet forwarding delay for Darwin video streaming. The packet forwarding delay is defined from the time when sk_buff is constructed for the packet till the time when the packet is             removed from sk_buff.     
II. On PC-1/PC-2:.       
 (2) (20%) Write down a backdoor program on PC-1/PC-2 to measure average throughput for Asterisk and Darwin, respectively. Compare their differences.     
 (3) (10%) Intercept only client/server and count how many IP packets generated for different sizes of text messages (e.g., 10, 50, 100 English/Chinese words).
