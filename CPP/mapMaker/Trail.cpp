#include "Trail.hpp"
#include "graphicalLib1.hpp"
#include <iostream>


    Trail::Trail(int length,int width,int xInit,int yInit,SDL_Color color){
            this->currentX=xInit;
            this->currentY=yInit;
            this->trailPoints={};
            this->color=color;
            this->trailLength=length;
            this->trailThickness=width;


    }

    int Trail::getThickness(){
        return this->trailThickness;

    }
    void Trail::render(SDL_Renderer* renderer){

        trailPoints.push_back(getCurrentPos());
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);

        graphicalLib1::drawThickLineFromPointVector(renderer,this->color,this->trailThickness,this->trailPoints);
        if(trailPoints.size()>this->trailLength){
            this->trailPoints.erase(this->trailPoints.begin());
        }



    }
    SDL_Point Trail::getCurrentPos(){
            return (SDL_Point){this->currentX,this->currentY};
    }
    void Trail::setPos(int x, int y){
                this->currentX=x;
                this->currentY=y;
    }
    void Trail::setThickness(int value){

            this->trailThickness=value;
    }
    Trail::~Trail(){


    }
