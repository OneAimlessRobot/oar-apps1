
#include<SDL2/SDL.h>
#include "Obstacle.hpp"
#include "Trail.hpp"


#ifndef THROWABLE_H
#define THROWABLE_H

class Throwable
{

    SDL_Color color;
    SDL_Point target;
    std::vector<Obstacle*> boxes;
    SDL_Rect *body=NULL;
    SDL_Texture *texture;
    Trail*trail;
    int speed,value;
    double coefficient;

public:
    Throwable(SDL_Renderer*renderer,int x, int y, int width,int initSpeed,double coefficient,int r,int g,int b, int a,int trailLength,int trailThickness,const char*imgPath,int value);
    void setPos(int x, int y);
    void setValue(int value);
    int getValue();
    SDL_Point getPos();
    SDL_Point getTarget();
    SDL_Point getCenter();
    SDL_Rect* getBody();
    void shoot();
    int getSpeed();
    void setSpeed(int value);
    void renderIteration(SDL_Renderer *ren);
    void setTarget(int x, int y);
    void setDirection(int x0,int y0,int x1,int y1);
    int ricochete();
    int getSize();
    void addBox(Obstacle*obstacle);
    void removeAllBoxes();
    int getNumOfBoxes();
    double getCoefficient();
    SDL_Color getColor();

    ~Throwable();
};

#endif
