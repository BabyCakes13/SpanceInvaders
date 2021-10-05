#include "alien.hpp"
#include "GLFW/glfw3.h"
#include <SDL2/SDL_surface.h>
#include <cstdio>

Alien::Alien() : Alien(0, 0) {}

Alien::Alien(int x, int y) {
  _image = nullptr;
  _position.x = x;
  _position.x = y;
  _position.w = 120;
  _position.h = 100;

  _loadImage("./images/red_alien.bmp");
  _cropBackground(255, 255, 255);
}

void Alien::updatePosition(int x, int y) {
  _position.x = x;
  _position.y = y;
}

}
