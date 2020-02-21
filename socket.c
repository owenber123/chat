#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib")

int main(int argc, char *argv[])
{
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	char *message, server_reply[2000];
	int recv_size;

	printf("\r\n\r\n\r\n\r\n\r\nInitialising Winsock...\r\n");

	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code: %d",WSAGetLastError());
		return 1;
	}

	printf("Initialized.\r\n");


	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket: %d", WSAGetLastError());
	}

	printf("Socket Created\r\n");

	server.sin_addr.s_addr = inet_addr("74.125.235.20");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	if (connect(s, (struct sockaddr *)&server, sizeof(server)) <  0)
	{
		puts("Connection Error\r\n");
		return 1;
	}

	puts("Connected");

	// Send a message
	message = "GET / HTTP/1.1\r\n\r\n";
	if (send(s, message, strlen(message), 0) < 0)
	{
		puts("Send Failed\r\n");
		return 1;
	}

	puts("Message Sent\r\n");

	// Recieve Message
	if ((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR)
	{
		puts("Recieve Failed");
	}

	puts("Reply Recieved");

	server_reply[recv_size] = '\0';
	puts(server_reply);


	return 0;
	
}






















