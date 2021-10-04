#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include<SDL2/SDL.h>
#include<string>

class Drawable {
    public:
        int loadImage(std::string imagePath);
        void draw(SDL_Surface *windowSurface);
        bool validate();

    protected:
        SDL_Surface *_image;
        SDL_Rect _position;
};

#endif // DRAWABLE_H_
