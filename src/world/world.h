#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>

#include "actor.h"
#include "building.h"
#include "item.h"
#include "prop.h"
#include "terrain.h"
#include "weather.h"
#include "map.h"
#include "unit.h"
#include "nation.h"
class World
{
private:
  Map *worldMap;
  std::vector<Weather *> weather;
  std::vector<Actor *> actors;
  std::vector<Unit *> units;
  std::vector<Item *> items;
  std::vector<Prop *> props;
  std::vector<Building *> buildings;

};
#endif
