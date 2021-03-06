#include <stdio.h>
#include <stdlib.h>
#include <Winsock2.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	// socket
	SOCKET socket1;
	WSADATA wsadata;
	
	int ErrorCode;
	
	if(WSAStartup(MAKEWORD(2,1), &wsadata))
	{
		printf("Winsock initiate failed!");
		WSACleanup();
		return 0;
	}
	
	printf("Winsock client start ...\n");
	
	// 准备 
	const char* ip = "172.16.60.247";
	struct sockaddr_in server;
	int len = sizeof(server);

	server.sin_family = AF_INET;
	server.sin_port = htons(12345);
	server.sin_addr.s_addr = inet_addr(ip);	
	
	socket1 = socket(AF_INET, SOCK_STREAM, 0);
	
	if(connect(socket1, (SOCKADDR*)&server, sizeof(SOCKADDR)) == 0)
	{
		
		while(1){
			// 一收一发 无限循环
			char buffer[1024] = "\0";
			
			printf("input message:\n"); 
			scanf("%s", buffer);
			
			if(strcmp(buffer, "bye") == 0)
			{
				printf("exit, bye!!\n");
				Sleep(100);
				closesocket(socket1);
				break;
			}
			
			if(send(socket1, buffer, strlen(buffer)+1, 0) != SOCKET_ERROR)
			{
				printf("sending...\n");
				Sleep(100);
				if(recv(socket1, buffer, sizeof(buffer), 0) != SOCKET_ERROR)
				{
					printf("recevie from server: %s\n", buffer);
				}
			}
		}
	}

	closesocket(socket1);
	system("pause");
	
	return 0;
}
