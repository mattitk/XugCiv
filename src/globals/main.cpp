#include "main.h"
#include "../globals/structs.h"
#include "../globals/timer.h"
#include "../globals/parser.h"
#include "../network/server.h"
//#include "../network/client.h"
#include "../console_ui/console_material.h"
#include "../console_ui/console_ui.h"
#include "../console_ui/console_window.h"
#include "../world/map.h"
#include "../ai/ai.h"
#include "../ai/animal_ai.h"
#include <chrono>
#include <thread>

int Server_Main()
{
	int quit=0, a =0;
	//Server server;
	//server.start();
	while(!quit)
	{
		//a = server.poll();
		if(a==2)quit=1;
	}
	//server.stop();
	return 1;
//	__int128 jee;
}

void Client_Main()
{
	//Client c;
	//c.connect_to_port("127.0.0.1",1235);
	//printf("Connected to socket %d", c.socketfd);
}

ConsoleUI ui;
Logger log;
Timer timer;
//Parser parser;
int main_loop()
{
	int quit=0;
	while(!quit)
	{
		refresh();
		ui.draw();
		ui.render();
		quit=ui.poll();
	}
	return quit;
}

int main(int argc, char **argv)
{
	int value=0;
	ConsoleWindow ww;
//	w.LoadStyle("res/styles/basic.style");

	std::vector<PropertyStruct *> values; // = new std::vector<PropertyStruct *>();
	if(LoadConfig("res/config.cfg", &values))
	{
		printf("Loading config failed. Going for defaults.\n");
	};
	for(unsigned int j=0;j<values.size();++j)
	{
		switch(values[j]->type)
		{
			case 's':
				printf("%s = \"%s\"\n", values[j]->key, values[j]->value);
				break;
			case 'i':
				printf("%s = %ld\n", values[j]->key, values[j]->numerical_value);
				break;
			case 'f':
				printf("%s = %f\n", values[j]->key, values[j]->floating_value);
		}
	}

	//ui.init();
	//value=main_loop();
	if(value == 1) return 1;
	return 0;
}
