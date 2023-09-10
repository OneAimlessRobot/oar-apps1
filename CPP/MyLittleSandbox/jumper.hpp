

#ifndef JUMPER_H
#define JUMPER_H
class Jumper:public Object{

clockCounter* counter;
GeometricVector<float>*speedVec;
int isBouncing,jumpingSpeed,initJumpingSpeed,inverseOfElasticity,floorLevel;

public:
    Jumper(SDL_Renderer*renderer,float xInit,float yInit,float initJumpingSpeed,float inverseOfElasticity,float width,SDL_Color color,float floorLevel,float  trailLength,float trailWidth,const char* imgPath,float DCoefficient);
    ~Jumper();
    void movePos(float  distX,float  distY);
    void shoot();
    void bounce();
    void land();
    int bouncing();
    float getJumpingSpeed();
    void setJumpingSpeed(float speed);
    void trajectoryCalculation(float gravity);
   static float jumpingPosEquation(float gravity,float timeInstant,float basePos);
   static float jumpingSpeedEquation(float gravity,float time,float initSpeed);
   static float fallingPosEquation(float gravity,float timeInstant,float basePos);


};
#endif // JUMPER_H
