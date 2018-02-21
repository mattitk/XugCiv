#ifndef __SPRITE_H__
#define __SPRITE_H__

class Sprite
{
public:
  float x,y;
  float rot;
  SDL_Surface *bitmap;

public:
  Sprite(char *filename)
  {
    if(bitmap)SDL_FreeSurface(bitmap);
    bitmap = SDL_LoadBMP(filename);
    if(!bitmap) bitmap = 0;
    x=0;
    y=0;
    rot=0;
  }
  ~Sprite()
  {
    if(bitmap)SDL_FreeSurface(bitmap);
  }
  void SetXY(float x, float y)
  {
    this->x = x; this->y = y;
  }
  void SetRot(float rot)
  {
    this->rot = rot;
  }
  void Rotate(float delta)
  {
    this->rot += delta;
  }
  void Translate(float delta_x, float delta_y)
  {
    this->x += delta_x; this->y += delta_y;
  }

};

#endif
