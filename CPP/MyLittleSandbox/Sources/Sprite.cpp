#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "../Includes/graphicalLib1.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "../Includes/TemporaryTexture.hpp"
#include "../Includes/Sprite.hpp"

    Sprite::Sprite(SDL_Renderer*renderer,float x,float y,const char* pathToSprite,int unlimitted,int cycleNumber){
        this->unlimitted=unlimitted;
        this->cycleCounter=new clockCounter(0,cycleNumber,this->unlimitted);
        std::fstream spriteReader;
        std::string placeHolder;
        this->frames={};
        spriteReader.open(pathToSprite);
        if(spriteReader.is_open()){
        while(!std::getline(spriteReader,placeHolder).eof()){
            std::string path;
            float w,h,xOffset,yOffset;
            int ticks;
            spriteReader>>path;
            spriteReader>>w>>h>>xOffset>>yOffset>>ticks;
            TemporaryTexture*texture=new TemporaryTexture(renderer,x+xOffset,y+yOffset,w,h,path.std::string::c_str(),ticks,1);
            this->frames.push_back(texture);


        }
        spriteReader.close();
        this->frameCounter=new clockCounter(0,frames.size()-1,0);
        }
        else{

            std::cerr<<"Could not create sprite because file did not open\n";
        }




    }

    void Sprite::setPos(float x,float y){

        for(TemporaryTexture *texture:frames){
            texture->setXPos(x+texture->getWidth()*0.5);
            texture->setYPos(y+texture->getHeight()*0.5);

        }

    }
    int Sprite::isOver(){

            if(!this->unlimitted){
                return this->cycleCounter->getCurrent()>=this->cycleCounter->getModulus();

            }


    }
    void Sprite::resetSprite(){

        for(TemporaryTexture *texture:frames){
            texture->reset();

        }

    }
    SDL_FPoint Sprite::getPos(){

        return (SDL_FPoint){frames[0]->getPos().x+frames[0]->getWidth()*0.5,frames[0]->getPos().y+frames[0]->getHeight()*0.5};

    }
    void Sprite::render(SDL_Renderer* renderer){


    if((this->cycleCounter->getCurrent()<this->cycleCounter->getModulus())||(this->unlimitted)){

        if(frameCounter->getCurrent()<this->frames.size()-1){

        if(this->frames[frameCounter->getCurrent()]->getCurrentValue()<this->frames[frameCounter->getCurrent()]->getMaxTicks()-1){

            this->frames[frameCounter->getCurrent()]->render(renderer);
        }
        else{
            this->frameCounter->increment();

        }
        }
        else{
            resetSprite();
            std::cout<<cycleCounter->getCurrent()<<"\n";
            this->frameCounter->setCurrent(0);
            this->cycleCounter->increment();
        }
        }


    }

    Sprite::~Sprite(){
        delete(frameCounter);
        delete(cycleCounter);

            int finished= frames.size();
            for(int i=0;i<finished;i++){
                frames.pop_back();
            }


    }
