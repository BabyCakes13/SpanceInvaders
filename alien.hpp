#ifndef __ALIEN_H_
#define __ALIEN_H_

#include <SDL2/SDL.h>
#include"drawable.hpp"

class Alien: public Drawable {
  public:
    Alien();
    Alien(int x, int y);

    void calculatePosition();
};

#endif // __ALIEN_H_
