

#ifndef JUMPER_H
#define JUMPER_H
class Jumper:public Object{

clockCounter* counter;
GeometricVector<int>*speedVec;
int isBouncing,jumpingSpeed,initJumpingSpeed,inverseOfElasticity,floorLevel;

public:
    Jumper(SDL_Renderer*renderer,int xInit,int yInit,int initJumpingSpeed,int inverseOfElasticity,int size,SDL_Color color,int floorLevel,int trailLength,int trailWidth,const char* imgPath,double DCoefficient);
    ~Jumper();
    void movePos(int distX,int distY);
    void shoot();
    void bounce();
    void land();
    int bouncing();
    int getJumpingSpeed();
    void setJumpingSpeed(int speed);
    void trajectoryCalculation(int gravity);
   static int jumpingPosEquation(int gravity,int timeInstant,int basePos);
   static int jumpingSpeedEquation(int gravity,int time,int initSpeed);
   static int fallingPosEquation(int gravity,int timeInstant,int basePos);


};
#endif // JUMPER_H
