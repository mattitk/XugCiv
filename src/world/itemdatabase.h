#ifndef __ITEM_DATABASE_H__
#define __ITEM_DATABASE_H__

#include "structs.h"
#include "defines.h"
#include "parser.h"

#include <vector>

class ItemDataBase {
public:
  std::vector<PropertyStruct *> items;
  int itemCount;
};

#endif
