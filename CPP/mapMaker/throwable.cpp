#include <SDL2/SDL_image.h>
#include"Obstacle.hpp"
#include "LTexture.hpp"
#include "throwable.hpp"
#include "graphicalLib1.hpp"
#include<iostream>
#include "Trail.hpp"


Throwable::Throwable(SDL_Renderer* renderer,int x, int y, int width,int initSpeed,double coefficient,int r,int g ,int b, int a,int trailLength,int trailThickness,const char* imgPath,int value)
    {
        this->body=(SDL_Rect*)malloc(sizeof(SDL_Rect));
        if(this->body==(SDL_Rect*)NULL){

        std::cout<<"Could not create object body\n";
        return;
        }
        *(this->body)=(SDL_Rect){x,y,width,width};
        this->color=(SDL_Color){r,g,b,a};
        this->speed=initSpeed;
        this->coefficient=coefficient;
        this->boxes={};
        trail=new Trail(trailLength,trailLength,x+width*0.5,y+width*0.5,this->color);
        SDL_Surface* surface=IMG_Load(imgPath);
        if(!surface){
            std::cerr<<"Could not create surface\n";
            return;
        }
        this->texture=SDL_CreateTextureFromSurface(renderer,surface);
        if(!this->texture){
            std::cerr<<"Could not create texture\n";

            return;


        }
        this->value=value;
    }

    void Throwable::renderIteration(SDL_Renderer *ren)
    {
    this->trail->setPos(this->getPos().x+this->body->w*0.5,this->getPos().y+this->body->w*0.5);
    trail->render(ren);
    if(this->texture){

        SDL_RenderCopy(ren,this->texture,NULL,this->body);
    }
    else{

        SDL_SetRenderDrawColor(ren, this->color.r, this->color.g, this->color.b, 255);
        SDL_RenderFillRect(ren, this->body);
        }

    }
    void Throwable::setPos(int x, int y){
        this->body->x=x;
        this->body->y=y;
    }
    void Throwable::setValue(int value){

      this->value=value;


    }
    int Throwable::getValue(){

       return this->value;


    }
    SDL_Point Throwable::getPos(){
        return (SDL_Point){this->body->x,this->body->y};
    }
    SDL_Point Throwable::getTarget(){
        return (SDL_Point){this->target.x,this->target.y};
    }
    SDL_Rect* Throwable::getBody(){
        return this->body;
    }
    double Throwable::getCoefficient(){
        return this->coefficient;
    }
    void Throwable::shoot(){

        this->body->x += round(this->speed * cos(atan2(target.y - this->body->y , target.x - this->body->x)));
        this->body->y += round(this->speed * sin(atan2(target.y - this->body->y , target.x - this->body->x)));

    }
    int Throwable::getSize(){

            return this->body->w;
    }
    void Throwable::setDirection(int x0,int y0,int x1,int y1){
        this->target= (SDL_Point){round(2000 * cos(atan2(y1-y0, x1-x0))), round(2000 * sin(atan2(y1-y0, x1-x0)))};



    }
    void Throwable::addBox(Obstacle*obstacle){
        this->boxes.push_back(obstacle);
    }
    void Throwable::setTarget(int x,int y){
        this->target=(SDL_Point){x,y};
    }
    SDL_Color Throwable::getColor(){
        return this->color;
    }
    int Throwable::getSpeed(){
        return this->speed;
    }
    void Throwable::setSpeed(int value){

        this->speed=value;

    }
    int Throwable::ricochete(){

        for(Obstacle *thing:this->boxes){
        if(!(thing->getHitBoxType())){
//LEFT

                if(thing->boxHitLeft(this->body)){
                    this->setPos(thing->getCorePos().x+1,this->getPos().y);
                    this->setTarget(-this->getTarget().x,this->getTarget().y);
                    this->setSpeed(this->getSpeed()-ceil(this->getSpeed()/this->getCoefficient()));
                    return 1;
                }
                //RIGHT
                else if(thing->boxHitRight(this->body)){
                    this->setPos(thing->getCorePos().x+thing->getInnerWidth()-1-this->body->w,this->getPos().y);
                    this->setTarget(-this->getTarget().x,this->getTarget().y);
                    this->setSpeed(this->getSpeed()-ceil(this->getSpeed()/this->getCoefficient()));
                    return 1;

                }
                //DOWN
                else if(thing->boxHitDown(this->body)){
                    this->setPos(this->getPos().x,thing->getCorePos().y+thing->getInnerHeight()-1-this->body->h);
                    this->setTarget(this->getTarget().x,-this->getTarget().y);
                    this->setSpeed(this->getSpeed()-ceil(this->getSpeed()/this->getCoefficient()));
                    return 1;
                }
                else if(thing->boxHitUp(this->body)){
                    this->setPos(this->getPos().x,thing->getCorePos().y+1);
                    this->setTarget(this->getTarget().x,-this->getTarget().y);
                    this->setSpeed(this->getSpeed()-ceil(this->getSpeed()/this->getCoefficient()));
                    return 1;
                }
            }
            else if(thing->getHitBoxType()){
//////////////////////////////   __
////////////////////////////// _/  \
//////////////////////////////|   $$
////////////////////////////// \$$$$
//////////////////////////////  | $$
//////////////////////////////  | $$
////////////////////////////// _| $$_
//////////////////////////////|   $$ \
////////////////////////////// \$$$$$$
                if(thing->boxHitLeft(this->body)){
                    this->setPos(thing->getShellPos().x-this->body->w-1,this->getPos().y);
                    this->setTarget(-this->getTarget().x,this->getTarget().y);
                    this->setSpeed(this->getSpeed()-ceil(this->getSpeed()/this->getCoefficient()));
                    return 1;
                }

//////////////////////////////  ______
////////////////////////////// /      \
//////////////////////////////|  $$$$$$\
////////////////////////////// \$$__| $$
////////////////////////////// /      $$
//////////////////////////////|  $$$$$$
//////////////////////////////| $$_____
//////////////////////////////| $$     \
////////////////////////////// \$$$$$$$$
                else if(thing->boxHitDown(this->body)){
                    this->setPos(this->getPos().x,thing->getOuterHeight()+thing->getShellPos().y+1);
                    this->setTarget(this->getTarget().x,-this->getTarget().y);
                    this->setSpeed(this->getSpeed()-ceil(this->getSpeed()/this->getCoefficient()));
                    return 1;

                }
//////////////////////////////  ______
////////////////////////////// /      \
//////////////////////////////|  $$$$$$\
////////////////////////////// \$$__| $$
//////////////////////////////  |     $$
////////////////////////////// __\$$$$$\
//////////////////////////////|  \__| $$
////////////////////////////// \$$    $$
//////////////////////////////  \$$$$$$
                else if(thing->boxHitUp(this->body)){
                    this->setPos(this->getPos().x,thing->getShellPos().y-this->body->h-1);
                    this->setTarget(this->getTarget().x,-this->getTarget().y);
                    this->setSpeed(this->getSpeed()-ceil(this->getSpeed()/this->getCoefficient()));
                    return 1;
                }


//////////////////////////// __    __
////////////////////////////|  \  |  \
////////////////////////////| $$  | $$
////////////////////////////| $$__| $$
////////////////////////////| $$    $$
//////////////////////////// \$$$$$$$$
////////////////////////////      | $$
////////////////////////////      | $$
////////////////////////////       \$$
                else if(thing->boxHitRight(this->body)){
                    this->setPos(thing->getShellPos().x+thing->getOuterWidth()+1,this->getPos().y);
                    this->setTarget(-this->getTarget().x,this->getTarget().y);
                    this->setSpeed(this->getSpeed()-ceil(this->getSpeed()/this->getCoefficient()));
                    return 1;
                }
            }
            }
            return 0;


    }

    void Throwable::removeAllBoxes(){

        for(Obstacle* thing: boxes){

            boxes.pop_back();
        }

    }
    int Throwable::getNumOfBoxes(){
        return this->boxes.size();
    }
    SDL_Point Throwable::getCenter(){
        return (SDL_Point){this->getPos().x+this->body->w/2,this->getPos().y+this->body->w/2};

    }


    Throwable::~Throwable(){

        free(this->body);
        SDL_DestroyTexture(this->texture);
        delete(trail);

    }

