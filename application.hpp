#ifndef APPLICATION_H_
#define APPLICATION_H_

#include<SDL2/SDL.h>

class Application {
    public:
        Application();
        ~Application();

        enum ERROR_CODE {SUCCESS, FAILED_SDL2_INIT, FAILED_WINDOW, FAILED_WINDOW_SURFACE, FAILED_IMAGE};
        enum EVENT_CODE {CONTINUE, QUIT};

        ERROR_CODE initialise();
        void update();
        void draw();
        EVENT_CODE handleEvent(SDL_Event *event);
        ERROR_CODE load(SDL_Surface *image);
        ERROR_CODE loadImage(SDL_Surface *image);

    private:
        SDL_Window *_mainWindow;
        SDL_Surface *_mainWindowSurface;
        SDL_Event mainWindowEvent;
};

#endif // APPLICATION_H_
