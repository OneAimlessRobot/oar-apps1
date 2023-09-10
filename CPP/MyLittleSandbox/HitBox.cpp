#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<vector>
#include<iostream>
#include"HitBox.hpp"



    HitBox::HitBox(float x,float y, float w, float h, float thickness,int type){
    this->x=x;
    this->y=y;
    this->type=type;
    this->thickness=thickness;

            this->left=(SDL_FRect*)malloc(sizeof(SDL_FRect));
            this->up=(SDL_FRect*)malloc(sizeof(SDL_FRect));
            this->right=(SDL_FRect*)malloc(sizeof(SDL_FRect));
            this->down=(SDL_FRect*)malloc(sizeof(SDL_FRect));


            *(this->left)= (SDL_FRect){x,y+thickness,thickness,h-(2*thickness)};
            *(this->up)=(SDL_FRect){left->x+thickness,left->y-thickness,w-(2*thickness),thickness};
            *(this->right)=(SDL_FRect){up->x+up->w,up->y+thickness,thickness,h-(2*thickness)};
            *(this->down)=(SDL_FRect){right->x-up->w,right->y+right->h,w-(2*thickness),thickness};


    }
    int HitBox::getType(){
        return this->type;
    }
    void HitBox::setPos(float newX,float newY){

            this->left->x=newX;
            this->left->y=newY+thickness;
            this->up->x=this->left->x+thickness;
            this->up->y=this->left->y-thickness;
            this->right->x=this->up->x+this->up->w;
            this->right->y=this->up->y+thickness;
            this->down->x=this->right->x-this->up->w;
            this->down->y=this->right->y+this->right->h;

    }
    void HitBox::setInnerWidth(float value){
            if(value<0){
                value=0;
            }

            this->up->w=value;
            this->down->w=value;
            this->right->x=up->x+up->w;


    }
    void HitBox::setInnerHeight(float value){
            if(value<0){
                value=0;
            }
            this->left->h=value;
            this->right->h=value;
            this->down->y=left->y+left->h;

    }
    float HitBox::getThickness(){
        return this->thickness;
    }
    float HitBox::getOuterWidth(){
        return this->up->w+2*thickness;
    }
    float HitBox::getInnerWidth(){
            return this->up->w;
    }
    float HitBox::getOuterHeight(){

            return this->left->h+2*thickness;

    }
    float HitBox::getInnerHeight(){
            return this->left->h;
    }
    SDL_FPoint HitBox::getPos(){

        return (SDL_FPoint){this->x,this->y};
    }
    int HitBox::hitLeft(const SDL_FRect* rect){
            return SDL_HasIntersectionF(this->left,rect);
    }
    int HitBox::hitRight(const SDL_FRect* rect){
            return SDL_HasIntersectionF(this->right,rect);
    }
    int HitBox::hitUp(const SDL_FRect* rect){
            return SDL_HasIntersectionF(this->up,rect);
    }
    int HitBox::hitDown(const SDL_FRect* rect){
            return SDL_HasIntersectionF(this->down,rect);
    }
    void HitBox::render(SDL_Renderer *renderer){
        SDL_FRect *rect=(SDL_FRect*)malloc(sizeof(SDL_FRect));
        (*rect)=(SDL_FRect){this->getPos().x,this->getPos().y,this->getOuterWidth(),this->getOuterHeight()};
        SDL_SetRenderDrawColor(renderer,100,100,100,255);
        SDL_RenderFillRectF(renderer,this->left);
        SDL_RenderFillRectF(renderer,this->right);
        SDL_RenderFillRectF(renderer,this->up);
        SDL_RenderFillRectF(renderer,this->down);
        SDL_SetRenderDrawColor(renderer,255,0,255,255);
        SDL_RenderFillRectF(renderer,rect);
        free(rect);

    }
    HitBox::~HitBox(){
        free(this->left);
        free(this->right);
        free(this->up);
        free(this->down);
    }

