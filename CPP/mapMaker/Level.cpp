#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Obstacle.hpp"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "ObstacleIterator.hpp"
#include "Level.hpp"


    Level::Level(SDL_Renderer*renderer,int worldWidth,int worldHeight,std::string filePath){

                    this->worldWidth=worldWidth;
                    this->worldHeight=worldHeight;
                    std::fstream fileIn;
                    fileIn.open(filePath);
                    std::string placeHolder;
                    if(fileIn.is_open()){
                        int ammount,hitBoxThickness;

                        fileIn>>skyTexturePath;
                        fileIn>>ammount>>hitBoxThickness;

                        this->air=new Obstacle(renderer,-500,-500,worldWidth,worldHeight,500,0,(SDL_Color){0,0,0,255},skyTexturePath.std::string::c_str());

                        for(int i=0;i<ammount;i++){

                            std::getline(fileIn,placeHolder);
                            int x,y,w,h;
                            std::string path2ImgStr;
                            fileIn>>path2ImgStr;
                            fileIn>>x>>y>>w>>h;
                            std::cout<<x<<" "<<y<<" "<<w<<" "<<h<<"\n";
                            this->obstacles.push_back(new Obstacle(renderer,x,y,w,h,hitBoxThickness,1,(SDL_Color){0,0,0,255},path2ImgStr.std::string::c_str()));


                        }
                        fileIn.close();



    }
    }

    ObstacleIterator* Level::obstacleIterator(){

            return new ObstacleIterator(obstacles);

    }

    void Level::renderObstacles(SDL_Renderer* renderer){



        for(Obstacle*obstacle:obstacles){
            obstacle->renderObstacle(renderer);

        }


    }
    int Level::getObstacleCount(){

            return obstacles.size();

    }
    void Level::renderSky(SDL_Renderer*renderer){
        this->air->renderObstacle(renderer);
    }

    Obstacle* Level::getAirBox(){
        return this->air;

    }

    void Level::addBox(Obstacle* obstacle){


            obstacles.push_back(obstacle);


    }

    void Level::removeBoxesOnly(){




        for(Obstacle* obstacle:obstacles){

            delete(obstacle);
            obstacles.pop_back();

        }


    }
    void Level::updateSky(SDL_Renderer*renderer,std::string path2Img){

    delete(air);

        this->air=new Obstacle(renderer,-500,-500,worldWidth,worldHeight,500,0,(SDL_Color){0,0,0,255},path2Img.std::string::c_str());






    }

    std::string Level::getSkyImagePath(){
                return  this->skyTexturePath;


    }

    SDL_Point Level::getPos(){
        return (SDL_Point){this->xInit,this->yInit};
    }
    Level::~Level(){

        delete(air);

        for(Obstacle* obstacle:obstacles){

            delete(obstacle);
            obstacles.pop_back();

        }



    }


