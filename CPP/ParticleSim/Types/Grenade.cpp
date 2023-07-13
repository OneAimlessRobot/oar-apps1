#include <SDL2/SDL.h>
#include "../auxFuncs.h"
#include <cmath>
#include <vector>
#include <iterator>
#include <iostream>
#include "GVector.h"
#include "Entity.h"
#include "Grenade.h"
#include "../constantHeaders/grenadeSettings.h"
Grenade::Grenade(float x,float y,float chargeForce,int explosionDuration,int timer):Entity(DEFAULTGRENADERGBA,x,y,DEFAULTGRENADESIZE,DEFAULTGRENADESIZE,DEFAULTGRENADEE,DEFAULTGRENADEM,DEFAULTGRENADECAR){
this->chargeForce=chargeForce;
this->explosionDuration=explosionDuration;
this->timer=timer;
this->currTime=0;
this->active=1;
this->explosionHappening=0;


}

float getChargeForce();

Grenade* Grenade::defaultGrenade(){

return new Grenade(0,0,DEFAULTGRENADEBFORCE,1000,DEFAULTGRENADETIMER);


}

void Grenade::update(){
if(active){
if(currTime==timer&&!explosionHappening){
explosionHappening=1;
currTime=0;
return;
}
if(explosionHappening){
currTime++;
if(currTime==explosionDuration){

deactivate();
return;

}
return;

}
currTime++;
}


}
void Grenade::deactivate(){
if(this->active){
this->active=0;

}

}

int Grenade::isActive(){

return active;

}

int Grenade::blowingUp(){
return explosionHappening;

}
Grenade::~Grenade(){




}
