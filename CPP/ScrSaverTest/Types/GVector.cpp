
#include "GVector.h"
#include <SDL2/SDL.h>
#include "../aux.h"
    GVector::GVector(float x,float y){

    this->x=x;
    this->y=y;


    }
    float GVector::getX(){
        return this->x;

    }
    float GVector::getY(){
        return this->y;

    }
    void GVector::setX(float newX){
        this->x=newX;

    }
    void GVector::setY(float newY){
        this->y=newY;

    }
    float GVector::getNorm(){

        return Aux::calculateDistance((SDL_FPoint){0,0},(SDL_FPoint){this->x,this->y});

    }
    void GVector::Reflect(GVector* velocity, GVector* collisionNormal) {
    float dotProduct = velocity->x * collisionNormal->x + velocity->y * collisionNormal->y;
    velocity->x = velocity->x - 2.0f * dotProduct * collisionNormal->x;
    velocity->y = velocity->y - 2.0f * dotProduct * collisionNormal->y;
    delete collisionNormal;
    }
    GVector::~GVector(){


    }
