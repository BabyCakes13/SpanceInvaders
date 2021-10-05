#include "alien.hpp"
#include "GLFW/glfw3.h"
#include <SDL2/SDL_surface.h>
#include <cstdio>

Alien::Alien() : Alien(0, 0) {}

Alien::Alien(int x, int y) {
  _image = nullptr;
  _position.x = x;
  _position.x = y;
  _position.w = 10;
  _position.h = 10;

  loadImage("./images/red_alien.bmp");
  _cropBackground();
}

void Alien::updatePosition(int x, int y) {
  _position.x = x;
  _position.y = y;
}

void Alien::_cropBackground() {
  SDL_SetColorKey(_image, SDL_TRUE, SDL_MapRGB( _image->format, 255, 255, 255 ));
}
