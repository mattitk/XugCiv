#ifndef __CITY_H__
#define __CITY_H__

#include "actor.h"
#include "prop.h"
#include "item.h"
#include "unit.h"
#include "building.h"

class City
{
	public:

	float lat, lon;
	std::vector<Building*> building;
	std::vector<Actor*> citizen;
	std::vector<Prop*> props;
	char *bitmap;
	int bitmap_xsize;
	int bitmap_ysize;
};

#endif
