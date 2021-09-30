#ifndef __ALIEN_H_
#define __ALIEN_H_

#include "GLFW/glfw3.h"

class Alien {
  private:
  int x;
  int y;

  public:
  Alien(int x, int y);
  static void errorCallback(int error, const char* description);
  void setupWindow();
};

#endif // __ALIEN_H_
