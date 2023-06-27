

#include <SDL2/SDL.h>
#include "../aux.h"
#include <vector>
#include <iterator>
#include <iostream>
#include "GVector.h"
#include "Entity.h"
#include "Gun.h"
#include "Collider.h"
#include "physicsAux.h"

Gun::Gun(SDL_Color clr,float x, float y, float w, float h,float e,float m,float Car,float force,float barrelLen,int capacity,float reloadTime):
Entity(clr,x,  y,  w,  h, e,  m, Car){
this->force=force;
this->barrelLen=barrelLen;
this->capacity=capacity;
this->reloadTime=reloadTime;
this->currAmmo=capacity;
this->x=x;
this->y=y;
this->shootVec=new GVector(1,1);



}

SDL_FPoint Gun::getPos(){

    return (SDL_FPoint){this->x,this->y};
}

void Gun::reload(){

currAmmo=capacity;

}
int Gun::isEmpty(){

return currAmmo==0;
}

float Gun::getReloadTime(){

return reloadTime;

}

float Gun::getShootingForce(){

return this->force;

}
void Gun::shoot(){


this->currAmmo--;



}
void Gun::setShootVec(SDL_FPoint newVec){
    this->shootVec->setCoords(newVec);

}

SDL_FPoint Gun::getShootVec(){
    return this->shootVec->getCoords();

}
Gun* Gun::randGun(float width, float height,float maxMass,float maxSize,float maxSpeed,int capacity,float force){

Entity* ent=randEnt(width,height,maxMass,maxSize,0);



}
Gun::~Gun(){
    this->~Entity();
    delete this->shootVec;

}


