#ifndef __LOG_H__
#define __LOG_H__

#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>

#include "../globals/defines.h"

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

	void FlushLogToFile(char *filename)
	{
		FILE *f = fopen(filename, "r");
		char logtext[1025];
		memset(logtext, 0, 1024);
		fprintf(f,"+_ %s log", APPLICATION_NAME);

		for(unsigned int i=0;i<field.size();++i)
		{
			//" %llu, (%d), [%d], \"%s\"\n",i , field[i]->timeStamp, field[i]->type, field[i]->value, field[i]->buffer.c_str());
			switch(field[i]->type)
			{
				case LOG_ENTRY_TEXT:
					sprintf(logtext, "%d: %s\n", i, field[i]->buffer.c_str());
					break;
				case LOG_ENTRY_NUMBER_WITH_TEXT:
					sprintf(logtext, "%d: %s -> %ld" ,i, field[i]->buffer.c_str(), field[i]->value);
					break;
			}
			fprintf(f,"%s", logtext);
			memset(logtext,0,1024);
		}
		fprintf(f, "+_ %s log terminated", APPLICATION_NAME);
		fclose(f);
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
