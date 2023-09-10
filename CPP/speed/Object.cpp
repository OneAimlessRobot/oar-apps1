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
//    double DCoefficient;
//public:

    Object::Object(SDL_Renderer* renderer,double x,double y, double width,double trailLength,double trailThickness,SDL_Color color,const char* imgPath,double DCoefficient){

        this->body=(SDL_FRect*)malloc(sizeof(SDL_FRect));
        *(this->body)=(SDL_Rect){x,y,width,width};
//        this->trail=new Trail(trailLength,trailThickness,(int)(x+width*0.5),(int)(y+width*0.5),color);
        this->texture=new LTexture(renderer,x,y,width,width,imgPath);
        this->color=color;
        this->DCoefficient=DCoefficient;

    }
    void Object::setPos(int x, int y){

        this->body->x=x;
        this->body->y=y;
        this->texture->setXPos(x);
        this->texture->setYPos(y);

    }
    SDL_Point Object::getPos(){
        return (SDL_Point){this->body->x,this->body->y};

    }
    SDL_Point Object::getCenter(){
        return (SDL_Point){this->body->x+(int)(this->getSize()*0.5),this->body->y+(int)(this->getSize()*0.5)};
    }
    SDL_Rect* Object::getBody(){
        return this->body;
    }
    int Object::getSize(){

        return this->body->w;
    }
    double Object::getDCoefficient(){
        return this->DCoefficient;
    }
    void Object::setDCoefficient(double value){
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
        SDL_RenderFillRect(renderer, this->body);
        }



    }
    Object::~Object(){

        free(body);
        delete(texture);
//        delete(trail);

    }

