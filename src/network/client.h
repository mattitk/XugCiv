#ifndef __CLIENT_H__
#define __CLIENT_H__

#ifdef LINUX
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#endif

#ifdef WINDOWS
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment (lib, "Ws2_32.lib");
#endif

#include <stdio.h>
#include <string.h>


#include <vector>
#include <string>

class Client
{
	public:
	Client();
	~Client();

	int send(char *buf);
	void *addr;
	int status;
	int port;
	int connected;
	int resolved;
	int socketfd;

	char ipver[5];
	struct addrinfo hints, *res, *p;
	struct sockaddr_in server;
	char server_reply[2000];

	void disconnect();
	int connect_ipv4(char *hostname);
	int get_ip(char *ip);
	void poll();
	int connect_to_port(std::string ipstring, int port);
};
#endif
