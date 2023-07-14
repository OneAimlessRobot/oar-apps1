
#include <SDL2/SDL.h>
#include "../auxFuncs.h"
#include <cmath>
#include <vector>
#include <iterator>
#include <iostream>
#include "GVector.h"
#include "Entity.h"
#include "Collider.h"
#include "physicsAux.h"

Entity::Entity(SDL_Color clr,float x, float y, float w, float h,float inve, float m,float Car){

    this->bodyColor=clr;
    if(w<=0){
        w=1;
    }
    if(h<=0){
        h=1;
    }
    this->body=(SDL_FRect){x,y,w,h};
    this->pos=(SDL_FPoint){x,y};
    this->moveVec= new GVector(0.000001,0.00001);
    this->lastPositions={};
    if(inve==1){
    this->inve=0.99;
    }
    else{
    this->inve=inve;
    }
    this->mass=m;
    this->Car=Car;


}
void Entity::render(SDL_Renderer*ren){
    SDL_SetRenderDrawColor(ren,this->bodyColor.r,this->bodyColor.g,this->bodyColor.b,this->bodyColor.a);
    SDL_RenderFillRectF(ren,&this->body);

    for(SDL_FPoint point: this->lastPositions){
        SDL_RenderDrawPointF(ren,point.x,point.y);
    }

        SDL_FRect rect=(SDL_FRect){this->getLastPos().x,this->getLastPos().y,this->body.x*0.01f,this->body.y*0.01f};
        SDL_RenderFillRectF(ren,&rect);
}
void Entity::setPos(SDL_FPoint point){

    this->lastPos=pos;
    this->pos.x=point.x;
    this->pos.y=point.y;
    this->body.x=point.x;
    this->body.y=point.y;

}
SDL_FPoint Entity::getPos(){

    return this->pos;

}
float Entity::getDragConstant(){

    return this->body.w*this->Car*0.001f;
}
SDL_FPoint Entity::getLastPos(){

    if(this->lastPositions.empty()){
        return pos;
    }
    return this->lastPositions.at(this->lastPositions.size()-std::min(COLLDISTANCE,(int)this->lastPositions.size()));

}
void Entity::translate(){
    this->lastPositions.push_back(this->pos);
    if(this->lastPositions.size()>TRAILLENGTH){
        this->lastPositions.erase(this->lastPositions.begin());
    }
    this->pos.x+=this->moveVec->getX();
    this->pos.y+=this->moveVec->getY();
    this->body.x+=this->moveVec->getX();
    this->body.y+=this->moveVec->getY();

}

float Entity::getInvElasticity(){

    return this->inve;
}
float Entity::getMass(){
 return this->mass;
}
void Entity::bounce(){
    float newSpeed=PhysicsAux::getReboundSpeed(GVector::getNorm(this->getVec()),this->inve);
    //O vetor e (nan, nan)
// ----------           if(newSpeed!=newSpeed){
//    std::cout<<"ERRO!!!!!\n";
//    }

    SDL_FPoint newVector=Aux::makeUnitVector((SDL_FPoint){0,0},(SDL_FPoint){this->moveVec->getX(),this->moveVec->getY()});
    Aux::scaleVec(&newVector,newSpeed);
//---------                if(newVector.x!=newVector.x||newVector.y!=newVector.y){
//    std::cout<<"ERRO!!!!!\n";
//    }

    this->setVec(newVector);

}
int Entity::areTouching(Entity*a,Entity*b){


 return (Aux::calculateDistance(a->getCenter(),b->getCenter()))<=a->getRadius()+b->getRadius();

}
Entity* Entity::randEnt(float width, float height,float maxMass,float maxSize,float maxSpeed){
float size= Aux::getRandomFloat(10,maxSize);
float x= Aux::getRandomFloat(1,width-size-1);
float y=Aux::getRandomFloat(1,height-size-1);
float maxAngle=Aux::getRandomFloat(0,2*3.14159);
float inve=Aux::getRandomFloat(0,1);
//float e=0;

float newMass=Aux::getRandomFloat(0,maxMass);
float coeffOfAirR=Aux::getRandomFloat(0,1);
float dx= std::cos(maxAngle);
float dy=std::sin(maxAngle);
float speed=Aux::getRandomFloat(maxSpeed,maxSpeed);
SDL_Color color= Aux::randColor();
SDL_FPoint resmoveVec= Aux::makeUnitVector((SDL_FPoint){0,0},(SDL_FPoint){dx,dy});
// --------       if(resmoveVec.x!=resmoveVec.x||resmoveVec.y!=resmoveVec.y){
//    std::cout<<"ERRO!!!!!\n";
//    }

Aux::scaleVec(&resmoveVec,speed);
Entity* result=new Entity(color,x,y,size,size,inve,newMass,coeffOfAirR);
result->setVec(resmoveVec);
//----------if(result->getVec().x!=result->getVec().x||result->getVec().y!=result->getVec().y){
//    std::cout<<"ERRO!!!!!\n";
//    }
return result;


}
SDL_FPoint Entity::getVec(){

return this->moveVec->getCoords();
}
SDL_FRect Entity::getBody(){

    return (this->body);
}
float Entity::getRadius(){

    return this->body.w*0.5;

}

float Entity::getTotalEnergy(){
    float v=GVector::getNorm(this->getVec()),m=this->getMass();
    return v*v*m*0.5;

}


float Entity::getQuality(){
//quanto mais pequeno "e", melhor
    return (GVector::getNorm(this->getVec()))/(getDragConstant()*getInvElasticity());


}
SDL_FPoint Entity::getCenter(){

    float x=this->pos.x+this->body.w*0.5f;
    float y=this->pos.y+this->body.h*0.5f;
    return (SDL_FPoint){x,y};


}
    SDL_FPoint getCoords();
    void setCoords(SDL_FPoint point);
void Entity::setVec(SDL_FPoint coords){
this->moveVec->setCoords(coords);
}
Entity::~Entity(){
delete this->moveVec;
}



