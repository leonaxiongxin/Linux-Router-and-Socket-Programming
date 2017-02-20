#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <netinet/in.h> // sockaddr_in結構所需標頭檔
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int sockfd;
    int recfd;
    int length;
    char buf[BUFSIZE];
    struct sockaddr_in myaddr; //宣告一個sockaddr_in結構(註)
    struct sockaddr_in client_addr;

    /* create socket */
    if ((socket=socket(AF_INET,SOCK_STREAM,0))<0)
    {
    	perror("socket error");
    	return 0;
    }
    memset((char*)&myaddr,0,sizeof(myaddr));
    
    sockfd = socket(PF_INET, SOCK_STREAM, 0); 
    //參數1:IPV6 參數2:使用TCP 參數3:通訊協定，一般為0，表自動選擇
    /* initialize structure myaddr */
    // bzero(&myaddr, sizeof(myaddr)); 
    //將沒有用到的結構內容清空,才不會有執行錯誤的問題
    myaddr.sin_family = AF_INET; //PF為IPV6；AF為IPV4
    /* this line is different from client */
    myaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    myaddr.sin_port = htons(1234); //htons()將2048轉換成系統看得懂的東西
    /* Assign a port number to socket */
    if (bind(sockfd, (struct sockaddr*)&myaddr, sizeof(myaddr)<0))
    {
    	perror("bind failed");
    	return 0;
    }
    /* make it listen to socket with max 1 connections */
    if (listen(sockfd,1)<0)//第二個參數為server要限制的client端數量
    {
    	perror("listen error");
    	return 0;
    }
    length=sizeof(client_addr);
    printf("Server start !\n");

    /* infinity loop -- accepting connection from client forever */
    while(1) //無限迴圈,1為true
    {
    	if (recfd=accept(sockfd,(struct sockaddr*)&client_addr,&length))
    	{
    		perror("accept error");
    		return 0;
    	}
    	if (length=read(recfd,buf,BUFSIZE)<0)
    	{
    		perror("server read error");
    		return 0;
    	}
    	printf("Creat socket #%d from %s : %d\n",recfd,inet_ntoa(client_addr.sin_addr),htons(client_addr.sin_port) );
    	printf("receive: %s\n", &buf);
    	if ((write(recfd,buf,sizeof(buf)))<0)
    	{
    		perror("server write error");
    		return 0;
    	}
    	memset(buf,0,sizeof(buf));
    	close(recfd);
    	return 0;
    }
}
