#ifndef __ITEM_H__
#define __ITEM_H__

class Item : public Actor
{
public:
  Actor *carrier;
  std::string name = "Generic Item";
  float weight;
  Item()
  {
    carrier = 0;
  }
};

#endif
