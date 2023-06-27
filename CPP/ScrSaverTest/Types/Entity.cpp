
#include <SDL2/SDL.h>
#include "../aux.h"
#include <vector>
#include <iterator>
#include <iostream>
#include "GVector.h"
#include "Entity.h"
#include "Collider.h"
#include "physicsAux.h"

Entity::Entity(SDL_Color clr,float x, float y, float w, float h,float e, float m,float Car){

    this->bodyColor=clr;
    this->body=(SDL_FRect){x,y,w,h};
    this->pos=(SDL_FPoint){x,y};
    this->moveVec= new GVector(0,0);
    this->lastVec= new GVector(0,0);
    this->lastPositions={};
    this->elasticity=e;
    this->mass=m;
    this->Car=Car;


}
void Entity::render(SDL_Renderer*ren){
    SDL_SetRenderDrawColor(ren,this->bodyColor.r,this->bodyColor.g,this->bodyColor.b,this->bodyColor.a);
    SDL_RenderFillRectF(ren,&this->body);

    for(SDL_FPoint point: this->lastPositions){
        SDL_RenderDrawPointF(ren,point.x,point.y);
    }
        SDL_FRect rect=(SDL_FRect){this->getLastPos().x,this->getLastPos().y,this->body.x*0.01,this->body.y*0.01};
        SDL_RenderFillRectF(ren,&rect);
}
void Entity::setPos(SDL_FPoint point){

    this->lastPos=pos;
    this->pos=point;
    this->body.x=point.x;
    this->body.y=point.y;

}
SDL_FPoint Entity::getPos(){

    return this->pos;

}
float Entity::getDragConstant(){

    return this->body.w*this->Car*0.001;
}
SDL_FPoint Entity::getLastPos(){

    if(this->lastPositions.empty()){
        return pos;
    }
//    std::vector<SDL_FPoint>::iterator it;
//
//        std::cout<<"Pontos na stack:\n";
//    for (it = this->lastPositions.begin(); it != this->lastPositions.end(); ++it) {
//
//        std::cout<<"( "<<(*it).x<<" , "<<(*it).y<<" )\n";
//    }
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
float Entity::getSpeedLoss(){
    float vel= this->getVec()->getNorm();
    float currEnergy=this->mass*vel*vel;



}
float Entity::getElasticity(){

    return this->elasticity;
}
float Entity::getMass(){
 return this->mass;
}
void Entity::bounce(){
    float newSpeed=PhysicsAux::getReboundSpeed(this->getVec()->getNorm(),this->elasticity);
    GVector* newVector=Aux::makeUnitVector((SDL_FPoint){0,0},(SDL_FPoint){this->moveVec->getX(),this->moveVec->getY()});
    Aux::scaleVec(newVector,newSpeed);
    this->moveVec=newVector;

}

Entity* Entity::randEnt(float width, float height,float maxMass,float maxSize,float maxSpeed){
float size= Aux::getRandomFloat(10,maxSize);
float x= Aux::getRandomFloat(0,width-size);
float y=Aux::getRandomFloat(0,height-size);
float maxAngle=Aux::getRandomFloat(0,2*3.14159);
float e=Aux::getRandomFloat(0,1);
float newMass=Aux::getRandomFloat(0,maxMass);
float coeffOfAirR=Aux::getRandomFloat(0,1);
float dx= std::cos(maxAngle);
float dy=std::sin(maxAngle);
float speed=Aux::getRandomFloat(maxSpeed,maxSpeed);
SDL_Color color= Aux::randColor();
GVector* resmoveVec= Aux::makeUnitVector((SDL_FPoint){x,y},(SDL_FPoint){x+dx,y+dy});
Aux::scaleVec(resmoveVec,speed);
Entity* result=new Entity(color,x,y,size,size,1-e,newMass,coeffOfAirR);
result->setVec(resmoveVec);
return result;


}
GVector* Entity::getVec(){

return this->moveVec;
}
SDL_FRect Entity::getBody(){

    return (this->body);
}
float Entity::getRadius(){

    return this->body.w*0.5;

}

float Entity::getQuality(){
//quanto mais pequeno "e", melhor
    return (getVec()->getNorm())/(getDragConstant()*getElasticity());


}
SDL_FPoint Entity::getCenter(){

    float x=this->pos.x+this->body.w*0.5;
    float y=this->pos.y+this->body.h*0.5;
    return (SDL_FPoint){x,y};


}
void Entity::setVec(GVector * vec){
delete this->moveVec;
this->moveVec=vec;
}
Entity::~Entity(){
delete this->moveVec;
}



