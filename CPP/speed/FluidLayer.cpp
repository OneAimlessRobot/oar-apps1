#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>
#include "Obstacle.hpp"
#include "LTexture.hpp"
#include "Object.hpp"
#include "Menu.hpp"
#include "graphicalLib1.hpp"
#include "auxFunctions.h"
#include "GeometricVector.hpp"
#include "throwable.hpp"
#include "FluidLayer.hpp"

    FluidLayer::FluidLayer(SDL_Renderer*renderer,int x,int y, int w, int h, int thickness,int type,SDL_Color color,const char* path,double density):Obstacle(renderer,x,y,w,h,thickness,type,color,path){

        this->bodies={};
        this->density=density;

    }

    double  FluidLayer::getDensity(){
        return this->density;
    }
    void  FluidLayer::addThrowable(Throwable*throwable){

        this->bodies.push_back(throwable);
    }
    void  FluidLayer::updateVectors(){
        for(Throwable*thing:bodies){
                GeometricVector<int>* accel=new GeometricVector<int>(thing->getCenter().x,thing->getCenter().y,thing->getVector()->getDx(),thing->getVector()->getDy(),positive,-ceil(getFluidDragOnBody(thing->getVector()->getLength(),thing->getDCoefficient(),thing->getSize())));



           thing->setVector(thing->getVector()->add(accel));
        }
    }
    double FluidLayer::getFluidDragOnBody(double speed,double DCoefficient,double area){

            return speed*speed*this->getDensity()*DCoefficient*area*0.001;
    }
    void FluidLayer::removeThrowables(){
        for(Throwable* thing:bodies){

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
//            double accelX=getFluidDragOnBody(thing->getVector()->getXLength()-this->flowVec->getXLength(),thing->getDCoefficient(),thing->getSize());
//            double accelY=getFluidDragOnBody(thing->getVector()->getYLength()-this->flowVec->getYLength(),thing->getDCoefficient(),thing->getSize());
//            double accelLength=sqrt(accelX*accelX+accelY*accelY);
//            else{
//                accel=new GeometricVector(0,0,accelX,accelY,positive,accelLength);
//
//            }
//    FluidLayer::FluidLayer(SDL_Renderer*renderer,int x,int y, int w, int h, int thickness,int type,SDL_Color color,const char* path,int dX,int dY,int flowSpeed,double density):Obstacle(renderer,x,y,w,h,thickness,type,color,path){
//
//        this->bodies={};
//        this->flowVec=new GeometricVector(0,0,dX,dY,positive,flowSpeed);
//        this->density=density;
//
//    }

