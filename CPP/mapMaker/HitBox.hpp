#include "SDL2/SDL.h"
#ifndef HITBOX_H
#define HITBOX_H
class HitBox{

    SDL_Rect    *left,
                *right,
                *up,
                *down;
    int         x,
                y,
                w,
                h,
                thickness,
                type;
public:
    HitBox(int x,int y, int w, int h, int thickness,int type);
    int getType();
    void setPos(int x,int y);
    SDL_Point getPos();
    int getThickness();
    int getOuterWidth();
    int getInnerWidth();
    int getOuterHeight();
    int getInnerHeight();
    void setInnerWidth(int value);
    void setInnerHeight(int value);
    int hitLeft(const SDL_Rect* rect);
    int hitRight(const SDL_Rect* rect);
    int hitUp(const SDL_Rect* rect);
    int hitDown(const SDL_Rect* rect);
    void render(SDL_Renderer *renderer);

    ~HitBox();


};
#endif
