#ifndef __CONSOLE_INPUT_H__
#define __CONSOLE_INPUT_H__

#include <memory.h>
#include <string>

class ConsoleInput
{
	char *buf;
	unsigned int cursor;
	unsigned int length;
	unsigned int copyPosition;
	void backspace()
	{
		if(--cursor<0)cursor=0;
		/*for(int j=length-1;j>cursor;--j)
		{
			input[j] = input[j+1]
		}*/
		copyPosition = cursor + 1;
		if(copyPosition<length)
		{
			memcpy(&buf[copyPosition], &buf[cursor], length-copyPosition);
			buf[length-1]=0;
		}
		else
		{
			buf[cursor] = 0;
		}
	}

	ConsoleInput(int size)
	{
		cursor=0;
		length=size;
		buf = (char *)malloc(length*sizeof(char));
	}
	
	std::string get_input(char ch)
	{
		static int escape = 0, enter = 0;
		switch(ch)
		{
			case 27:
				escape = 1;
				break;
			case 13:
				enter = 1;
				//std::string s(buf);
				break;
			default:
				if(ch>32){
					buf[cursor]=ch;
					if(++cursor >= length) cursor=length-1;
				}
				break;
		
		}

		if(escape) return "ESC";
		if(enter)
		{
			std::string s(buf);
			return s;
		}
		return NULL;
	}
};

#endif
