#ifndef __ALIEN_H_
#define __ALIEN_H_

#include <SDL2/SDL.h>
#include"drawable.hpp"

class Alien:public Drawable {
  private:
    SDL_Surface *_image;
    int x;
    int y;

  public:
    Alien();
    int loadImage();
    SDL_Surface *image();
};

#endif // __ALIEN_H_
