#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

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
	char ipstr[INET6_ADDRSTRLEN];
	int force_disconnect();
	int disconnect();
	int connect_ipv4(char *hostname);
	int get_ip(char *ip);
};

#endif
