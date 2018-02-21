#ifndef __UNIT_H__
#define __UNIT_H__

#include <vector>
#include "../ai/ai.h"
#include "actor.h"
#include "item.h"

class Unit : public Actor
{
  private:
    int race;
    AI *ai;
    std::vector<Item*> inv;
    int eq_slots[16];

  public:
    bool PickUpItem(Item *i)
    {
      return false;
    }
};

#endif
