
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Includes/Obstacle.hpp"
#include "../Includes/LTexture.hpp"
#include <vector>
#include "../Includes/TextBox.hpp"
#include "../Includes/auxFunctions.h"
#include "../Includes/graphicalLib1.hpp"
#include<iostream>
#include "../Includes/Obstacle.hpp"
#include "../Includes/Trail.hpp"
#include "../Includes/GeometricVector.hpp"
#include "../Includes/Object.hpp"
#include "../Includes/throwable.hpp"


Throwable::Throwable(SDL_Renderer*renderer,float x, float y, float width,SDL_Color color,float trailLength,float trailThickness,const char*imgPath,int value, float coefficient,float DCoefficient):Object(renderer,x, y, width,trailLength,trailThickness,color,imgPath,DCoefficient)
    {
        this->speedVec=GeometricVector<float>::neutralVector(this->getCenter().x,this->getCenter().y);
        this->coefficient=coefficient;
        this->boxes={};
        this->value=value;
    }
    void Throwable::setVector(GeometricVector<float>*vec){

        this->speedVec=vec;

    }
    void Throwable::setValue(int value){

      this->value=value;


    }
    int Throwable::getValue(){

       return this->value;

    }
    float Throwable::getCoefficient(){
        return this->coefficient;
    }
    void Throwable::shoot(){

        this->speedVec->setStart(this->getCenter());
        SDL_FPoint after=this->speedVec->getTip();
        this->setPos(after.x-this->getSize()*0.5,after.y-this->getSize()*0.5);
    }
    void Throwable::addBox(Obstacle*obstacle){
        this->boxes.push_back(obstacle);
    }
    int Throwable::ricochete(){

        for(Obstacle *thing:this->boxes){
        if(!(thing->getHitBoxType())){
//LEFT

                if(thing->boxHitLeft(this->getBody())){
                    this->setPos(thing->getCorePos().x+1,this->getPos().y);
                    this->speedVec->setDx(-this->speedVec->getDx());
                    this->speedVec->setLength(this->speedVec->getLength()-(this->speedVec->getLength()/this->getCoefficient()));
                    return 1;
                }
                //RIGHT
                else if(thing->boxHitRight(this->getBody())){
                    this->setPos(thing->getCorePos().x+thing->getInnerWidth()-1-this->getBody()->w,this->getPos().y);
                    this->speedVec->setDx(-this->speedVec->getDx());
                    this->speedVec->setLength(this->speedVec->getLength()-(this->speedVec->getLength()/this->getCoefficient()));
                    return 1;

                }
                //DOWN
                else if(thing->boxHitDown(this->getBody())){
                    this->setPos(this->getPos().x,thing->getCorePos().y+thing->getInnerHeight()-1-this->getBody()->h);
                    this->speedVec->setDy(-this->speedVec->getDy());
                    this->speedVec->setLength(this->speedVec->getLength()-(this->speedVec->getLength()/this->getCoefficient()));
                    return 1;
                }
                else if(thing->boxHitUp(this->getBody())){
                    this->setPos(this->getPos().x,thing->getCorePos().y+1);
                    this->speedVec->setDy(-this->speedVec->getDy());
                    this->speedVec->setLength(this->speedVec->getLength()-(this->speedVec->getLength()/this->getCoefficient()));
                    return 1;
                }
            }
            else if(thing->getHitBoxType()){
                if(thing->boxHitLeft(this->getBody())){
                    this->setPos(thing->getShellPos().x-this->getBody()->w-1,this->getPos().y);
                    this->speedVec->setDx(-this->speedVec->getDx());
                    this->speedVec->setLength(this->speedVec->getLength()-(this->speedVec->getLength()/this->getCoefficient()));
                    return 1;
                }
                else if(thing->boxHitDown(this->getBody())){
                    this->setPos(this->getPos().x,thing->getOuterHeight()+thing->getShellPos().y+1);
                    this->speedVec->setDy(-this->speedVec->getDy());
                    this->speedVec->setLength(this->speedVec->getLength()-(this->speedVec->getLength()/this->getCoefficient()));
                    return 1;

                }
                else if(thing->boxHitUp(this->getBody())){
                    this->setPos(this->getPos().x,thing->getShellPos().y-this->getBody()->h-1);
                    this->speedVec->setDy(-this->speedVec->getDy());
                    this->speedVec->setLength(this->speedVec->getLength()-(this->speedVec->getLength()/this->getCoefficient()));
                    return 1;
                }

                else if(thing->boxHitRight(this->getBody())){
                    this->setPos(thing->getShellPos().x+thing->getOuterWidth()+1,this->getPos().y);
                    this->speedVec->setDx(-this->speedVec->getDx());
                    this->speedVec->setLength(this->speedVec->getLength()-(this->speedVec->getLength()/this->getCoefficient()));
                    return 1;
                }
            }
            }
            return 0;


    }
    int Throwable::getNumOfBoxes(){
        return this->boxes.size();
    }

    GeometricVector<float>*Throwable::getVector(){

    return this->speedVec;

    }

    Throwable::~Throwable(){

        delete(speedVec);

    }

