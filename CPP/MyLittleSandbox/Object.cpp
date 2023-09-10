#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "LTexture.hpp"
#include "Trail.hpp"
#include "Object.hpp"


//
//
//class Object{
//
//
//
//    SDL_Color color;
//    SDL_Rect *body;
//    LTexture* texture;
//    Trail*trail;
//    float DCoefficient;
//public:

    Object::Object(SDL_Renderer* renderer,float x,float y, float width,float trailLength,float trailThickness,SDL_Color color,const char* imgPath,float DCoefficient){

        this->body=(SDL_FRect*)malloc(sizeof(SDL_FRect));
        *(this->body)=(SDL_FRect){x,y,width,width};
//        this->trail=new Trail(trailLength,trailThickness,(int)(x+width*0.5),(int)(y+width*0.5),color);
        this->texture=new LTexture(renderer,x,y,width,width,imgPath);
        this->color=color;
        this->DCoefficient=DCoefficient;

    }
    void Object::setPos(float x, float y){

        this->body->x=x;
        this->body->y=y;
        this->texture->setXPos(x);
        this->texture->setYPos(y);

    }
    SDL_FPoint Object::getPos(){
        return (SDL_FPoint){this->body->x,this->body->y};

    }
    SDL_FPoint Object::getCenter(){
        return (SDL_FPoint){this->body->x+this->getSize()*0.5,this->body->y+this->getSize()*0.5};
    }
    SDL_FRect* Object::getBody(){
        return this->body;
    }
    float Object::getSize(){

        return this->body->w;
    }
    float Object::getDCoefficient(){
        return this->DCoefficient;
    }
    void Object::setDCoefficient(float value){
        this->DCoefficient=value;
    }
    SDL_Color Object::getColor(){

        return this->color;
    }
    void Object::render(SDL_Renderer *renderer){

//
//    this->trail->setPos(this->getCenter().x,this->getCenter().y);
//    trail->render(renderer);
    if(this->texture){

        this->texture->render(renderer);
    }
    else{

        SDL_SetRenderDrawColor(renderer, this->color.r, this->color.g, this->color.b, 255);
        SDL_RenderFillRectF(renderer, this->body);
        }



    }
    Object::~Object(){

        free(body);
        delete(texture);
//        delete(trail);

    }

