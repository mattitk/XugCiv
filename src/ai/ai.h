#ifndef __AI_H__
#define __AI_H__

class AI
{
  protected:
    int type;
  public:
    virtual int Poll();
    virtual int Trigger();
};

#endif
