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


class SDL_Handler
{
  private:
  std::vector<PropertyStruct *> spriteProperties;
  std::vector<PropertyStruct *> videoProperties;
  WindowProperties windowProperties;
  SDL_Window *window;
  SDL_Surface *screenSurface;
  std::vector<SDL_Surface> sprite;

  public:

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
  void Init()
  {
    LoadConfig("video_config.cfg", &videoProperties );
    SDL_Init(SDL_INIT_VIDEO);
  }

  void Start()
  {
    if(!window)
    {
        window =  SDL_CreateWindow(APPLICATION_NAME,
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

#endif
