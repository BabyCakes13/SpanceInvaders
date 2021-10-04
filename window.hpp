#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>

class Window {
    private:
        SDL_Window *window;
        SDL_Surface *windowSurface;

    public:
        enum ERROR_CODE {SUCCESS, FAILED_SDL2_INIT, FAILED_WINDOW, FAILED_WINDOW_SURFACE, FAILED_IMAGE};
        enum EVENT_CODE {CONTINUE, QUIT};

        Window();
        ERROR_CODE initialise();
        void run();
        ERROR_CODE load(SDL_Surface *image);
        ERROR_CODE loadImage(SDL_Surface *image);
        EVENT_CODE handleEvent(SDL_Event *event);
};

#endif
