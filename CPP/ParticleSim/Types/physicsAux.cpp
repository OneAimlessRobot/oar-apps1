#include <random>
#include <cmath>
#include "../aux.h"
#include <iostream>
#include "GVector.h"
#include "Entity.h"
#include "Collider.h"
#include "physicsAux.h"

float PhysicsAux::getReboundSpeed(float initSpeed,float coeff){
return initSpeed-(initSpeed*coeff);
}

float PhysicsAux::blastForce(SDL_FPoint p1,SDL_FPoint p2,float forceConst){


float dist=Aux::calculateDistance(p1,p2);

return (forceConst*PhysicsAux::GCONST)/(dist*dist);
}

void PhysicsAux::railAcceleration(Entity* ent,SDL_FPoint forceVec,float length){

for(float curr=0;curr<=length;curr+=GVector::getNorm(forceVec)){

    float efficiency=std::cos(GVector::angleBetween(ent->getVec(),forceVec));
    float efficientComponentMagnitude= GVector::getNorm(forceVec)*efficiency;
    SDL_FPoint paralelToMovement=Aux::makeUnitVector((SDL_FPoint){0,0},ent->getVec());
    Aux::scaleVec(&paralelToMovement,efficientComponentMagnitude);
    accelerateEntity(ent,paralelToMovement);

}




}
SDL_FPoint PhysicsAux::blastVector(SDL_FPoint p1,SDL_FPoint p2,float forceConst){


        SDL_FPoint newVec=Aux::makeUnitVector(p1,p2);
        float accel= PhysicsAux::blastForce(p1,p2,forceConst);
        if(Aux::calculateDistance(p1 ,p2)<=50){
            Aux::scaleVec(&newVec,10);
        }
        else{
        Aux::scaleVec(&newVec,accel);
        }
        return newVec;


}

void PhysicsAux::accelerateEntity(Entity* ent,SDL_FPoint forceVec){



        SDL_FPoint accelVec=getAccelVec(forceVec,ent->getMass());
        ent->setVec(GVector::add(accelVec,ent->getVec()));


}
SDL_FPoint PhysicsAux::getAccelVec(SDL_FPoint forcevec,float mass){


        SDL_FPoint accel= forcevec;
//        Aux::scaleVec(&accel,1/mass);

        return accel;
}
SDL_FPoint PhysicsAux::gravVector(SDL_FPoint p1,SDL_FPoint p2,float m1,float m2){


        SDL_FPoint newVec=Aux::makeUnitVector(p1,p2);
        float accel= PhysicsAux::gravForce(p1,p2,m1,m2);
        if(Aux::calculateDistance(p1 ,p2)<=50){
            Aux::scaleVec(&newVec,-1);
        }
        else{
        Aux::scaleVec(&newVec,-accel);
        }
        return newVec;

}

SDL_FPoint PhysicsAux::dragNeutralWindVector(SDL_FPoint vVec,float k, float airD){

        SDL_FPoint newVec=Aux::makeUnitVector((SDL_FPoint){0,0},vVec);
        float dragMag= PhysicsAux::dragNeutralWind(k,airD,GVector::getNorm(vVec));
        Aux::scaleVec(&newVec,-dragMag);
        return newVec;



}
void PhysicsAux::separateEntities(Entity *a ,Entity* b){
SDL_FPoint va=a->getVec(),
        vb=b->getVec();
    SDL_FPoint separatorB=Aux::makeUnitVector(a->getCenter(),b->getCenter());
    SDL_FPoint separatorA=Aux::makeUnitVector(b->getCenter(),a->getCenter());
    a->setVec(separatorA);
    b->setVec(separatorB);
    while(Entity::areTouching(a,b)){
    a->translate();
    b->translate();

    }
    a->setVec(va);
    b->setVec(vb);


}
void PhysicsAux::separateEntityFromCollider(Entity* a,Collider *col,int where){
    if(where==0){
        return;
    }
    SDL_FPoint og= (SDL_FPoint){a->getVec().x,a->getVec().y};
   SDL_FPoint inv= Aux::makeUnitVector((SDL_FPoint){0,0},(SDL_FPoint){-og.x,-og.y});
//    a->translate();
//    if(col->whereIsColliding(a->getBody())==0){
//
//        return;

//    }
//    float secArea=Aux::getRectArea(col->getInter(a->getBody(),col->whereIsColliding(a->getBody())));
//    if(firstArea<secArea){
    a->setVec(inv);
//    }



    do{
    where=col->whereIsColliding(a->getBody());
    a->translate();

    }while(where!=0);
    a->setVec(og);


}
void PhysicsAux::rebound(Entity *a ,Entity* b){
float ma=a->getMass(),mb=b->getMass();

SDL_FPoint directionA=Aux::makeUnitVector(a->getCenter(),b->getCenter()),
            directionB=Aux::makeUnitVector(a->getCenter(),b->getCenter());

float normalAngleA=GVector::angleBetween(a->getVec(),directionA);
float normalAngleB=GVector::angleBetween(b->getVec(),directionA);
//tudo bem.
SDL_FPoint pva=a->getVec();
Aux::scaleVec(&pva,std::cos(normalAngleA));
SDL_FPoint pvb=b->getVec();
Aux::scaleVec(&pvb,std::cos(normalAngleB));
//tudo bem.
Aux::scaleVec(&pva,-1);
SDL_FPoint firstresult=GVector::add(pva,pvb);
//tudo bem
float coeff=1+ ((1-a->getInvElasticity())*(1-b->getInvElasticity()));
float bigCoeff=(((ma*mb)/(ma+mb))*coeff);

Aux::scaleVec(&firstresult,bigCoeff);
float Jn=GVector::dotProduct(firstresult,directionA);
Aux::scaleVec(&directionA,Jn/ma);
Aux::scaleVec(&directionB,-Jn/mb);
a->setVec(GVector::add(directionA,a->getVec()));
b->setVec(GVector::add(directionB,b->getVec()));

}

float PhysicsAux::gravForce(SDL_FPoint p1,SDL_FPoint p2,float m1,float m2){
float dist=Aux::calculateDistance(p1,p2);

return (m1*m2*10*PhysicsAux::GCONST)/(dist*dist);
}


float PhysicsAux::dragNeutralWind(float k,float airD,float speed){

return speed*speed*k*airD;
}

