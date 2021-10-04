#include <iostream>
#include "application.hpp"
#include "alien.hpp"

using namespace std;

int main() {

  Alien alien;
  Application app = Application();
  app.addDrawables(&alien);
  app.run();

  return 0;
}
