#include "../aux.h"
#include <SDL2/SDL.h>
#include "Collider.h"


Collider::Collider(SDL_bool type,SDL_Color color,float x,float y,float w,float h,float thickness){

this->left=(SDL_FRect){-thickness,0,thickness,h};
this->right=(SDL_FRect){w,0,thickness,h};
this->top=(SDL_FRect){0,-thickness,w,thickness};
this->bottom=(SDL_FRect){0,h,w,thickness};
this->containedObject=(SDL_FRect){0,0,w,h};
this->bodyColor = color;



}
void Collider::fullRender(SDL_Renderer* ren){

    SDL_SetRenderDrawColor(ren,this->bodyColor.r,this->bodyColor.g,this->bodyColor.b,this->bodyColor.a);
    SDL_RenderFillRectF(ren,&this->containedObject);

    SDL_SetRenderDrawColor(ren,0,0,0,255);
    SDL_FRect  rlist[]= {left,right,top,bottom};
    SDL_RenderFillRectsF(ren,rlist,4);
    SDL_RenderPresent(ren);


}
void Collider::render(SDL_Renderer* ren){


    SDL_SetRenderDrawColor(ren,this->bodyColor.r,this->bodyColor.g,this->bodyColor.b,this->bodyColor.a);
    SDL_RenderFillRectF(ren,&this->containedObject);
    SDL_RenderPresent(ren);



}
int Collider::whereIsColliding(SDL_FRect rect){

    if(SDL_HasIntersectionF(&rect,&this->left)){

        return 1;

    }
    else if(SDL_HasIntersectionF(&rect,&this->right)){

        return 2;

    }
    else if(SDL_HasIntersectionF(&rect,&this->top)){

        return 3;

    }
    else if(SDL_HasIntersectionF(&rect,&this->bottom)){

        return 4;

    }

    else{

        return 0;

    }




}

