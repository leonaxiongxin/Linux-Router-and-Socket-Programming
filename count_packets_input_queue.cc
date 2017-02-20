int count(struct sk_buff* skb)
{
	struct iphdr *iph; //IP header
	struct tcphdr *tcph; //TCP header
	struct udphdr *udph; //UDP header
	struct timeval tv; //time struct(second & micro second)
	static int totalpacket=0;
	do_gettimeofday(&tv); //get now time
	_kernel_seconds_t intime=(tv.tv_sec*1000000)+tv.tv_usec; // intime = micro second
	iph = ip_hdr(skb); //get IP header

	if(iph->protocal==6){ //TCP packet
		tcph=(struct tcphdr *)((char *)iph+(iph->ihl*4));
		if(ntohs(tcph->source) == 8888) // TCP header, port number = 8888(change to your port number)
		{
			totalpacket++;
			printk("Socket_i\t%ld\t%d\t%d\n",intime,ntohs(iph-> tot_len),totalpacket); // time, total length, total packet
		}
		
		
	}
	return 0;
}
