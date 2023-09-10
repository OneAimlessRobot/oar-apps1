#include "HitBox.hpp"
#ifndef OBSTACLE_H
#define OBSTACLE_H
class Obstacle{

    HitBox *hitBox;
    SDL_FRect*body;
    SDL_Texture *texture;
    SDL_Color color;
    float thickness;
public:
    Obstacle(SDL_Renderer*renderer,float x,float y, float w, float h, float thickness,int type,SDL_Color color,const char* path);

    int getHitBoxType();
    void setPos(float x,float y);
    SDL_FPoint getShellPos();
    SDL_FPoint getCorePos();
    float getThickness();
    float getOuterWidth();
    float getInnerWidth();
    float getOuterHeight();
    float getInnerHeight();
    void setInnerWidth(float value);
    void setInnerHeight(float value);
    int boxHitLeft(const SDL_FRect* rect);
    int boxHitRight(const SDL_FRect* rect);
    int boxHitUp(const SDL_FRect* rect);
    int boxHitDown(const SDL_FRect* rect);
    int boxContains(const SDL_FRect* rect);
    void renderBodyOnly(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);
    ~Obstacle();

};
#endif
