#include "server.h"
#include "../globals/log.h"

Server::Server()
{
	int j;
	max_conns=50;
	port=1235;

	Console = 0;
	
	for(j=0;j<max_conns;++j)clientSocket[j]=0;
	
	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	fcntl(serverSocket, F_SETFL, O_NONBLOCK);
	memset(&serverSocketAddress, 0, sizeof(serverSocketAddress));
	serverSocketAddress.sin_family = AF_INET;
	serverSocketAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverSocketAddress.sin_port = htons(port);
	
}

int Server::setActiveSocket(int s)
{
	activeSocket = s;
	return 0;
}

int Server::outpt(char *str){
        if(!(clientSocket[activeSocket]<0)&&str)
                {
                send(clientSocket[activeSocket], str,strlen(str),0);
                return 1;
                }
        return -1;
}

int Server::inpt(char *str){
        free(str);
        str=(char *)malloc(512);
        memset(str,0,512);
        if(recv(clientSocket[activeSocket],str,512,0)>0){
                return 1;
                }
        return -1;
}

char *Server::build_message(int type)
{
	static char msg[256];
	memset(msg,0,256);
	switch(type)
	{
		case DISCONNECT_MESSAGE:
			sprintf(msg, "%s", message_words[4].c_str());
			return msg;
		case DISCONNECT_WARNING_MESSAGE:
			sprintf(msg, "%s", message_words[3].c_str());
		case HANDSHAKE_MESSAGE:
			sprintf(msg, "%s", message_words[0].c_str());
			return msg;
		case GREETING_MESSAGE:
			sprintf(msg, "%s", message_words[1].c_str());
			return msg;
	};
	return msg;
}

void Server::disconnect(int socketNumber){
        outpt(build_message(DISCONNECT_MESSAGE));
        close(clientSocket[socketNumber]);
        return;

}

int Server::catchFreeSocket(){
        int j;
        for(j=0;j<max_conns;j++)
                if(!clientSocket[j])return j;
        return -1;
}

int Server::logConnection(int socket_number)
{
	return 0;
}

void Server::bind_console(Logger *c)
{
	Console = c;
}

void Server::init_message_words(char *filename)
{
	char msg[256];
	if(filename == NULL)
	{
		sprintf(msg,"+XUGSERVER+ %d", 1);
		message_words.push_back(msg);
		message_words.push_back("(disconnect)");
	}
}

int Server::start(){
        if(bind(serverSocket, (struct sockaddr *) &serverSocketAddress, sizeof(serverSocketAddress)) < 0)
                {
                return 0;
                }
        if(listen(serverSocket,max_conns) < 0)
        {
                return 0;
        }
        if(Console)Console->Log("server_start(): Right on man.. Ready to answer");
        return 1;
}

int Server::stop(){
        int j=0;
        for(j=0;j<max_conns;j++)
        if(clientSocket[j]){
                        disconnect(j);
                        }
        close(serverSocket);
	return 0;
}


int Server::poll(){
        int s,a;
	//int received=0;
        //static int old_received=0;
        s=accept(serverSocket,0,0);
        if(!(s<0)){
                if(!((a=catchFreeSocket()) < 0)){
                        logConnection(a);
			clientSocket[a]=s;
                        setActiveSocket(a);
                        outpt(build_message(GREETING_MESSAGE));
                        return 2;
                }
                else{
                	return 0;
		}
        }

        return 1;
}
