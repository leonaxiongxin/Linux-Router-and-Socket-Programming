BEGIN{
	j=1;
	total = 0;
	total_time = 0;
	delay_time = 0;
	avg_delay_time = 0;
}
{
	IO = $2;
	time = $3;
	seq = $4;
	if( IO == "Input")
	{
		in_seq[j]=seq;
		input[seq]=time;
		j++;
	}
	if( IO == "Output")
	{
		output[seq]=time;
	}
}
END{
	for(i=in_seq[1];i<in_seq[j-1];i++)
	{
		delay_time=output[i]-input[i];
		total_time=total_time + delay_time;
	}
	avg_delay_time = total_time / j;
	printf("Average delay_time = %f us\n",delay_time);
}
