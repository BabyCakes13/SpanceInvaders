#include <SDL2/SDL_error.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include<iostream>
#include "window.hpp"
#include <SDL2/SDL.h>

Window::Window() {}

Window::ERROR_CODE Window::initialise() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialise the SDL2 library.\n" << SDL_GetError() << "\n";
        return FAILED_SDL2_INIT;
    }

    window = SDL_CreateWindow("SDL2 Window",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              1920, 1080,
                                      0);

    if(!window) {
        std::cout << "Failed to create window.\n" << SDL_GetError() << "\n";
        return FAILED_WINDOW;
    }


    windowSurface = SDL_GetWindowSurface(window);

    if(!windowSurface) {
        std::cout << "Failed to create window surface.\n" << SDL_GetError() << "\n";
        return FAILED_WINDOW_SURFACE;
    }

    return SUCCESS;
}

Window::ERROR_CODE Window::load(SDL_Surface *image) {
    loadImage(image);

    return SUCCESS;
}

void Window::run() {
    bool keepWindowOpen = true;
    while(keepWindowOpen) {

        SDL_Event event;
        while(SDL_PollEvent(&event) > 0) {
            EVENT_CODE eventCode = handleEvent(&event);
            if(eventCode == QUIT) {
                keepWindowOpen = false;
            }
        }

        SDL_UpdateWindowSurface(window);
    }
}

Window::EVENT_CODE Window::handleEvent(SDL_Event *event) {
    switch(event->type) {
        case SDL_QUIT:
            return QUIT;
            break;
        default:
            return CONTINUE;
            break;
    }
}

Window::ERROR_CODE Window::loadImage(SDL_Surface *image) {
    if(!image) {
        std::cout << "Failed to load image\n" << SDL_GetError() << "\n";
        return FAILED_IMAGE;
    }

    SDL_BlitSurface(image, NULL, windowSurface, NULL);

    return SUCCESS;
}
