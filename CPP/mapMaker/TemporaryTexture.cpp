#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "graphicalLib1.hpp"
#include "TemporaryTexture.hpp"
#include <iostream>



    TemporaryTexture::TemporaryTexture(int x, int y, int w, int h, SDL_Texture *texture, int ticks){
    this->rect=(SDL_Rect*)malloc(sizeof(SDL_Rect));
    (*this->rect)=(SDL_Rect){x,y,w,h};
    this->counter=new clockCounter(1,ticks,0);
    this->texture=texture;


    }

    TemporaryTexture::TemporaryTexture(SDL_Renderer*renderer,int x, int y, int w, int h,const char* pathToImg, int ticks){

    this->rect=(SDL_Rect*)malloc(sizeof(SDL_Rect));
    (*this->rect)=(SDL_Rect){x,y,w,h};
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

    TemporaryTexture::TemporaryTexture(SDL_Renderer*renderer,int x, int y, int w, int h,const char* pathToImg, int ticks,int uselessValue){

    this->rect=(SDL_Rect*)malloc(sizeof(SDL_Rect));
    (*this->rect)=(SDL_Rect){x,y,w,h};
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

    void TemporaryTexture::setXPos(int value){
    this->rect->x=value;
    }
    void TemporaryTexture::setYPos(int value){
    this->rect->y=value;

    }
    SDL_Point TemporaryTexture::getPos(){

        return (SDL_Point){this->rect->x,this->rect->y};



    }
    void TemporaryTexture::render(SDL_Renderer* renderer){
        if(this->counter->getCurrent()){
            if(this->texture){

                SDL_RenderCopy(renderer,this->texture,NULL,this->rect);
                increment();
            }
            else{
                SDL_SetRenderDrawColor(renderer,255,0,255,255);
                SDL_RenderFillRect(renderer,this->rect);
                increment();

            }
        }

    }
    void TemporaryTexture::increment(){
        this->counter->increment();

    }
    int TemporaryTexture::getWidth(){

        return this->rect->w;
    }
    int TemporaryTexture::getHeight(){

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


