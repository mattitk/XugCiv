#ifndef __UNIT_H__
#define __UNIT_H__

#include <vector>
#include "../ai/ai.h"
#include "actor.h"
#include "item.h"

#include "wound.h"

class Unit : public Actor
{
  private:
    bool gender;
    bool pregnant;
    bool fertile;
    unsigned int age;
    unsigned short birthday;
    int race;
    //World *world;
    AI *ai;
    Actor *mount;
    //std::vector<Skill *> skills;
    unsigned int *eq_slots;
    unsigned int xp;
    int str;
    int dex;
    int spd;
    float carried_weight;
    unsigned int hunger;
    std::vector<Item*> inv;
    std::vector<Wound*> wounds;
    std::vector<Unit*> mounted_units;

  public:

    void ReserveMemory()
    {
      if(race == RACE_HUMAN) eq_slots = new unsigned int[16];
      else eq_slots = new unsigned int[1];
    }

    void FreeMemory()
    {
      delete(eq_slots);
    }

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
      ReserveMemory();
      FreeMemory();
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
