#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include "../globals/main.h"
#include <stdlib.h>
#include <string.h>
#include <vector>

#include "console_input.h"
#include "console_material.h"
#include "console_window.h"


class ConsoleUI
{
	public:
	int enabled;
	int xsize, ysize;

	char colors;

	int input_cursor;
	int input_max_size;
	char *input;
	void backspace();
	void get_input(char ch);

	int active_window = -1;

	char *buffer;
	char *colbuffer;
	WINDOW *mainwin;
	std::vector<ConsoleWindow*> win;
	ConsoleUI();
	~ConsoleUI();
	void SetBoundaries(int ysize, int xsize);
	int SetActiveWindow(int handle);
	int CreateConsoleWindow(std::string name, int x, int y, int xsize, int ysize);
	int poll();
	int render();
	int draw();
	int evaluate_input();
	int init();
};

#endif
