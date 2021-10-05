#include "drawable.hpp"
#include <SDL2/SDL_surface.h>
#include<iostream>


void Drawable::draw(SDL_Surface *windowSurface) {
    SDL_BlitScaled(_image, NULL, windowSurface, &_position);
}

bool Drawable::validate() {
     if(!_image) {
        std::cout << "Failed to load image\n" << SDL_GetError() << "\n";
        return false;
     }
     return true;
}

int Drawable::loadImage(std::string imagePath) {
    _image = SDL_LoadBMP(imagePath.c_str());
    validate();
  return 0;
}

void Drawable::setPosition(int x, int y) {
  _position.x = x;
  _position.y = y;
}

void Drawable::move(int x, int y) {
  _position.x += x;
  _position.y += y;
}

void Drawable::_cropBackground(int r, int g, int b) {
  SDL_SetColorKey(_image, SDL_TRUE, SDL_MapRGB( _image->format, r, g, b ));
}
