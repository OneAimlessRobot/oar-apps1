#include <SDL2/SDL.h>
#include <math.h>
#include "jumper.hpp"
    Jumper::Jumper(int xInit,int yInit,int initSpeed,int initJumpingSpeed,int isInTheAir,int inverseOfElasticity,int size,SDL_Color color,int floorLevel,int trailLength,int trailWidth){
        this->body=(SDL_Rect){xInit,yInit,size,size};
        this->trail=new Trail(trailLength,trailWidth,xInit,yInit,color);
        this->color=color;
        this->speed=initSpeed;
        this->initJumpingSpeed=initJumpingSpeed;
        this->floorLevel=floorLevel;
        this->isBouncing=isInTheAir;
        this->inverseOfElasticity=inverseOfElasticity;
        this->counter=new clockCounter(0,0,1);
    }
    void Jumper::render(SDL_Renderer* renderer){

    trail->setPos(this->getX()+this->body.w*0.5,this->getY()+this->body.w*0.5);
    trail->render(renderer);
    SDL_SetRenderDrawColor(renderer,this->color.r,this->color.g,this->color.b,255);
    SDL_RenderFillRect(renderer,&this->body);
    }
    void Jumper::moveX(int dist){
    this->body.x+=dist*speed;
    }
    void Jumper::moveY(int dist){
    this->body.y+=dist*speed;
    }
    void Jumper::setX(int value){
    this->body.x=value;
    }
    void Jumper::setY(int value){
    this->body.y=value;
    }

    void Jumper::shoot(int xAim,int yAim,int speed){
        this->body.x += round(speed * cos(atan2(yAim - this->body.y , xAim - this->body.x)));
        this->body.y += round(speed * sin(atan2(yAim - this->body.y , xAim - this->body.x)));

    }
    void Jumper::shootXOnly(int xAim,int speed){

    }
    void Jumper::shootYOnly(int yAim,int speed){

    }
    int Jumper::getX(){
    return this->body.x;
    }
    int Jumper::getY(){
    return this->body.y;

    }
    void Jumper::jump(){
    if(!this->bouncing()){
        this->isBouncing=1;
        this->setY(this->floorLevel-1);
        this->jumpingSpeed=this->initJumpingSpeed;
        }
    }

    void Jumper::land(){
        this->isBouncing=0;
        this->counter->setCurrent(0);
    }
    void Jumper::bounce(){
        this->setY(this->floorLevel-1);
        this->counter->setCurrent(0);
        this->jumpingSpeed-=this->inverseOfElasticity;
    }
    int Jumper::bouncing(){
    return this->isBouncing;
    }
    int Jumper::getJumpingSpeed(){

    return this->jumpingSpeed;
    }
    void Jumper::setJumpingSpeed(int speed){

    this->jumpingSpeed=speed;
    }

    void Jumper::jumpingIteration(int gravity){

    if(this->getJumpingSpeed()<=0){
        this->land();
        }

    else if(this->bouncing()){

    if(this->getY()<this->floorLevel){
        this->shoot(this->getX(),this->floorLevel,jumpingSpeedEquation(gravity,jumpingSpeed,this->counter->getCurrent()));
        }
                else{
                this->bounce();

                }

    this->counter->increment();
                }


    }
   int Jumper::jumpingPosEquation(int gravity,int timeInstant,int basePos){

        return round(gravity*((timeInstant/100)-(sqrt(basePos/gravity)))*((timeInstant/100)-(sqrt(basePos/gravity)))-1);
   }
   int Jumper::jumpingSpeedEquation(int gravity,int initSpeed,int time){

        return round(2*gravity*(time)-2*initSpeed);
   }
   int Jumper::fallingPosEquation(int gravity,int timeInstant,int basePos){

        return gravity*(timeInstant/1000)*(timeInstant/1000)-1;
   }
   Jumper::~Jumper(){
   delete(trail);
   delete(counter);
   }

