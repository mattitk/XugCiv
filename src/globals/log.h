#ifndef __LOG_H__
#define __LOG_H__

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>

class LogField
{
	public:
	char type;
	clock_t timeStamp;
	long int value;
	unsigned long int bufferLength;
	std::string buffer;
};

class Logger
{
	private:
	static int verbose;
	std::vector<LogField *> field;

	public:
	void set_verbose(int v){
		verbose=v;
	}
	std::string getLogText(unsigned int index){
		if(index<field.size())return field[index]->buffer;
	}
	long int getLogValue(unsigned int index)
	{
		if(index<field.size())return field[index]->value;
	}
	int Log(std::string text, long int value = 0, char type = 0)
	{
		LogField *f = new LogField;
		f->buffer = text;
		f->value = value;
		f->timeStamp = clock();
		f->type = type;
		field.push_back(f);
/*
		LogField f;
		int txtLength = strlen(text);
		f.buffer=(char*)malloc(txtLength*sizeof(char));
		memcpy(text, f.buffer, txtLength);
		f.type = type;
		f.value = value;
		field.push_back(f);
		free(f.buffer);
		return field.size();
		*/
		return 0;
	}
};

#endif
