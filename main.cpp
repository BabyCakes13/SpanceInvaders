#include <GLFW/glfw3.h>
#include <iostream>
#include "alien.hpp"
#include "window.hpp"
#include "buffer.hpp"

using namespace std;

int main(int argc, char *argv[]) {

  Alien a = Alien(1, 2);
  Window window = Window();
  window.setupWindow();

  return 0;
}
