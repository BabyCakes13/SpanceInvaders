#ifndef __ALIEN_H_
#define __ALIEN_H_

#include <SDL2/SDL.h>
#include"drawable.hpp"

class Alien: public Drawable {
  public:
    Alien();
    Alien(int x, int y);
    void updatePosition(int x, int y);

  private:
    void _cropBackground();
};

#endif // __ALIEN_H_
