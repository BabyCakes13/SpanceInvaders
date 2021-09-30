#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include "window.hpp"

int Window::setupWindowContext() {
    if(!glfwInit()) {
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(1920, 1080, "SPACE INVADERS", NULL, NULL);

    if(!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLenum err = glewInit();
    if(err != GLEW_OK) {
        fprintf(stderr, "Error initialising GLEW.\n");
        glfwTerminate();
        return -1;
    }
    return 0;
}

void  Window::setupWindow() {
    GLint glVersion[2] = {-1, -1};
    glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
    glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
    printf("Running OpenGL with version: %d.%d\n", glVersion[0], glVersion[1]);
}
