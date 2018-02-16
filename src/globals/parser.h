#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>

#include <memory.h>

#include "defines.h"
#include "structs.h"

static int LoadConfig(std::string filename, std::vector<PropertyStruct *> *properties)
{
	FILE *f = fopen(filename.c_str(), "r");
	int eof=0, escape=0, state=0, string =0;
	char ch;
	char type='i';
	int bufCursor=0;
	char buf[256];
	PropertyStruct *p;
	char keyBuf[256];
	memset(&buf,0,255); memset(&keyBuf,0,255);
	
		
	if(!f) return 0;
  	
	while(!eof)
	{ 
  	ch = fgetc(f);
		switch(ch)
		{
			case EOF:
				eof =1;
				break;
			case '\n':
      				if(state>0)
				{
					p = (PropertyStruct *)malloc(sizeof(PropertyStruct));
					memcpy(&p->key, &keyBuf, 255);
					memcpy(&p->value, &buf, 255);

					switch(type)
					{
						case 'i':
							p->numerical_value = atoi(buf);
							break;
						case 'f':
							p->floating_value = atof(buf);
							break;
					}
					p->type=type;
         				properties->push_back(p);
				}
				state=0;
				type='i';
				memset(&buf,0,255);
				bufCursor=0;
			case '\\':
				if(escape == 0)
				{
					escape = 2;
					break;
        			}
			case '=':
				if(state == 0 && !escape)
				{
					memcpy(&keyBuf, &buf, 255);
					bufCursor=0;
					memset(&buf,0,255);
					state = 1;
					break;
				}
			case '\"':
				if(!escape)
				{
					if(string == 0)
					{
						string = 1;
						type='s';
					}
					else string = 0;
				break;
				}
			case '.':
				if(state>0 && string == 0 && !escape)
				{
					type = 'f';
				}
			default:
				if( escape> 0 ) --escape;
				buf[bufCursor]= ch;
				if( ++bufCursor > 255 ) state++;
				break;
		} //switch

	} //while
	return 0;
} //function


#endif
