#include<iostream>
#include "application.hpp"

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

void Application::addDrawable(Drawable* drawable) {
    _drawables.push_back(drawable);
}

void Application::run() {
    bool keepWindowOpen = true;
    while(keepWindowOpen) {
        SDL_Event event;
        while(SDL_PollEvent(&event) > 0) {
            EVENT_CODE eventCode = handleEvent(&event);
            if(eventCode == QUIT) {
                keepWindowOpen = false;
            }
        }

        updateDrawablePositions();
        drawDrawables();
        updateSurface();
    }
}

void Application::drawDrawables() {
    SDL_FillRect(_mainWindowSurface, NULL, SDL_MapRGB(_mainWindowSurface->format, 0, 0, 0));

    for(auto drawable: _drawables) {
        drawable->draw(_mainWindowSurface);
    }
}

void Application::updateDrawablePositions() {
    for(auto drawable: _drawables) {
        drawable->calculatePosition();
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

void Application::updateSurface() {
    SDL_UpdateWindowSurface(_mainWindow);
}
