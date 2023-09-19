#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>
#include "Obstacle.hpp"
#include "LTexture.hpp"
#include "Object.hpp"
#include "TextBox.hpp"
#include "graphicalLib1.hpp"
#include "auxFunctions.h"
#include "GeometricVector.hpp"
#include "throwable.hpp"
#include "FluidLayer.hpp"

    FluidLayer::FluidLayer(SDL_Renderer*renderer,float x,float y, float w, float h, float thickness,int type,SDL_Color color,const char* path,float density):Obstacle(renderer,x,y,w,h,thickness,type,color,path){

        this->bodies={};
        this->density=density;

    }

    float  FluidLayer::getDensity(){
        return this->density;
    }
    void  FluidLayer::addThrowable(Throwable*throwable){

        this->bodies.push_back(throwable);
    }
    void  FluidLayer::updateVectors(){
        for(Throwable*thing:bodies){
                GeometricVector<float>* accel=new GeometricVector<float>(thing->getCenter().x,thing->getCenter().y,thing->getVector()->getDx(),thing->getVector()->getDy(),positive,-ceil(getFluidDragOnBody(thing->getVector()->getLength(),thing->getDCoefficient(),thing->getSize())));



           thing->setVector(thing->getVector()->add(accel));
        }
    }
    float FluidLayer::getFluidDragOnBody(float speed,float DCoefficient,float area){

            return speed*speed*this->getDensity()*DCoefficient*area*0.001;
    }
    void FluidLayer::removeThrowables(){

            int finished= bodies.size();
            for(int i=0;i<finished;i++){
                bodies.pop_back();
            }
    }
//    int FluidLayer::getVecDx(){
//        return this->flowVec->getDx();
//    }
//    int FluidLayer::getVecDy(){
//        return this->flowVec->getDy();
//    }
//    int FluidLayer::getFluidSpeed(){
//        return this->flowVec->getLength();
//    }
     FluidLayer::~FluidLayer(){


     }


//      Para caso um dia eu descubra como isto funciona
//            GeometricVector*accel;
//            float accelX=getFluidDragOnBody(thing->getVector()->getXLength()-this->flowVec->getXLength(),thing->getDCoefficient(),thing->getSize());
//            float accelY=getFluidDragOnBody(thing->getVector()->getYLength()-this->flowVec->getYLength(),thing->getDCoefficient(),thing->getSize());
//            float accelLength=sqrt(accelX*accelX+accelY*accelY);
//            else{
//                accel=new GeometricVector(0,0,accelX,accelY,positive,accelLength);
//
//            }
//    FluidLayer::FluidLayer(SDL_Renderer*renderer,int x,int y, int w, int h, int thickness,int type,SDL_Color color,const char* path,int dX,int dY,int flowSpeed,float density):Obstacle(renderer,x,y,w,h,thickness,type,color,path){
//
//        this->bodies={};
//        this->flowVec=new GeometricVector(0,0,dX,dY,positive,flowSpeed);
//        this->density=density;
//
//    }

