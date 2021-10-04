#include "alien.hpp"
#include "GLFW/glfw3.h"
#include <cstdio>

Alien::Alien() : Alien(0, 0) {}

Alien::Alien(int x, int y) {
  _image = nullptr;
  _position.x = x;
  _position.x = y;
  _position.w = 10;
  _position.h = 10;

  loadImage("./images/red_alien.bmp");
}

void Alien::updatePosition(int x, int y) {
  _position.x = x;
  _position.y = y;
}
