#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "LTexture.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "TextBox.hpp"
#include "auxFunctions.h"
#include "graphicalLib1.hpp"
#include "GeometricVector.hpp"
#include "Trail.hpp"
#include "Object.hpp"
#include "Obstacle.hpp"
#include "throwable.hpp"
#include "ForceField.hpp"


    ForceField::ForceField(SDL_Renderer* renderer,float x,float y, float width,float trailLength,float trailThickness,SDL_Color color,const char* imgPath,float DCoefficient,float dX,float dY,float magnitude):Object(renderer,x,y,width, trailLength, trailThickness,color,imgPath,DCoefficient){

        this->forceVec=new GeometricVector<float>(x,y,dX,dY,positive,magnitude);

    }

    void ForceField::addBody(Throwable* throwable){

        bodies.push_back(throwable);
    }

    void ForceField::updateVectors(){

        for(Throwable* body:bodies){
        if(SDL_HasIntersectionF(this->getBody(),body->getBody())){

            body->setVector(body->getVector()->add(this->forceVec));
            }

        }
    }

    void ForceField::removeBodies(){
            int finished= bodies.size();
            for(int i=0;i<finished;i++){
                bodies.pop_back();
            }
    }

    ForceField::~ForceField(){

    delete(forceVec);
    removeBodies();


    }
