#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "city.h"
#include "unit.h"
#include "terrain.h"
#include "weather.h"

class Map
{
	public:
		std::vector<Terrain> terrain;
		std::vector<Weather> weather;
		std::vector<City*> city;
		std::vector<Unit*> unit;

		std::vector<int> cubeMapIndex[6];
		int subdivisions;
		int sectorCount;
		int totalSectorCount;
		float radius;

};

#endif
