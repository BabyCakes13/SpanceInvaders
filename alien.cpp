#include "alien.hpp"
#include "GLFW/glfw3.h"
#include <cstdio>

Alien::Alien(int x,int y) : x(x), y(y) {}

void Alien::errorCallback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

void Alien::setupWindow() {
  glfwSetErrorCallback(errorCallback);

  int *w, *p;
}
