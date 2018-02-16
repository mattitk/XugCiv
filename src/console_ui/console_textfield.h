#ifndef __CONSOLE_TEXTFIELD_H__
#define __CONSOLE_TEXTFIELD_H__

#include <chrono>
#include <string>


class ConsoleTextField
{
	public:
	char *buf;
	int x,y;
	unsigned int xsize, ysize;
	void *parent;
	
	void SetParent(void *p)
	{
		parent = p;
	}

	std::vector<std::string> lines;
};

#endif
