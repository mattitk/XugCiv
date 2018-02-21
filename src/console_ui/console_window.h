#ifndef __CONSOLE_WINDOW_H__
#define __CONSOLE_WINDOW_H__

/*
 TODO: LOCATE MEMORY VIOLATION
*/

#include <vector>

#include "console_textfield.h"
#include "console_button.h"
#include "console_input.h"
#include "../globals/defines.h"
#include "../globals/structs.h"
#include "../globals/parser.h"

class ConsoleWindow
{
	public:
	int id;
	WindowProperties p;
	ConsoleWindowStyle *style;
	int active_element;
	char *background;

	std::vector<void*> elements;
	std::vector<unsigned int> input_handles;
	std::vector<unsigned int> button_handles;
	std::vector<unsigned int> text_handles;

	ConsoleWindow()
	{

		memset(p.name,0,255);
		sprintf(p.name, "My Window");
		p.x=5;
		p.y=5;
		p.xsize=35;
		p.ysize=7;
		p.scale=1;
	//	InitBackground();
	}

	void InitBackground()
	{
		if(background)free(background);
    background=(char *)malloc(p.xsize*p.ysize*sizeof(char)+1);
    memset(background, ' ', p.xsize*p.ysize);
	}

	~ConsoleWindow()
	{
		if(style)free(style);
		if(background)free(background);
	}

	void LoadStyle(std::string filename)
	{
		if(style)free(style);
		style=(ConsoleWindowStyle *)malloc(sizeof(ConsoleWindowStyle));
		std::vector<PropertyStruct *> values;
    LoadConfig(filename.c_str(), &values);
		for(unsigned int i=0;i<values.size();++i)
		{
			if(strcmp(values[i]->key, "style_name"))
			{
				memset(style->style_name, 0, 255);
				memcpy(&style->style_name, &values[i]->value, 10);
				printf("STYLE_NAME! \n %s\n",style->style_name);
			}
		}
	}

	void SetStyle(ConsoleWindowStyle *s)
	{
		if(style)free(style);
		style=s;
	}

	int SetBackground(char *buf)
	{
		if(buf)
		{
			background = buf;
			return 0;
		} else  return 1;
	}

	int SetProperties(WindowProperties *prop)
	{
		memcpy(&p.name, &prop->name, 255);
		return 0;
	}

	int AddInput(ConsoleInput *in)
	{
		elements.push_back((ConsoleInput *)in);
		input_handles.push_back(elements.size()-1);
		return 0;
	}

	int AddText(ConsoleTextField *in)
	{
		elements.push_back((ConsoleTextField *)in);
		text_handles.push_back(elements.size()-1);
		return 0;
	}

};

#endif
