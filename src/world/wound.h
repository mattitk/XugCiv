#ifndef __WOUND_H__
#define __WOUND_H__

class Wound
{
private:
  int type;
  int damage;
public:
  void SetDamage(int damage)
  {
    this->damage = damage;
  }
  void SetType(int type)
  {
    this->type = type;
  }
};

#endif
