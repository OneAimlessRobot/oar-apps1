#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include"LTexture.hpp"
#include <vector>
#include "Menu.hpp"
#include <string>
#include <iostream>
#include "auxFunctions.h"
#include "graphicalLib1.hpp"
#include "GeometricVector.hpp"
#include "Trail.hpp"
#include "Object.hpp"
#include "Obstacle.hpp"
#include "throwable.hpp"
#include "ForceField.hpp"


    ForceField::ForceField(SDL_Renderer* renderer,int x,int y, int width,int trailLength,int trailThickness,SDL_Color color,const char* imgPath,double DCoefficient,int dX,int dY,int magnitude):Object(renderer,x,y,width, trailLength, trailThickness,color,imgPath,DCoefficient){

        this->forceVec=new GeometricVector<int>(x,y,dX,dY,positive,magnitude);

    }

    void ForceField::addBody(Throwable* throwable){

        bodies.push_back(throwable);
    }

    void ForceField::updateVectors(){

        for(Throwable* body:bodies){
        if(SDL_HasIntersection(this->getBody(),body->getBody())){

            body->setVector(body->getVector()->add(this->forceVec));
            }

        }
    }

    void ForceField::removeBodies(){

            for(Throwable *body:bodies){
                bodies.pop_back();
            }
    }

    ForceField::~ForceField(){

    delete(forceVec);
    removeBodies();


    }
