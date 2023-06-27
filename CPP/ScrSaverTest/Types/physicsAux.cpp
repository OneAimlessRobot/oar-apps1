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
void PhysicsAux::separateEntities(Entity *a ,Entity* b){
GVector*va=new GVector(a->getVec()->getX(),a->getVec()->getY()),
        *vb=new GVector(b->getVec()->getX(),b->getVec()->getY());
    GVector* separatorB=Aux::makeUnitVector(a->getCenter(),b->getCenter());
    GVector* separatorA=Aux::makeUnitVector(b->getCenter(),a->getCenter());
    a->setVec(separatorA);
    b->setVec(separatorB);
    while(Aux::calculateDistance(a->getCenter(),b->getCenter())<=a->getRadius()+b->getRadius()){
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
    GVector *og= new GVector(a->getVec()->getX(),a->getVec()->getY());
    GVector *inv= Aux::makeUnitVector((SDL_FPoint){0,0},(SDL_FPoint){-a->getVec()->getX(),-a->getVec()->getY()});
    a->setVec(inv);
    do{
    where=col->whereIsColliding(a->getBody());
    a->translate();

    }while(where!=0);
    a->setVec(og);


}
void PhysicsAux::rebound(Entity *a ,Entity* b){
float ma=a->getMass(),mb=b->getMass();

GVector * directionA=Aux::makeUnitVector(a->getCenter(),b->getCenter()),
        * directionB=Aux::makeUnitVector(a->getCenter(),b->getCenter());

float normalAngleA=GVector::angleBetween(a->getVec(),directionA);
float normalAngleB=GVector::angleBetween(b->getVec(),directionA);
//tudo bem.
GVector *pva=a->getVec();
Aux::scaleVec(pva,std::cos(normalAngleA));
GVector* pvb=b->getVec();
Aux::scaleVec(pvb,std::cos(normalAngleB));
//tudo bem.
Aux::scaleVec(pva,-1);
GVector* firstresult=GVector::add(pva,pvb);
//tudo bem
float coeff=1+ (a->getElasticity()*b->getElasticity());
float bigCoeff=(((ma*mb)/(ma+mb))*coeff);

Aux::scaleVec(firstresult,bigCoeff);
float Jn=GVector::dotProduct(firstresult,directionA);
Aux::scaleVec(directionA,Jn/ma);
Aux::scaleVec(directionB,-Jn/mb);
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


