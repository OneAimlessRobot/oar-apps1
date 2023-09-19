#include <SDL2/SDL.h>
#include <vector>
#include <list>
#include <string>
#include "TextBox.hpp"
#include "graphicalLib1.hpp"
#include"auxFunctions.h"
#include "Trail.hpp"


    Trail::Trail(float length,float width,float xInit,float yInit,SDL_Color color){
            this->currentX=xInit;
            this->currentY=yInit;
            this->trailPoints={};
            this->color=color;
            this->trailLength=length;
            this->trailThickness=width;


    }

    float Trail::getThickness(){
        return this->trailThickness;

    }
    void Trail::render(SDL_Renderer* renderer){

        if((this->getLength()>=this->trailLength)){

                trailPoints.erase(trailPoints.begin());


        }
            trailPoints.push_back(getCurrentPos());
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);

        graphicalLib1::drawThickLineFromPointVector(renderer,this->color,this->trailThickness,this->trailPoints);




    }
    SDL_FPoint Trail::getCurrentPos(){
            return (SDL_FPoint){this->currentX,this->currentY};
    }
    void Trail::setPos(float x,float y){
                this->currentX=x;
                this->currentY=y;
    }
    void Trail::setThickness(float value){

            this->trailThickness=value;
    }
    float Trail::getLength(){
        float result=0;
        if(trailPoints.size()<2){
        return 0;
        }
        for(std::iterator<std::vector<SDL_FPoint>> it= trailPoints.begin();it!=trailPoints.end();it++){

            result+=aux::distBetPoints((SDL_FPoint*)it,(SDL_FPoint*)(it+1));

        }
        return result;

    }
    Trail::~Trail(){


    }
