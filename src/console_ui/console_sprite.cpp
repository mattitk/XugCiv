#include "console_sprite.h"

ConsoleSprite::ConsoleSprite()
{
	xsize=1;
	ysize=1;
	ch='@';
	buf=0;
	col=0;
	angle=0.0;
	size=1.0;
	x=0.0;
	y=0.0;
	z=0.0;
}

ConsoleSprite::~ConsoleSprite()
{
	if(buf)free(buf);
	if(col)free(col);
}

int ConsoleSprite::Load(std::string filename)
{
	return 0;
}

int ConsoleSprite::Save(std::string filename)
{
	return 0;
}

int ConsoleSprite::Rasterize(std::string filename)
{
	return 0;
}
