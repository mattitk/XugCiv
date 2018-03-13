#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "actor.h"

class Component
{
protected:
  bool enabled;
  Actor *parent;
};

#endif
