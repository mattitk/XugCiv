#ifndef __CONSOLE_BUTTON_H__
#define __CONSOLE_BUTTON_H__



class ConsoleButton
{
	public:
	signed int x,y;
	unsigned int xsize, ysize;
	char triggered;
	std::string text;
	int textcolor;
	int selectedcolor;
	int bgcolor;
	void *parent;
	
	void SetParent(void *p)
	{
		parent = p;
	}
	
	ConsoleButton()
	{
		x=0;
		y=0;
		xsize=1;
		ysize=1;
		triggered=0;
		bgcolor=CONSOLE_RED;
		textcolor=CONSOLE_WHITE;
		selectedcolor=CONSOLE_YELLOW;
	}
	 
};

#endif
