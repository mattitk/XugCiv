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
	//ConsoleWindow *ww = new ConsoleWindow();
//	w.LoadStyle("res/styles/basic.style");
	AI *ai = new Animal_AI();

	//The window we'll be rendering to
 SDL_Window* window = NULL;

 //The surface contained by the window
 SDL_Surface* screenSurface = NULL;

 //Initialize SDL
 if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
 {
		 printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
 }
 else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
				else
{
		//Get window surface
		screenSurface = SDL_GetWindowSurface( window );

		//Fill the surface white
		SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

		//Update the surface
		SDL_UpdateWindowSurface( window );

		//Wait two seconds
		SDL_Delay( 2000 );
}
}
//Destroy window
SDL_DestroyWindow( window );

//Quit SDL subsystems
SDL_Quit();

return 0;

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
