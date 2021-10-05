#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include<SDL2/SDL.h>
#include<string>

class Drawable {
    public:
        virtual void _cropBackground() = 0;

        int loadImage(std::string imagePath);
        void draw(SDL_Surface *windowSurface);
        bool validate();

    protected:
        SDL_Surface *_image;
        SDL_Rect _position;
        void _cropBackground(int r, int g, int b);
};

#endif // DRAWABLE_H_
