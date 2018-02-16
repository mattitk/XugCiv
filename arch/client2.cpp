#include "client.h"

int Client::connect_ipv4(char *hostname)
{
	if(connected)return 0;
	if(resolved<=0)get_ip(hostname);
	socketfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	connect(socketfd, res->ai_addr, res->ai_addrlen);	
	return 1;
}

int Client::get_ip(char *ip)
{
        if((status = getaddrinfo(ip, NULL, &hints, &res)) != 0) {
                fprintf(stderr, "getaddinfo %s\n", gai_strerror(status));
                return 0;
        }
	
        for(p = res; p != NULL; p = p->ai_next)
        {
                if(p->ai_family == AF_INET)
			{
                        struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
                        addr = &(ipv4->sin_addr);
                        memcpy(ipver, &"IPv4", 4);
                }else
                {
                        struct sockaddr_in6 *ipv6 = ( struct sockaddr_in6 *)p->ai_addr;
                        addr = &(ipv6->sin6_addr);
                        sprintf(ipver, "IPv6");
                }
        }
	resolved = 1;
        return 1;
}

Client::Client()
{
	resolved = 0;
	connected = 0;
	port = 1235;
        memset(&ipver,0,5);
        memset(&hints,0,sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
}

int Client::disconnect()
{
}

int Client::force_disconnect()
{
	connected = 0;
	
}

Client::~Client()
{
	if(connected)force_disconnect();
	freeaddrinfo(&hints);
}

