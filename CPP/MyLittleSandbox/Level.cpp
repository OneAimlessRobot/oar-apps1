#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "LTexture.hpp"
#include "Menu.hpp"
#include "auxFunctions.h"
#include "graphicalLib1.hpp"
#include "Object.hpp"
#include "GeometricVector.hpp"
#include "Obstacle.hpp"
#include "throwable.hpp"
#include "Planet.hpp"
#include "Iterator.hpp"
#include "FluidLayer.hpp"
#include "Level.hpp"



    Level::Level(SDL_Renderer*renderer,int worldWidth,int worldHeight,std::string filePath){

                    this->worldWidth=worldWidth;
                    this->worldHeight=worldHeight;
                    std::fstream fileIn;
                    fileIn.open(filePath);
                    std::string placeHolder;
                    if(fileIn.is_open()){
                        int obstacleAmmount,planetAmmount;
                        float fluidDensity,hitBoxThickness;
//,fluidDx,fluidDy,fluidSpeed
                        fileIn>>skyTexturePath;
                        fileIn>>fluidDensity;
//                        >>fluidDx>>fluidDy>>fluidSpeed
                        fileIn>>objectTexturePath;
                        fileIn>>obstacleAmmount>>hitBoxThickness;

                        this->air=new FluidLayer(renderer,-500,-500,worldWidth,worldHeight,500,0,(SDL_Color){0,0,0,255},skyTexturePath.std::string::c_str(),fluidDensity);

                        for(int i=0;i<obstacleAmmount;i++){

                            std::getline(fileIn,placeHolder);
                            float x,y,w,h;
                            fileIn>>x>>y>>w>>h;
                            std::cout<<x<<" "<<y<<" "<<w<<" "<<h<<"\n";
                            this->obstacles.push_back(new Obstacle(renderer,x,y,w,h,hitBoxThickness,1,(SDL_Color){0,0,0,255},objectTexturePath.std::string::c_str()));


                        }
                        fileIn>>planetTexturePath;
                        fileIn>>planetAmmount;
                        for(int i=0;i<planetAmmount;i++){

                            std::getline(fileIn,placeHolder);
                            float x,y,w,constant;
                            fileIn>>x>>y>>w>>constant;
                            std::cout<<x<<" "<<y<<" "<<w<<" "<<constant<<"\n";
                            this->planets.push_back(new Planet(renderer,x,y,w,planetTexturePath.std::string::c_str(),(SDL_Color){0,0,0,255},constant,1));


                        }
                        fileIn.close();



    }else{

        std::cerr<<"O mapa nao carregou\n";
        return;

    }
    }

    Iterator<Obstacle*>* Level::obstacleIterator(){

            return new Iterator<Obstacle*>(obstacles);

    }

    Iterator<Planet*>* Level::planetIterator(){

            return new Iterator<Planet*>(planets);

    }

    void Level::addThrowable(Throwable*throwable){

            this->air->addThrowable(throwable);

    }
    float Level::getAirDensity(){
            return this->air->getDensity();
    }
    void Level::renderObstacles(SDL_Renderer* renderer){



        for(Obstacle*obstacle:obstacles){
            obstacle->render(renderer);

        }


    }
//    int Level::getFluidDx(){
//
//        return this->air->getVecDx();
//
//    }
//    int Level::getFluidDy(){
//
//        return this->air->getVecDy();
//        }
//    int Level::getFluidSpeed(){
//
//        return this->air->getFluidSpeed();
//        }
    void Level::addPlanet(Planet*planet){

        for(Planet*thing:planets){

            planet->addPlanet(thing);
        }
        planets.push_back(planet);

    }
    void Level::updateMovements(){

        for(Planet*thing:planets){

            thing->updateVectors();
            thing->shoot();
        }
        air->updateVectors();

    }
    void Level::removePlanets(){



        for(Planet* planet:planets){

            delete(planet);
            planets.pop_back();

        }


    }
    void Level::renderPlanets(SDL_Renderer* renderer){

        for(Planet* planet:planets){

            planet->render(renderer);

        }

    }
    int Level::getObstacleCount(){

            return obstacles.size();

    }
    int Level::getPlanetCount(){

            return planets.size();

    }
    void Level::renderSky(SDL_Renderer*renderer){
        this->air->render(renderer);
    }

    Obstacle* Level::getAirBox(){
        return this->air;

    }

    void Level::addBox(Obstacle* obstacle){


            obstacles.push_back(obstacle);


    }

    void Level::removeBoxes(){




        for(Obstacle* obstacle:obstacles){

            delete(obstacle);
            obstacles.pop_back();

        }


    }

    std::string Level::getSkyImagePath(){
                return  this->skyTexturePath;


    }
    std::string Level::getObjectImagePath(){

           return this->objectTexturePath;


    }
    std::string Level::getPlanetImagePath(){

           return this->planetTexturePath;


    }
    void Level::removeThrowables(){
        this->air->removeThrowables();
    }
    SDL_Point Level::getPos(){
        return (SDL_Point){this->xInit,this->yInit};
    }
    Level::~Level(){
        air->removeThrowables();
        delete(air);
    removeBoxes();
    removePlanets();



    }


