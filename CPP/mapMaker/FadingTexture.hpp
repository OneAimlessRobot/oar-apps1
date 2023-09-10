#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "graphicalLib1.hpp"
#ifndef FADING_TEXT_H
#define FADING_TEXT_H
class FadingTexture{

    clockCounter* counter;
    SDL_Texture*texture;
    SDL_Rect* rect;

    int startFadingTick, endFadingTick;
    Uint8 currentAlpha,startingAlpha;

    Uint8 getAlphaFading();
public:
    FadingTexture(int x, int y, int w, int h, SDL_Texture *texture, int ticks,int startFadingTick,int endFadingTick,Uint8 startingAlpha);
    FadingTexture(SDL_Renderer* renderer,int x, int y, int w, int h, const char* path, int ticks,int startFadingTick,int endFadingTick,Uint8 startingAlpha);
    void setXPos(int value);
    void setYPos(int value);
    void resetFading();
    void increment();
    int getCurrentValue();
    SDL_Point getPos();
    void render(SDL_Renderer* renderer);
    ~FadingTexture();



};
#endif