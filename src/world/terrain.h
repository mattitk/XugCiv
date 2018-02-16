#ifndef __TERRAIN_H__
#define __TERRAIN_H__

class Terrain
{
	public:
	char *bitmap;
	char *heightmap;
	char *normalmap;
	std::vector<Prop> prop;
	int xsize, ysize;

};


#endif
