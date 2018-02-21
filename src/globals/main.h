#ifndef __MAIN_H__
#define __MAIN_H__

#include "defines.h"

#ifdef USE_NCURSES
#ifdef LINUX
#include <ncurses.h>
#endif
#ifdef WINDOWS
#include <curses.h>
#endif
#endif

#endif
