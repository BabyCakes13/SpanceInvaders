#include <iostream>
#include "window.hpp"
#include "alien.hpp"

using namespace std;

int main() {

  Alien alien = Alien();

  Window window = Window();
  window.initialise();
  window.load(alien.image());
  window.run();

  return 0;
}
