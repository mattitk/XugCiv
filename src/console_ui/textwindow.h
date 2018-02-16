#ifndef __TEXTWINDOW_H__
#define __TEXTWINDOW_H__

class TextWindow
{
	public:
		std::vector<void *> element;
		int x,y;
		int xsize, ysize;
		char name[256];
		char *buffer;
		char *colbuffer;
		
};

#endif
