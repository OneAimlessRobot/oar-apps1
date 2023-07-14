

#include <SDL2/SDL.h>
#include "../auxFuncs.h"
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>
#include "Bullet.h"
#include "GVector.h"
#include "Entity.h"
#include "../constantHeaders/gunSettings.h"
#include "../constantHeaders/IOSettings.h"
#include "Gun.h"
#include "Collider.h"
#include "physicsAux.h"

Gun::Gun(SDL_Color clr,float x, float y, float w, float h,float e,float m,float Car,float force,float recoilFactor,float barrelLen,float spreadIndex,int capacity,int reloadTime,int shootperiod):Entity(clr,x,  y,  w,  h, e,  m, Car){
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

void Gun::setCaliber(caliber bType){

    this->bulletType=bType;
}

caliber Gun::getCaliber(){

    return this->bulletType;
}
//void Gun::setCaliber(caliber bType){
//
//
//    this->bulletType=bType;
//
//}
Gun* Gun::defaultGun(){

return new Gun(DEFAULTGUNRGBA,0,0,
    DEFAULTGUNW,
    DEFAULTGUNH,
    DEFAULTGUNE,
    DEFAULTGUNM,
    DEFAULTGUNCAR,
    DEFAULTGUNFORCE,
    DEFAULTGUNRECOIL,
    DEFAULTGUNBARRELLENGTH,
    DEFAULTGUNSPREAD,
    DEFAULTGUNCAP,
    DEFAULTGUNRELTIME,
    DEFAULTGUNSHOTTIME);

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

        SDL_FRect rect=(SDL_FRect){this->getLastPos().x,this->getLastPos().y,this->body.w*0.01f,this->body.h*0.01f};
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
void Gun::setTarget(float x, float y){


    SDL_FPoint master=(SDL_FPoint){x,y},
                slave=getCenter();
    SDL_FPoint vec= Aux::makeUnitVector(slave,master);
    Aux::scaleVec(&vec,getShootingForce());
    setShootVec(vec);

}
Entity* Gun::shoot(){

    caliber bType=getCaliber();
//    std::cout<<this->shootVec->getX()<<" , "<<this->shootVec->getY()<<" \n";
    SDL_FPoint launchPos=getCenter();
    Entity* bullet= new Entity(Aux::randColor(),launchPos.x,launchPos.y,bType.size,bType.size,bType.e,bType.mass,bType.Car);
    //dou-lhe o pointer para o vetor da gun. Mais tarde, quando apago as guns, apago o vetor. quando
    //tento apagar as entities, dá merda.
    float shootSpread=getTilt();
    PhysicsAux::railAcceleration<Entity>(bullet,getShootVec(),shootSpread,getBarrelLength());
    bullet->setVec(GVector::tiltVector(bullet->getVec(),shootSpread));
    SDL_FPoint tiltedVec=GVector::tiltVector(getShootVec(),getTilt());
    Aux::scaleVec(&tiltedVec,-getRecoilFactor());
    this->currAmmo--;
    shootCounter=shootperiod;
    if(isEmpty()){

    this->reloadCounter=reloadTime;
    }
    else{

    setVec(GVector::add(tiltedVec,getVec()));

    }

    return bullet;



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


