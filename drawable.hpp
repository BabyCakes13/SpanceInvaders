#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include<SDL2/SDL.h>
#include<string>

class Drawable {
    public:
        virtual void _cropBackground() = 0;

        int loadImage(std::string imagePath);
        void draw(SDL_Surface *windowSurface);
        virtual void calculatePosition() = 0;
        bool validate();

    protected:
        SDL_Surface *_image;
        SDL_Rect _position;
        void _cropBackground(int r, int g, int b);
        void move(int x, int y);
        void setPosition(int x, int y);
};

#endif // DRAWABLE_H_
