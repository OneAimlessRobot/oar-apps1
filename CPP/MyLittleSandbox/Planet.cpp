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



    Planet::Planet(SDL_Renderer* renderer,float xInit,float yInit,float width,const char* imgPath,SDL_Color color,float constant,float DCoefficient):Object(renderer,xInit,yInit,width,1,1,color,imgPath,DCoefficient){
    this->width=width;
    this->constant=constant;
    this->satelites={};
    this->planets={};
    this->speedVec=GeometricVector<float>::neutralVector(this->getCenter().x,this->getCenter().y);


    }
    void Planet::addPlanet(Planet*planet){

        this->planets.push_back(planet);

    }
    void Planet::updateVectors(){

        for(Planet*obj:planets){

            GeometricVector<float>*accel=new GeometricVector<float>(obj->getCenter().x,obj->getCenter().y,this->getCenter().x-obj->getCenter().x,this->getCenter().y-obj->getCenter().y,positive,getIntensity(obj->getCenter().x,obj->getCenter().y));
            GeometricVector<float>*objSpeed=obj->getVector();
            obj->setVector(objSpeed->add(accel));

        }

    }
    float Planet::getConstant(){
        return this->constant;
    }
    void Planet::setVector(GeometricVector<float>*vec){

        this->speedVec=vec;



    }
    GeometricVector<float>* Planet::getVector(){

        return this->speedVec;


    }
    void Planet::shoot(){

        this->speedVec->setStart(this->getCenter());
        SDL_FPoint after=this->speedVec->getTip();
        this->setPos(after.x-this->getSize()*0.5,after.y-this->getSize()*0.5);
    }
    void Planet::deleteSatelites(){




        for(Throwable*thing:satelites){

            satelites.pop_back();

        }
        for(Planet*planet:planets){

            planets.pop_back();

        }


    }
    float Planet::getIntensity(float xPos,float yPos){
        SDL_FPoint current=this->getCenter();
        SDL_FPoint particlePos=(SDL_FPoint){xPos,yPos};

        float dist=aux::distBetPoints(&current,&particlePos);
        if(dist==0){
            return 0;
        }
        else{
            return this->constant/(dist*dist);
        }

    }
    Planet::~Planet(){


    }


