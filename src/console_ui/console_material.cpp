#include "console_material.h"

#define ESCAPE_CHAR \\

ConsoleMaterial::ConsoleMaterial()
{
	name = "Default Material";
	type = 0;
}

void ConsoleMaterial::SetType(int type)
{
	this->type = type;
}

void ConsoleMaterial::ListProperties()
{
	for(unsigned int j=0;j<properties.size();++j)
	{
		printf("%s = ", properties[j]->key);
		switch(properties[j]->type)
		{
			case 's':
				printf("%s\n", properties[j]->value);
				break;
			case 'i':
				printf("%ld\n", properties[j]->numerical_value);
				break;
			case 'f':
				printf("%f\n", properties[j]->floating_value);
				break;
			default:
				printf("(type = null)\n");
				break;
		}
	}
}

int ConsoleMaterial::Load(std::string filename)
{
	FILE *f = fopen(filename.c_str(), "r");
	int eof=0, escape=0, state=0, string =0;
	char ch;
	char type='i';
	int bufCursor=0;
	char buf[256];
	PropertyStruct *p;
	char keyBuf[256];
	memset(&buf,0,255);
	memset(&keyBuf,0,255);
	if(!f) return 1;

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
					properties.push_back(p);
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
			default:
				if(escape>0)--escape;
				buf[bufCursor]=ch;
				if(++bufCursor>255) state++;
				break;
				
		}
	
	}
	return 0;
	
}
