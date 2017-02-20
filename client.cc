#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int sockfd,length;
	char data[1024];
	char serverIP[15];
	char buf[BUFSIZ];
	struct sockaddr_in myaddr;
	struct sockaddr_in servaddr;

	if((sockfd = socket(AF_INET,SOCK_STREAM.0))<0){
		printf("socket error\n");
		return 0;
  }
	memset((char*)&myaddr,0,sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	myaddr.sin_port = htons(0);
	if (bind(sockfd,(struct sockaddr*)&myaddr,sizeof(myaddr))<0){
		printf("bind error\n");
		return 0;
	}
	memset((char*)&servaddr,0,sizeof(servaddr));
	printf("Enter Server IP:");
	scanf("%s",serverIP);
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(1234);
	servaddr.sin_addr.s_addr = inet_addr(serverIP);

	if (connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0){
		printf("connect failed !");
		return 0;
	}
	printf("Send Data : ");
	scanf("%s",data);
	if (write(sockfd,data,strlen(data))<0){
		printf("write error!\n");
		return 0;
	}
	printf("Receive Data : %s\n",buf );
	close(sockfd);
	return 0;
}
