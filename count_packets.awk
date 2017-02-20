BEGIN{
	packets=0;
	i=1;
}
{
	category = $2;
	size = $4;
	
	if( category == "Socket_i")
	{
		packet_size[i] = size;
		c[i] = category;
		i++;
		packets++;
	}
	else if( category == "Socket_o")
	{
		packet_size[i] = size;
		c[i] = category;
		i++;
		packets++;
	}
}
END{
	for(j=1;j<i;j++)
	{
		total_size = total_size + packet_size[j];
		if(c[j]=="Socket_i")
			printf("Input Packet size %d = %d\n",j,packet_size[j]);
		if(c[j]=="Socket_o")
			printf("Output Packet size %d = %d\n",j,packet_size[j]);
	}
	
	printf("Total packets = %d\n",packets);
	printf("Total packet size = %d\n",total_size);
}
