#ifndef WINDOW_H_
#define WINDOW_H_

#include <GLFW/glfw3.h>

class Window {
    GLFWwindow *window;

    public:
        void setupWindow();
        int setupWindowContext();
};

#endif // WINDOW_H_
