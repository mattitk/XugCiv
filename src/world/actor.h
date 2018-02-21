#ifndef __ACTOR_H__
#define __ACTOR_H__

class Actor
{
	protected:
		float lat, lon;
		int sector;
		int x,y;
		Actor *parent;
};

#endif
