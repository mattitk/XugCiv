#ifndef __NATION_H__
#define __NATION_H__

struct NationRelationStruct
{
  int id;
  int formal_relations;
  int trust;
  int threat_level;
  int mutual_interests;
  int common_enemies;
};

struct Point {
  float x,y,z;
};

class Nation {
private:
  int id;
  std::vector<Unit *> citizens;
  std::vector<NationRelationStruct *> relations;
  std::vector<Point *> border;
};

#endif
