

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

Gun::Gun(SDL_Color clr,float x, float y, float w, float h,float e,float m,float Car,float force,float barrelLen,int capacity,int reloadTime):
Entity(clr,x,  y,  w,  h, e,  m, Car){
this->force=force;
this->barrelLen=barrelLen;
this->capacity=capacity;
this->reloadTime=reloadTime;
this->currAmmo=capacity;
this->x=x;
this->y=y;
this->shootperiod=2000;
this->existenceTime=0;
this->shootCounter=0;
this->shootVec=new GVector(1,1);



}

SDL_FPoint Gun::getPos(){

    return (SDL_FPoint){this->x,this->y};
}

void Gun::reload(){

currAmmo=capacity;
reloadCounter=reloadTime;
shootCounter=0;

}
int Gun::inCooldown(){
return shootCounter>0;
}
int Gun::isEmpty(){

return currAmmo==0;
}

int Gun::getReloadTime(){

return reloadTime;

}

float Gun::getShootingForce(){

return this->force;

}
void Gun::shoot(){

this->currAmmo--;
shootCounter=100;
if(isEmpty()){

this->reloadCounter=reloadTime;
}



}
void Gun::setShootVec(SDL_FPoint newVec){
    this->shootVec->setCoords(newVec);

}
int Gun::canShoot(){

return !isEmpty()&&!inCooldown();

}
void Gun::updateGun(){

this->existenceTime++;
if(isEmpty()){
this->reloadCounter--;
if(reloadCounter==0){
reload();
}
}
if(inCooldown()){
    shootCounter--;
return;
}
}
SDL_FPoint Gun::getShootVec(){
    return this->shootVec->getCoords();

}
Gun::~Gun(){
    delete this->shootVec;

}


