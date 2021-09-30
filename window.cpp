#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include "window.hpp"

Window::ERROR_CODE Window::setupWindowContext() {
    if(!glfwInit()) {
        return FAILED_GLFW_INIT;
    }

    window = glfwCreateWindow(1920, 1080, "SPACE INVADERS", NULL, NULL);

    if(!window) {
        glfwTerminate();
        return FAILED_TERMINATE;
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
        return FAILED_GLEW_INIT;
    }
    return SUCCESS;
}

Window::ERROR_CODE  Window::setupWindow() {
    if(setupWindowContext() != SUCCESS) {
        return FAILED_SETUP_WINDOW_CONTEXT;
    }

    GLint glVersion[2] = {-1, -1};
    glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
    glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
    printf("Running OpenGL with version: %d.%d\n", glVersion[0], glVersion[1]);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return SUCCESS;
}
