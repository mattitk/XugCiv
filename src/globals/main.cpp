#include "main.h"
#include "../globals/structs.h"
#include "../globals/config.h"
#include "../globals/timer.h"
#include "../globals/parser.h"
#ifdef USE_NETWORK
	#include "../network/server.h"
	//#include "../network/client.h"
#endif
#ifdef USE_SDL
	#include "../sdl_ui/sdl_handler.h"
#endif
#ifdef USE_NCURSES
	#include "../console_ui/console_material.h"
	#include "../console_ui/console_ui.h"
	#include "../console_ui/console_window.h"
#endif
#include "../world/world.h"
#include "../ai/ai_includes.h"
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
Logger logger;
Timer timer;
SDL_Handler XUG_SDL;

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

int sdl_main_loop()
{
	int quit=0;
	while(!quit)
	{
		quit = XUG_SDL.Refresh();
		//ui.draw();
		//ui.render();
		//quit=ui.poll();
	}
	return quit;
}


int main(int argc, char **argv)
{
	int value=0;
	ConsoleWindow *ww = new ConsoleWindow();
//	w.LoadStyle("res/styles/basic.style");
	AI *ai = new Animal_AI();
if(MAIN_INTERFACE == 0)
{
	XUG_SDL.Init();
	XUG_SDL.Start();
	value=main_loop();
	XUG_SDL.DeInit();
}
else if(MAIN_INTERFACE == 1)
{
	ui.init();
	value=main_loop();
	ui.deinit();
}
	if(value == 1) return 1;
	delete(&ai);
	return 0;
}
