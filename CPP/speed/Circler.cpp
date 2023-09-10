#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include <iostream>
#include "Trail.hpp"
#include "graphicalLib1.hpp"
#include "Circler.hpp"


    Circler::Circler(SDL_Renderer*renderer,int xInit,int yInit,int size,int speedInit,const char* imagePath,SDL_Color color,int trailW,int trailL,int radius,int precision){

        this->radius=radius;
        this->xCenter=xInit;
        this->yCenter=yInit;
        this->x=this->xCenter+radius;
        this->y=this->yCenter;
        this->precision=precision;
        this->counter=new clockCounter(0,3,1);
        this->size=size;
        this->body=(SDL_Rect*)malloc(sizeof(SDL_Rect));
        (*this->body)=(SDL_Rect){this->x,this->y,this->size,this->size};
        this->speed=speedInit;
        this->imagePath=imagePath;
        SDL_Surface* surface=IMG_Load(imagePath);
        if(!surface){
            std::cerr<<"Unable to initialize surface\n";
            return;
        }
        this->texture=SDL_CreateTextureFromSurface(renderer,surface);
        if(!texture){

            std::cerr<<"Unable to initialize texture\n";
            return;

        }
        this->trail=new Trail(trailL,trailW,this->x,this->y,color);
        if(!trail){
            std::cerr<<"Unable to initialize trail\n";
            return;
        }


    }

    void Circler::parametricEquationCalculation(){
        double newX=this->radius*cos((counter->getCurrent()*(M_PI/this->precision)))+this->xCenter;
        double newY=this->radius*sin((counter->getCurrent()*(M_PI/this->precision)))+this->yCenter;
        this->setPos(round(newX),round(newY));

        counter->setCurrent(counter->getCurrent()+this->speed);



    }

    void Circler::setPos(int x,int y){

            this->x=x;
            this->y=y;
            this->body->x=x;
            this->body->y=y;

    }
    SDL_Point Circler::getPos(){

            return (SDL_Point){this->x,this->y};
    }

    void Circler::setCenter(int x,int y){

            this->xCenter=x;
            this->yCenter=y;

    }
    SDL_Point Circler::getCenter(){

            return (SDL_Point){this->xCenter,this->yCenter};
    }


    void Circler::render(SDL_Renderer *renderer){

    trail->setPos(this->getPos().x+this->size*0.5,this->getPos().y+this->size*0.5);
    trail->render(renderer);
            SDL_RenderCopy(renderer,this->texture,NULL,this->body);

    }
    int Circler::getSize(){

        return this->body->w;
    }

    Circler::~Circler(){
        SDL_DestroyTexture(this->texture);
        free(body);
        delete(counter);
        delete(trail);

    }
