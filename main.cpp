#include <iostream>
#include<vector>
#include "application.hpp"
#include "alien.hpp"

using namespace std;

int main() {

  Application app = Application();

  std::vector<Alien> aliens (1);

  for(auto &a : aliens){
    app.addDrawable(&a);
  }

  app.run();

  return 0;
}
