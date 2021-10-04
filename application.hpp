#ifndef APPLICATION_H_
#define APPLICATION_H_

#include<SDL2/SDL.h>

#include "drawable.hpp"

class Application {
    public:
        Application();
        ~Application();

        enum ERROR_CODE {SUCCESS, FAILED_SDL2_INIT, FAILED_WINDOW, FAILED_WINDOW_SURFACE, FAILED_IMAGE};
        enum EVENT_CODE {CONTINUE, QUIT};

        void run();
        void addDrawables(Drawable *drawable);

    private:
        SDL_Window *_mainWindow;
        SDL_Surface *_mainWindowSurface;
        SDL_Event mainWindowEvent;
        Drawable *_drawable;

        ERROR_CODE initialise();
        void updateSurface();
        EVENT_CODE handleEvent(SDL_Event *event);
};

#endif // APPLICATION_H_
