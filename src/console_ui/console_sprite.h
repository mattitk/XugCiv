#ifndef __CONSOLESPRITE_H__
#define __CONSOLESPRITE_H__

#include <stdlib.h>
#include <vector>
#include <string>

class ConsoleSprite
{
	public:
	float x,y,z;
	unsigned char angle;

	float size;

	int xsize;
	int ysize;

	char ch;
	char *buf;
	char *col;
	int Load(std::string filename);
	int Save(std::string filename);
	ConsoleSprite();
	~ConsoleSprite();
	int Rasterize(std::string filename);	
};

#endif
