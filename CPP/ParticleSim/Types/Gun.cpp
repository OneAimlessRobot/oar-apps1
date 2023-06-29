

#include <SDL2/SDL.h>
#include "../aux.h"
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>
#include "GVector.h"
#include "Entity.h"
#include "Gun.h"
#include "Collider.h"
#include "physicsAux.h"

Gun::Gun(SDL_Color clr,float x, float y, float w, float h,float e,float m,float Car,float force,float recoilFactor,float barrelLen,float spreadIndex,int capacity,int reloadTime,int shootperiod):
Entity(clr,x,  y,  w,  h, e,  m, Car){
this->force=force;
this->barrelLen=barrelLen;
this->capacity=capacity;
this->reloadTime=reloadTime;
this->currAmmo=capacity;
this->pos=(SDL_FPoint){x,y};
this->shootperiod=shootperiod;
this->existenceTime=0;
this->spreadMaxAngle=3.14159*0.5*spreadIndex;
this->shootCounter=0;
this->recoilFactor=recoilFactor;
this->shootVec=new GVector(1,1);



}


void Gun::printGunInfo(std::string filePath){
std::ifstream gunRead(filePath);
float force, barrelLen,
            recoil,
            spread,
            reloadTime;
int capacity,
    shootperiod;
gunRead>>force>>barrelLen>>spread>>recoil>>reloadTime>>capacity>>shootperiod;
gunRead.close();
std::cout<<"Características:\n";
std::cout<<"Força: "<<force<<"\n";
std::cout<<"Capacidade: "<<capacity<<"\n";
std::cout<<"spread: "<<spread<<"\n";
std::cout<<"recoil: "<<capacity<<"\n";
std::cout<<"Comprimento cano: "<<barrelLen<<"\n";
std::cout<<"Reloadtime: "<<reloadTime<<"\n";
std::cout<<"ShootCooldown: "<<shootperiod<<"\n";

}
void Gun::setCaliber(caliber bType){


    this->bulletType=bType;

}
Gun* Gun::parseGun(std::string filePath){
std::ifstream gunRead(filePath);
float force, barrelLen,
            recoil,
            spread,
            reloadTime;
int capacity,
    shootperiod;
gunRead>>force>>barrelLen>>spread>>recoil>>reloadTime>>capacity>>shootperiod;
if(!gunRead.is_open()){

std::cerr<<"ERRO DE FICHEIRO A CARREGAR ARMA!!!!\n"<< strerror(errno) <<"\n"<<filePath<<"\n";
return Gun::defaultGun();

}
gunRead>>force>>barrelLen>>spread>>recoil>>reloadTime>>capacity>>shootperiod;
gunRead.close();
return new Gun(Aux::randColor(),0,0,100,100,0.5,0.9,0.9,force,recoil,barrelLen,spread,capacity,reloadTime,shootperiod);






}
Gun* Gun::defaultGun(){

return new Gun(Aux::randColor(),0,0,100,100,0,1,0,1,1,1,0,20,1,1);

}
void Gun::render(SDL_Renderer* ren){
if(isEmpty()){

   SDL_SetRenderDrawColor(ren,255,0,0,255);
   SDL_FRect rect=(SDL_FRect){this->getPos().x-10,this->getPos().y-10,body.w+20,body.h+20};
    SDL_RenderFillRectF(ren,&rect);

}

SDL_SetRenderDrawColor(ren,this->bodyColor.r,this->bodyColor.g,this->bodyColor.b,this->bodyColor.a);

    SDL_RenderFillRectF(ren,&this->body);

    for(SDL_FPoint point: this->lastPositions){
        SDL_RenderDrawPointF(ren,point.x,point.y);
    }
    SDL_SetRenderDrawColor(ren,this->bodyColor.r,this->bodyColor.g,this->bodyColor.b,this->bodyColor.a);

        SDL_FRect rect=(SDL_FRect){this->getLastPos().x,this->getLastPos().y,this->body.x*0.01,this->body.y*0.01};
        SDL_RenderFillRectF(ren,&rect);


}
SDL_FPoint Gun::getPos(){

    return (SDL_FPoint){this->pos.x,this->pos.y};
}
float Gun::getBarrelLength(){

    return this->barrelLen;
}
float Gun::getTilt(){

return Aux::getRandomFloat(-spreadMaxAngle,spreadMaxAngle);



}
float Gun::getRecoilFactor(){

    return recoilFactor;
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
shootCounter=shootperiod;
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


