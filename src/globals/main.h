#ifndef __MAIN_H__
#define __MAIN_H__

#include "defines.h"

#define MAIN_INTERFACE 0

// 0 sdl
// 1 curses

#ifdef USE_NCURSES
  #ifdef LINUX
  #include <ncurses.h>
  #endif
  #ifdef WINDOWS
  #include <curses.h>
  #endif
#endif

#ifdef USE_SDL
  #ifdef LINUX
  #include <SDL2/SDL.h>
  #endif
  #ifdef WINDOWS
  #include <SDL/SDL.h>
  #endif
#endif


#endif
