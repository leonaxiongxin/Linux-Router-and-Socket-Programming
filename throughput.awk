BEGIN{
	i=1;	
	j=1;
	a=1:
	b=1;
}
{
	category = $2;
	t_length = $3;
	time = $4;
	
	if( category == "Darwin")
	{
		length_d[i] = t_length*8;
		time_d[i] = time;
		i++;
	}
	else if( category == "Asterisk")
	{
		length_a[j] = t_length*8;
		time_a[j] = time;
		j++;
	}
}

END{
	for(x=1;x<i;x++)
	{
		total_length = total_length + length_d[x];
		total_length_d = total_length;
	}
	
	for(y=1;y<i;y++)
	{
		total_length = total_length + length_a[y];
		total_length_a = total_length;
	}

	packet_time_d = time_d[i-1]-time_d[1];
	packet_time_a = time_a[j-1]-time_a[1];
	avg_throughput_d = total_length_d / packet_time_d *1000;
	avg_throughput_a = total_length_a / packet_time_a *1000;
	printf("%d KB last %d first %d total %d\n",total_length_d/8/1000,time_d[i-1],time_d[1],packet_time_d);
	printf("Darwin throughput = %f Kbps\n",avg_throughput_d);
	printf("Darwin throughput = %f KBps\n",avg_throughput_d/8);
	printf("Asterisk throughput = %f Kbps\n",avg_throughput_a);
}
