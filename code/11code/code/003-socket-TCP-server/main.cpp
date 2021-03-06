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
	
	printf("Winsock start ...\n");
	
	// 准备 
	const char* ip = "172.16.60.247";
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(12345);
	local.sin_addr.s_addr = inet_addr(ip);
	
	struct sockaddr_in client;
	int len = sizeof(client);
	
	socket1 = socket(AF_INET, SOCK_STREAM, 0);
	//bind
	bind(socket1, (struct sockaddr*)&local, sizeof(local));
	
	while(1){
		// 一收一发 无限循环
		char buffer[1024] = "\0";
		
		printf("waiting for message from the client...\n"); 

		if(listen(socket1, 10) != SOCKET_ERROR)
		{
			SOCKADDR_IN clientAddr;
			int len1 = sizeof(SOCKADDR);
			
			SOCKET connSocket = accept(socket1, (SOCKADDR*)&clientAddr, &len1);
			if(connSocket == INVALID_SOCKET)
			{
				printf("accept failed!");
				return -1;
			}
			
			while(1)
			{
				char recvBuf[100];
				if(recv(connSocket, recvBuf, sizeof(recvBuf), 0) != SOCKET_ERROR)
				{
					printf("recevie message: [%s] --- %s\n", inet_ntoa(clientAddr.sin_addr), recvBuf);
					send(connSocket, recvBuf, strlen(recvBuf)+1, 0);
				} 

			}
			
			closesocket(connSocket);
		}
		
	}

	closesocket(socket1);
	system("pause");
	
	return 0;
}
