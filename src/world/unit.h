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
    Actor *mount;
    std::vector<Item*> inv;
    //std::vector<Skill *> skills;
    int eq_slots[16];
    int xp;
    int str;
    int dex;
    int spd;
    float carried_weight;

  public:
    Unit()
    {
      mount = 0;
      ai = 0;
      xp = 0;
      str = 1;
      dex = 1;
      spd = 1;
      carried_weight = 0.0;
      race = RACE_HUMAN;
    }

    void BindAi(AI *ai)
    {
      this->ai = ai;
    }

    void CalculateCarriedItemsWeight()
    {
      int new_carried_weight=0;
      for(unsigned int i=0;i<inv.size();++i)
      {
        new_carried_weight += inv[i]->weight;
      }
      carried_weight = new_carried_weight;
    }

    bool DropItem(unsigned int index)
    {
      if(index >= inv.size()) return false;
      Item *i = inv[index];
      i->carrier = 0;
      inv.erase(inv.begin() + index);
      CalculateCarriedItemsWeight();
      return true;
    }

    bool PickUpItem(Item *i)
    {
      CalculateCarriedItemsWeight();
      if(carried_weight + i->weight <= str*10)
      {
        i->carrier = this;
        inv.push_back(i);
        return true;
      }
      //UNITLOG ITEM TOO HEAVE
      return false;
    }
};

#endif
