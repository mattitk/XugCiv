#include "client.h"

int Client::connect_to_port(std::string ipstring, int port)
{
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if(socketfd == -1) return 0;
	server.sin_addr.s_addr = inet_addr(ipstring.c_str());
	server.sin_family = AF_INET;
	server.sin_port = htons (port);
	
	if(connect(socketfd, (struct sockaddr *)&server, sizeof(server)) <0)
	{
		return 0;
	}
	return 1;
}

void Client::poll()
{
	if(recv(socketfd, server_reply, 2000, 0) <0)
	{
		printf("%s",server_reply);
	}
}

void Client::disconnect()
{
}

Client::Client()
{
	socketfd = -1;
	connected = 0;
}

Client::~Client()
{
	if(socketfd != -1) disconnect();
}
