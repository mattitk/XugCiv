#ifndef __ANIMAL_AI_H__
#define __ANIMAL_AI_H__

#include <stdio.h>
#include "ai.h"

class Animal_AI : public AI
{
protected:
  unsigned int thirst;       // required amount to drink
  unsigned int hunger;       // required amount to eat
  unsigned int urine;        // required amount to urine
  unsigned int fecal_matter; // required amount to excrement

  int stress;
  int decision_cooldown;
  unsigned int decision_treshold;
  bool unexcpected = false;

  int protection_value;
  int hitpoints;

  // memory conservation
  unsigned int maxium_friends;

  // static world bindings
  Actor *host;
  std::vector<Actor *> friends;
//  Herd *herd;

  // dynamic
  std::vector<Actor *> nearby_actors;
public:
  Animal_AI()
  {
    decision_cooldown = 0;
    decision_treshold = 128;
  }

  void EvaluateSurroundings()
  {

  }

  int Poll()
  {
    if(decision_cooldown<=0 || unexcpected)
    {
      Act();
      unexcpected = false;
      decision_cooldown = decision_treshold;
    }
    else --decision_cooldown;
    return 0;
  }

  int Trigger()
  {
    unexcpected = true;
    return 0;
  }

  void Act()
  {
    printf("moo\n");
  }

};

#endif
