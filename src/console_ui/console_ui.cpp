#include "console_ui.h"

int ConsoleUI::deinit()
{
	if(buffer)free(buffer);

	if(colbuffer)free(colbuffer);
	//WINDOW *mainwin;
	//std::vector<ConsoleWindow*> win;
	return 0;
}

ConsoleUI::ConsoleUI()
{
	enabled = false;
}

int ConsoleUI::init()
{
	if((mainwin = initscr()) == NULL)
	{
		enabled = false;
		return 1;
	}
	enabled = true;
	//raw();
	noecho();
	getmaxyx(mainwin, ysize, xsize);
	//input_max_size = 10;
	//if(xsize>10)input_max_size=xsize-3;
	//input_cursor=0;
	//input=(char*) malloc(input_max_size*sizeof(char));

	active_window = -1;

	buffer = (char*) malloc(xsize*ysize*sizeof(char));
	colbuffer = (char*) malloc(xsize*ysize*sizeof(char));

	keypad(mainwin, TRUE);
	//cbreak();
	timeout(0);
	if(has_colors() == false) colors = false;
	else colors = true;

	if(colors)
	{
		start_color();
		for(int fg=0;fg<8;++fg)
		for(int bg=0;bg<8;++bg)
			init_pair(bg*8+fg, fg, bg);
	}

	return 0;
}

ConsoleUI::~ConsoleUI()
{
	endwin();
}

int ConsoleUI::SetActiveWindow(int handle)
{
	if((signed int)win.size() > handle)
	{
		active_window = handle;
	}
	return 0;
}

int ConsoleUI::CreateConsoleWindow(std::string name = "Default", int x=0, int y=0, int xsize = 32, int ysize = 10)
{
	ConsoleWindow *w = new ConsoleWindow();
	if(!w) return 1;
	win.push_back(w);
	return 0;
}

int ConsoleUI::draw()
{
	int x,y, a;
	char backgroundchars[]="  '. , `                 ";
	int backgroundchars_length=strlen(backgroundchars);

	for(y=0;y<ysize;++y)
	for(x=0;x<xsize;++x)
	{
		a = rand()%backgroundchars_length;
		buffer[y*xsize+x] = backgroundchars[a];
		colbuffer[y*xsize+x] = 3;
	}

	//sprintf(buffer,"> %s", input);

	return 0;
}

int ConsoleUI::render()
{
	int x,y;
	int oldColor=0;
	if(colors)attron(oldColor);
	for(y=0;y<ysize;++y)
	for(x=0;x<xsize;++x)
	{
		move(y,x);
		if(colbuffer[y*xsize+x]!=oldColor && colors)
		{
			attroff(COLOR_PAIR(oldColor));
			attron(COLOR_PAIR(colbuffer[y*xsize+x]));
			oldColor=colbuffer[y*xsize+x];
		}
		printw(&buffer[y*xsize+x]);
	}
	return 0;
}

int ConsoleUI::evaluate_input()
{
	//int size = input_cursor;
	if(strcmp(input, "moi")) return 1;
	return 0;
}

void ConsoleUI::get_input(char ch)
{
	if(ch<32)return;
	if(input_cursor>input_max_size-1)return;
	input[input_cursor]=ch;
	if(++input_cursor > input_max_size) input_cursor = input_max_size;
}

void ConsoleUI::backspace()
{

	if(--input_cursor<0)input_cursor=0;
	input[input_cursor]=' ';

}

int ConsoleUI::poll()
{
	char ch = getch();
	switch(ch)
	{
		case 13:
			return evaluate_input();
			break;
		case (char)KEY_BACKSPACE:
			backspace();
			break;
		default:
			get_input(ch);
			break;
	}
	return 0;
}
