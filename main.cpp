#include <iostream>
#include "application.hpp"
#include "alien.hpp"

using namespace std;

int main() {

  Alien alien = Alien();
  Application app = Application();

  app.load(alien.image());
  app.update();
  app.draw();

  return 0;
}
