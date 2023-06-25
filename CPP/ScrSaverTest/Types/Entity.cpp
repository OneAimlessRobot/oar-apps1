
#include <SDL2/SDL.h>
#include "../aux.h"
#include "GVector.h"
#include "Entity.h"

Entity::Entity(SDL_Color clr,float x, float y, float w, float h){

    this->bodyColor=clr;
    this->body=(SDL_FRect){x,y,w,h};
    this->pos=(SDL_FPoint){x,y};
    this->moveVec= new GVector(0,0);


}
void Entity::render(SDL_Renderer*ren){
    SDL_SetRenderDrawColor(ren,this->bodyColor.r,this->bodyColor.g,this->bodyColor.b,this->bodyColor.a);
    SDL_RenderFillRectF(ren,&this->body);

}
void Entity::setPos(SDL_FPoint point){

    this->lastPos=pos;
    this->pos=point;

}
SDL_FPoint Entity::getPos(){

    return this->pos;

}
SDL_FPoint Entity::getLastPos(){

    return this->lastPos;

}
void Entity::translate(){
    this->lastPos=pos;
    this->pos.x+=this->moveVec->getX();
    this->pos.y+=this->moveVec->getY();
    this->body.x+=this->moveVec->getX();
    this->body.y+=this->moveVec->getY();

}

Entity* Entity::randEnt(float width, float height,float maxSize,float maxSpeed){

float size= Aux::getRandomFloat(10,maxSize);
float x= Aux::getRandomFloat(0,width-size);
float y=Aux::getRandomFloat(0,height-size);
float dx= Aux::getRandomFloat(0,maxSpeed);
float dy=Aux::getRandomFloat(0,maxSpeed);
SDL_Color color= Aux::randColor();
GVector* resmoveVec= new GVector(dx,dy);
Entity* result=new Entity(color,x,y,size,size);
result->setVec(resmoveVec);
return result;


}
GVector* Entity::getVec(){

return this->moveVec;
}
SDL_FRect Entity::getBody(){

    return (this->body);
}

void Entity::setVec(GVector * vec){
delete this->moveVec;
this->moveVec=vec;
}
Entity::~Entity(){

delete this->moveVec;
}



