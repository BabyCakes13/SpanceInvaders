#include "alien.hpp"
#include "GLFW/glfw3.h"
#include <cstdio>

Alien::Alien() {
  _image = nullptr;
  loadImage();
}

int Alien::loadImage() {
  _image = SDL_LoadBMP("./images/red_alien.bmp");
  return 0;
}

SDL_Surface *Alien::image() {
  return _image;
}
