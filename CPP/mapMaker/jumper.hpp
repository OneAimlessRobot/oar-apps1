
#include "graphicalLib1.hpp"
#include "Trail.hpp"

#ifndef JUMPER_H
#define JUMPER_H
class Jumper{

SDL_Rect body;
SDL_Color color;
clockCounter* counter;
Trail*trail;
int speed,isBouncing,jumpingSpeed,initJumpingSpeed,inverseOfElasticity,floorLevel;

public:
    Jumper(int xInit,int yInit,int initSpeed,int initJumpingSpeed,int isInTheAir,int inverseOfElasticity,int size,SDL_Color color,int floorLevel,int trailLength,int trailWidth);
    ~Jumper();
    void render(SDL_Renderer* renderer);
    void moveX(int dist);
    void moveY(int dist);
    void setX(int value);
    void setY(int value);
    int getX();
    int getY();
    void shoot(int xAim,int yAim,int speed);
    void shootXOnly(int xAim,int speed);
    void shootYOnly(int yAim,int speed);
    void jump();
    void bounce();
    void land();
    int bouncing();
    int justJumped();
    int getJumpingSpeed();
    void setJumpingSpeed(int speed);
    void jumpingIteration(int gravity);
   static int jumpingPosEquation(int gravity,int timeInstant,int basePos);
   static int jumpingSpeedEquation(int gravity,int time,int initSpeed);
   static int fallingPosEquation(int gravity,int timeInstant,int basePos);


};
#endif // JUMPER_H
