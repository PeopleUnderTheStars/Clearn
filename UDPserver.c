/*************************************************************************  
File Name:	server.c
Author:		Joey
Date		2015-7-1

*************************************************************************/ 

#include<sys/types.h>  
#include<sys/socket.h>  
#include<unistd.h>  
#include<netinet/in.h>  
#include<arpa/inet.h>  
#include<stdio.h>  
#include<stdlib.h>  
#include<errno.h>  
#include<netdb.h>  
#include<stdarg.h>  
#include<string.h>  

#define SERVER_PORT 8000  
#define BUFFER_SIZE 1024  

#define TRUE_SN "012345678901"
#define CMP_NUM 12

int main()  
{  
	/* 创建UDP套接口 */ 
	struct sockaddr_in server_addr;  
	bzero(&server_addr, sizeof(server_addr));  
	server_addr.sin_family = AF_INET;  
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);  
	server_addr.sin_port = htons(SERVER_PORT);  
	
	char *result;

	/* 创建socket */ 
	int server_socket_fd = socket(AF_INET, SOCK_DGRAM, 0);  
	if(server_socket_fd == -1)  
	{  
		perror("Create Socket Failed:");  
		exit(1);  
	}  

	/* 绑定套接口 */ 
	if(-1 == (bind(server_socket_fd,(struct sockaddr*)&server_addr,sizeof(server_addr))))  
	{  
		perror("Server Bind Failed:");  
		exit(1);  
	}  

	/* 数据传输 */ 
	while(1)  
	{   
		/* 定义一个地址，用于捕获客户端地址 */ 
		struct sockaddr_in client_addr;  
		socklen_t client_addr_length = sizeof(client_addr);  

		/* 接收数据 */ 
		char buffer[BUFFER_SIZE];  
		bzero(buffer, BUFFER_SIZE);  
		if(recvfrom(server_socket_fd, buffer, BUFFER_SIZE,0,(struct sockaddr*)&client_addr, &client_addr_length) == -1)  
		{  
			perror("Receive Data Failed:");  
			exit(1);  
		}  
		printf("%s\n", buffer);  

		/* 判断客户端SN码的正确性 */ 
		if(strncmp(TRUE_SN, buffer, CMP_NUM))
			result = "error";
		else
			result = "right";
		sendto(server_socket_fd, result, strlen(result),0,(struct sockaddr*)&client_addr, client_addr_length);
		printf("%s\n", result);  

	}  
	close(server_socket_fd);  
	return 0;  
}
