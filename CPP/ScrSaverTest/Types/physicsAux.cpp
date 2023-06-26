#include <random>
#include <cmath>
#include "../aux.h"
#include "GVector.h"
#include "Entity.h"
#include "physicsAux.h"

float PhysicsAux::getReboundSpeed(float initSpeed,float coeff){
return initSpeed-(initSpeed*coeff);
}
void PhysicsAux::separateEntities(Entity *a ,Entity* b){
GVector*va=a->getVec(),
        *vb=b->getVec();
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

void PhysicsAux::rebound(Entity *a ,Entity* b){
float ma=a->getMass(),mb=b->getMass();
GVector * direction=Aux::makeUnitVector(a->getCenter(),b->getCenter()),
        * deltaA=new GVector(-direction->getY(),direction->getX()),
        * deltaB=new GVector(-direction->getY(),direction->getX());

float normalAngleA=GVector::angleBetween(direction,a->getVec());
float normalAngleB=GVector::angleBetween(direction,b->getVec());
GVector *va=a->getVec();
Aux::scaleVec(va,std::cos(normalAngleA));
GVector* vb=b->getVec();
Aux::scaleVec(vb,std::cos(normalAngleB));
GVector* firstresult=GVector::add(va,vb);
float coeff=1+ (a->getElasticity()*b->getElasticity());
float bigCoeff=(((ma*mb)/(ma+mb))*coeff);
Aux::scaleVec(va,-1);
Aux::scaleVec(firstresult,bigCoeff);
float Jn=GVector::dotProduct(firstresult,deltaA);
Aux::scaleVec(deltaA,Jn/ma);
Aux::scaleVec(deltaB,-Jn/mb);
a->setVec(GVector::add(deltaA,va));
b->setVec(GVector::add(deltaB,vb));

}


float PhysicsAux::gravForce(SDL_FPoint p1,SDL_FPoint p2,float m1,float m2){
float dist=Aux::calculateDistance(p1,p2);

return (m1*m2*10*PhysicsAux::GCONST)/(dist*dist);
}


float PhysicsAux::dragNeutralWind(float k,float airD,float speed){

return speed*speed*k*airD;
}


