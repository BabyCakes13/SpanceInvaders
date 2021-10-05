#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include<SDL2/SDL.h>
#include<string>

class Drawable {
    public:
        void draw(SDL_Surface *windowSurface);
        virtual void calculatePosition() = 0;

    protected:
        SDL_Surface *_image;
        SDL_Rect _position;

        int _loadImage(std::string imagePath);
        void _cropBackground(int r, int g, int b);
        void move(int x, int y);
        void setPosition(int x, int y);

    private:
        bool _validate();
};

#endif // DRAWABLE_H_
