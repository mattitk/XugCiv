#ifndef __WEATHER_H__
#define __WEATHER_H__

#include "component.h"

#define WEATHER_CLEAR     0
#define WEATHER_FOGGY     1
#define WEATHER_CLOUDY    2
#define WEATHER_RAIN      3
#define WEATHER_STORM     4
#define WEATHER_HURRICANE 5

// a weather "vertex" in the weather heat map

class Weather : public Component
{
protected:
  int type;
  unsigned long cooldown;
  int cooldown_rate;
  float intensity;
  double x,y,z;

  void cooldown_function()
  {
    if(cooldown>0)
    {

      cooldown -= cooldown_rate;
    }
    else
    {
      enabled = false;
    }
  }
};

#endif
