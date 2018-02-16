#ifndef __STRUCTS_H__
#define __STRUCTS_H__

typedef struct
{
	char style_name[256];
	int border_color;
        char left_up, left_down, right_up, right_down, horizontal, vertical;
        char shadow;
}ConsoleWindowStyle;

typedef struct
{
        int type;
        char name[256];
        int x,y;
        int xsize, ysize;
        float scale;
}WindowProperties;

typedef struct {
        char type;
        char key[256];
        char value[256];
        float floating_value;
        long int numerical_value;
}PropertyStruct;

#endif
