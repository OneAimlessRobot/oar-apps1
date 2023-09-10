#include<SDL2/SDL.h>
#include<vector>
#include<iostream>
#include"HitBox.hpp"



    HitBox::HitBox(int x,int y, int w, int h, int thickness,int type){
    this->x=x;
    this->y=y;
    this->type=type;
    this->thickness=thickness;

            this->left=(SDL_Rect*)malloc(sizeof(SDL_Rect));
            this->up=(SDL_Rect*)malloc(sizeof(SDL_Rect));
            this->right=(SDL_Rect*)malloc(sizeof(SDL_Rect));
            this->down=(SDL_Rect*)malloc(sizeof(SDL_Rect));


            *(this->left)= (SDL_Rect){x,y+thickness,thickness,h-(2*thickness)};
            *(this->up)=(SDL_Rect){left->x+thickness,left->y-thickness,w-(2*thickness),thickness};
            *(this->right)=(SDL_Rect){up->x+up->w,up->y+thickness,thickness,h-(2*thickness)};
            *(this->down)=(SDL_Rect){right->x-up->w,right->y+right->h,w-(2*thickness),thickness};


    }
    int HitBox::getType(){
        return this->type;
    }
    void HitBox::setPos(int newX,int newY){

            this->left->x=newX;
            this->left->y=newY+thickness;
            this->up->x=this->left->x+thickness;
            this->up->y=this->left->y-thickness;
            this->right->x=this->up->x+this->up->w;
            this->right->y=this->up->y+thickness;
            this->down->x=this->right->x-this->up->w;
            this->down->y=this->right->y+this->right->h;

    }
    void HitBox::setInnerWidth(int value){
            if(value<0){
                value=0;
            }

            this->up->w=value;
            this->down->w=value;
            this->right->x=up->x+up->w;


    }
    void HitBox::setInnerHeight(int value){
            if(value<0){
                value=0;
            }
            this->left->h=value;
            this->right->h=value;
            this->down->y=left->y+left->h;

    }
    int HitBox::getThickness(){
        return this->thickness;
    }
    int HitBox::getOuterWidth(){
        return this->up->w+2*thickness;
    }
    int HitBox::getInnerWidth(){
            return this->up->w;
    }
    int HitBox::getOuterHeight(){

            return this->left->h+2*thickness;

    }
    int HitBox::getInnerHeight(){
            return this->left->h;
    }
    SDL_Point HitBox::getPos(){

        return (SDL_Point){this->x,this->y};
    }
    int HitBox::hitLeft(const SDL_Rect* rect){
            return SDL_HasIntersection(this->left,rect);
    }
    int HitBox::hitRight(const SDL_Rect* rect){
            return SDL_HasIntersection(this->right,rect);
    }
    int HitBox::hitUp(const SDL_Rect* rect){
            return SDL_HasIntersection(this->up,rect);
    }
    int HitBox::hitDown(const SDL_Rect* rect){
            return SDL_HasIntersection(this->down,rect);
    }
    void HitBox::render(SDL_Renderer *renderer){
        SDL_Rect *rect=(SDL_Rect*)malloc(sizeof(SDL_Rect));
        (*rect)=(SDL_Rect){this->getPos().x,this->getPos().y,this->getOuterWidth(),this->getOuterHeight()};
        SDL_SetRenderDrawColor(renderer,100,100,100,255);
        SDL_RenderFillRect(renderer,this->left);
        SDL_RenderFillRect(renderer,this->right);
        SDL_RenderFillRect(renderer,this->up);
        SDL_RenderFillRect(renderer,this->down);
        SDL_SetRenderDrawColor(renderer,255,0,255,255);
        SDL_RenderFillRect(renderer,rect);
        free(rect);

    }
    HitBox::~HitBox(){
        free(this->left);
        free(this->right);
        free(this->up);
        free(this->down);
    }

