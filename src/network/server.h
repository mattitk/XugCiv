#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <time.h>

#include "../globals/log.h"

#include <vector>
#include <string>

#define BUFFSIZE 32
#define greetingMessage "Hello"

#define HANDSHAKE_MESSAGE 0
#define DISCONNECT_MESSAGE 3
#define DISCONNECT_WARNING_MESSAGE 2
#define GREETING_MESSAGE 1
#define WORD_MAX_LENGTH 512

class Server
{
	public:
		Logger *Console;
		Server();
		void bind_console(Logger *c);
		int start();
                int stop();
		int logConnection(int socket_number);
                int poll();
                int catchFreeSocket();
                int loadConfig();
                int saveConfig();
                int setActiveSocket(int s);
                int getActivesocket();
                int inpt(char *str);
                int outpt(char* str);
                void disconnect(int socket_number);
                int port,max_conns,max_pending_conns;
                struct sockaddr_in serverSocketAddress, clientSocketAddress[];
                int serverSocket,clientSocket[512];
                int activeSocket;
		char *build_message(int type);
		void init_message_words(char *filename);
		std::vector<std::string> message_words;
};


