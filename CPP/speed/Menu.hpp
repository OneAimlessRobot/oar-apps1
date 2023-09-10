#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include<iostream>
#ifndef MENU_H
#define MENU_H

class textBox{
TTF_Font* Font=NULL;
SDL_Rect Message_rect;
SDL_Texture* texture=NULL;
SDL_Color Color;
char message[128];

public:
    textBox(SDL_Renderer* renderer,int size,int x,int y,const char* fontFileName,Uint8 r, Uint8 g,Uint8 b,Uint8 a,const char* message);

    int getWidth();

    int getHeight();

    int getXPos();

    int getYPos();

    SDL_Color getTextColor();

    SDL_Color getBoxColor();

    void render(SDL_Renderer* renderer);
    void updateText(SDL_Renderer* renderer,const char* str);

    char * printMsg();

    SDL_Texture* getTexture();

    ~textBox();

};

#endif
