#include <SDL2/SDL.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "Menu.hpp"
#include "auxFunctions.h"
#include "graphicalLib1.hpp"
#include "LTexture.hpp"
#include "Trail.hpp"
#include "GeometricVector.hpp"
#include "Object.hpp"
#include "jumper.hpp"
    Jumper::Jumper(SDL_Renderer*renderer,int xInit,int yInit,int initJumpingSpeed,int inverseOfElasticity,int size,SDL_Color color,int floorLevel,int trailLength,int trailWidth,const char*imgPath,double DCoefficient):Object(renderer,xInit,yInit,size,trailLength,trailWidth,color,imgPath,DCoefficient){

        this->initJumpingSpeed=initJumpingSpeed;
        this->speedVec=GeometricVector<int>::neutralVector(this->getCenter().x,this->getCenter().y);
        this->floorLevel=floorLevel;
        this->isBouncing=0;
        this->inverseOfElasticity=inverseOfElasticity;
        this->counter=new clockCounter(0,0,1);
    }
    void Jumper::movePos(int distX,int distY){
    this->setPos(this->getPos().x+distX,this->getPos().y+distY);
    }

    void Jumper::shoot(){

        this->speedVec->setStart(this->getCenter());
        SDL_Point after= this->speedVec->getTip();
        this->setPos(after.x-this->getSize()*0.5,after.y-this->getSize()*0.5);

    }
    void Jumper::land(){
        this->isBouncing=0;
    }
    void Jumper::bounce(){
        this->setPos(this->getPos().x,this->floorLevel-1);
    if(!this->isBouncing){
        this->isBouncing=1;
        this->jumpingSpeed=initJumpingSpeed;
        this->speedVec=new GeometricVector<int>(this->getCenter().x,this->getCenter().y,0,-1,positive,jumpingSpeed);
        }
    else{
        this->jumpingSpeed-=this->inverseOfElasticity;
        this->speedVec=new GeometricVector<int>(this->getCenter().x,this->getCenter().y,0,-1,positive,jumpingSpeed);
        }


    }
    int Jumper::getJumpingSpeed(){

    return this->jumpingSpeed;
    }
    void Jumper::setJumpingSpeed(int speed){

    this->jumpingSpeed=speed;
    }

    int Jumper::bouncing(){
        return this->isBouncing;
    }

    void Jumper::trajectoryCalculation(int gravity){
    if(this->getJumpingSpeed()<=0){
        this->land();
        }

    else if(this->isBouncing){

    if(this->getPos().y<this->floorLevel){
                GeometricVector<int>*acceleration=new GeometricVector<int>(this->getCenter().x,this->getCenter().y,0,1,positive,gravity);
                speedVec=speedVec->add(acceleration);
                this->shoot();
                delete(acceleration);
        }
                else{
                this->bounce();

                }
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

    delete(speedVec);
   delete(counter);
   }

