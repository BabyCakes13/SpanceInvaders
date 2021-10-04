#include "application.hpp"

#include<iostream>

Application::Application() {
    initialise();
}

Application::~Application() {
    SDL_FreeSurface(_mainWindowSurface);
    SDL_DestroyWindow(_mainWindow);
}

Application::ERROR_CODE Application::initialise() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Failed to initialise the SDL2 library.\n" << SDL_GetError() << "\n";
        return FAILED_SDL2_INIT;
    }

    _mainWindow = SDL_CreateWindow("SDL2 Window",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              1920, 1080,
                                      0);

    if(!_mainWindow) {
        std::cout << "Failed to create window.\n" << SDL_GetError() << "\n";
        return FAILED_WINDOW;
    }


    _mainWindowSurface = SDL_GetWindowSurface(_mainWindow);

    if(!_mainWindowSurface) {
        std::cout << "Failed to create window surface.\n" << SDL_GetError() << "\n";
        return FAILED_WINDOW_SURFACE;
    }

    return SUCCESS;
}

void Application::update() {
    bool keepWindowOpen = true;
    while(keepWindowOpen) {

        SDL_Event event;
        while(SDL_PollEvent(&event) > 0) {
            EVENT_CODE eventCode = handleEvent(&event);
            if(eventCode == QUIT) {
                keepWindowOpen = false;
            }
        }

        draw();

    }
}

Application::EVENT_CODE Application::handleEvent(SDL_Event *event) {
    switch(event->type) {
        case SDL_QUIT:
            return QUIT;
            break;
        default:
            return CONTINUE;
            break;
    }
}

void Application::draw() {
    SDL_UpdateWindowSurface(_mainWindow);
}

Application::ERROR_CODE Application::load(SDL_Surface *image) {
    loadImage(image);

    return SUCCESS;
}



Application::ERROR_CODE Application::loadImage(SDL_Surface *image) {
    if(!image) {
        std::cout << "Failed to load image\n" << SDL_GetError() << "\n";
        return FAILED_IMAGE;
    }

    SDL_BlitSurface(image, NULL, _mainWindowSurface, NULL);

    return SUCCESS;
}