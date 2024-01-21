#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "../Includes/graphicalLib1.hpp"
#include "../Includes/TemporaryTexture.hpp"
#include <iostream>



    TemporaryTexture::TemporaryTexture(float x, float y, float w, float h, SDL_Texture *texture, int ticks){
    this->rect=(SDL_FRect*)malloc(sizeof(SDL_FRect));
    (*this->rect)=(SDL_FRect){x,y,w,h};
    this->counter=new clockCounter(1,ticks,0);
    this->texture=texture;


    }

    TemporaryTexture::TemporaryTexture(SDL_Renderer*renderer,float x, float y, float w, float h,const char* pathToImg, int ticks){

    this->rect=(SDL_FRect*)malloc(sizeof(SDL_FRect));
    (*this->rect)=(SDL_FRect){x,y,w,h};
    this->counter=new clockCounter(1,ticks,0);
    SDL_Surface*surface=IMG_Load(pathToImg);
    if(!surface){

            std::cout<<"Could not create surfaceaaaaaaaa\n"<<pathToImg<<"\n";
            return;

    }
    this->texture=SDL_CreateTextureFromSurface(renderer,surface);
    if(!texture){

        std::cerr<<"Could not create texture\n";
        return;

    }
    SDL_FreeSurface(surface);


    }

    TemporaryTexture::TemporaryTexture(SDL_Renderer*renderer,float x, float y, float w, float h,const char* pathToImg, int ticks,int uselessValue){

    this->rect=(SDL_FRect*)malloc(sizeof(SDL_FRect));
    (*this->rect)=(SDL_FRect){x,y,w,h};
    this->counter=new clockCounter(1,ticks,0);
    SDL_Surface*surface=IMG_Load(pathToImg);
    if(!surface){
            return;

    }
    this->texture=SDL_CreateTextureFromSurface(renderer,surface);
    if(!texture){

        std::cerr<<"Could not create texture\n";
        return;

    }
    SDL_FreeSurface(surface);


    }

    void TemporaryTexture::setXPos(float value){
    this->rect->x=value;
    }
    void TemporaryTexture::setYPos(float value){
    this->rect->y=value;

    }
    SDL_FPoint TemporaryTexture::getPos(){

        return (SDL_FPoint){this->rect->x,this->rect->y};



    }
    void TemporaryTexture::render(SDL_Renderer* renderer){
        if(this->counter->getCurrent()){
            if(this->texture){

                SDL_RenderCopyF(renderer,this->texture,NULL,this->rect);
                increment();
            }
            else{
                SDL_SetRenderDrawColor(renderer,255,0,255,255);
                SDL_RenderFillRectF(renderer,this->rect);
                increment();

            }
        }

    }
    void TemporaryTexture::increment(){
        this->counter->increment();

    }
    float TemporaryTexture::getWidth(){

        return this->rect->w;
    }
    float TemporaryTexture::getHeight(){

        return this->rect->h;
    }
    void TemporaryTexture::reset(){
        this->counter->setCurrent(1);

    }
    int TemporaryTexture::getMaxTicks(){
        return this->counter->getModulus();

    }
    int TemporaryTexture::getCurrentValue(){
        return this->counter->getCurrent();

    }

    TemporaryTexture::~TemporaryTexture(){
    free(this->rect);
    delete(this->counter);
    SDL_DestroyTexture(this->texture);


    }


