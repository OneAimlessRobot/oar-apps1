#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include"LTexture.hpp"
#include <vector>
#include "Menu.hpp"
#include <string>
#include "auxFunctions.h"
#include "graphicalLib1.hpp"
#include "GeometricVector.hpp"
#include "Trail.hpp"
#include "Object.hpp"
#include "Obstacle.hpp"
#include "throwable.hpp"
#include "Planet.hpp"



    Planet::Planet(SDL_Renderer* renderer,int xInit,int yInit,int width,const char* imgPath,SDL_Color color,int constant,double DCoefficient):Object(renderer,xInit,yInit,width,1,1,color,imgPath,DCoefficient){
    this->width=width;
    this->constant=constant;
    this->satelites={};
    this->planets={};
    this->speedVec=GeometricVector<int>::neutralVector(this->getCenter().x,this->getCenter().y);


    }
    void Planet::addThrowable(Throwable* throwable){

        this->satelites.push_back(throwable);

    }

    void Planet::addPlanet(Planet*planet){

        this->planets.push_back(planet);

    }
    void Planet::updateVectors(){

        for(Throwable*obj:satelites){
            GeometricVector<int>*accel=new GeometricVector<int>(obj->getCenter().x,obj->getCenter().y,this->getCenter().x-obj->getCenter().x,this->getCenter().y-obj->getCenter().y,positive,round(getIntensity(obj->getCenter().x,obj->getCenter().y)));
            GeometricVector<int>*objSpeed=obj->getVector();
            obj->setVector(objSpeed->add(accel));
        }
        for(Planet*obj:planets){

            GeometricVector<int>*accel=new GeometricVector<int>(obj->getCenter().x,obj->getCenter().y,this->getCenter().x-obj->getCenter().x,this->getCenter().y-obj->getCenter().y,positive,round(getIntensity(obj->getCenter().x,obj->getCenter().y)));
            GeometricVector<int>*objSpeed=obj->getVector();
            obj->setVector(objSpeed->add(accel));

        }

    }
    int Planet::getConstant(){
        return this->constant;
    }
    void Planet::setVector(GeometricVector<int>*vec){

        this->speedVec=vec;



    }
    GeometricVector<int>* Planet::getVector(){

        return this->speedVec;


    }
    void Planet::shoot(){

        this->speedVec->setStart(this->getCenter());
        SDL_Point after=this->speedVec->getTip();
        this->setPos(after.x-(int)(this->getSize()*0.5),after.y-(int)(this->getSize()*0.5));
    }
    void Planet::deleteSatelites(){




        for(Throwable*thing:satelites){

            satelites.pop_back();

        }
        for(Planet*planet:planets){

            planets.pop_back();

        }


    }
    double Planet::getIntensity(int xPos,int yPos){
        SDL_Point current=this->getCenter();
        SDL_Point particlePos=(SDL_Point){xPos,yPos};

        double dist=aux::distBetPoints(&current,&particlePos);
        if(dist==0){
            return 0;
        }
        else{
            return this->constant/(dist*dist);
        }

    }
    Planet::~Planet(){


    }


