#ifndef __SDL_HANDLER_H__
#define __SDL_HANDLER_H__

#include <SDL2/SDL.h>
//#include <SDL/SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "../globals/main.h"
#include "../globals/structs.h"
#include "../globals/parser.h"
#include "../sdl_ui/sprite.h"


class SDL_Handler
{
  private:
  std::vector<PropertyStruct *> spriteProperties;
  std::vector<PropertyStruct *> videoProperties;
  WindowProperties windowProperties;

  bool quit = false;
  int sdl_poll_retries = 8;
  SDL_Event e;
  SDL_Window *window[32];
  bool windowActive[32];
  int SDL_GFX_SYSTEM = 0;
  SDL_Surface *screenSurface;
  std::vector<SDL_Surface> sprite;

  public:

  int Refresh();

  bool LoadSprites()
  {

    LoadConfig("sprites.cfg", &spriteProperties);
      //INIT_SPRITES
    return true;
  }

  SDL_Handler()
  {
    Init();
  }
  ~SDL_Handler()
  {
    DeInit();
  }

  void FallBackToConsole()
  {
    printf("ALERT! Falling back to console .... in the future\n");
  }

  void CheckVideoProperties(std::vector<PropertyStruct*> pr)
  {
    for(unsigned int i=0;i<pr.size();++i)
    {
      if(pr[i]->type=='i')
      {
        if(strncmp(pr[i]->key, "SDL", 3))
        {
            if(pr[i]->numerical_value == 0)
            {
              FallBackToConsole();
            }

        }
      }
    }
  }

  void Init()
  {
    LoadConfig("video_config.cfg", &videoProperties);
    CheckVideoProperties(videoProperties);
    //LoadConfig("last_session.cfg", &recoveryProperties);
    SDL_Init(SDL_INIT_VIDEO);
  }



  void Start()
  {
    if(!window[0])
    {
        window[0] = (SDL_Window *)malloc(sizeof(SDL_Window*));
        window[0] =  SDL_CreateWindow(APPLICATION_NAME,
          windowProperties.x, windowProperties.y,
          windowProperties.xsize, windowProperties.ysize
        ,  SDL_WINDOW_SHOWN);
    }
  }

  void DeInit()
  {
    SDL_Quit();
  }
};

int SDL_Handler::Refresh()
{
  int event_main_type = 0;
  int counter = 0;
  while(counter++ < sdl_poll_retries || event_main_type)
  {
      event_main_type = SDL_PollEvent(&e);
  }
  switch(event_main_type)
  {
    case SDL_QUIT:
      quit = true;
      break;
  }
  if(windowActive[0] == true) SDL_UpdateWindowSurface(window[0]);
  if(windowActive[1] == true) SDL_UpdateWindowSurface(window[1]);
  if(windowActive[2] == true) SDL_UpdateWindowSurface(window[2]);
  if(windowActive[3] == true) SDL_UpdateWindowSurface(window[3]);
  if(windowActive[4] == true) SDL_UpdateWindowSurface(window[4]);
  if(windowActive[5] == true) SDL_UpdateWindowSurface(window[5]);
  if(windowActive[6] == true) SDL_UpdateWindowSurface(window[6]);
  if(windowActive[7] == true) SDL_UpdateWindowSurface(window[7]);
  if(windowActive[8] == true) SDL_UpdateWindowSurface(window[8]);
  if(windowActive[9] == true) SDL_UpdateWindowSurface(window[9]);
  if(windowActive[10] == true) SDL_UpdateWindowSurface(window[10]);
  if(quit == true) return 420;
  return 0;
}

#endif
