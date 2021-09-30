#ifndef WINDOW_H_
#define WINDOW_H_

#include <GLFW/glfw3.h>

class Window {
    public:
        enum ERROR_CODE {SUCCESS=0, FAILED_GLEW_INIT, FAILED_TERMINATE, FAILED_GLFW_INIT, FAILED_SETUP_WINDOW_CONTEXT};
        ERROR_CODE setupWindow();

    private:
        GLFWwindow *window;
        ERROR_CODE setupWindowContext();
};

#endif // WINDOW_H_
