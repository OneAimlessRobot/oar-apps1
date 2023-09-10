#include "Menu.hpp"


    textBox::textBox(SDL_Renderer* renderer,int size,int x,int y,const char* fontFileName,Uint8 r, Uint8 g,Uint8 b,Uint8 a,const char* message){

    this->Color = {r,g,b,a};
    this->Font=TTF_OpenFont(fontFileName, size);
    if(this->Font==(TTF_Font*)NULL){

        std::cout<<"Could not create font\n";
        }
    this->Message_rect.x = x;
    this->Message_rect.y = y;
SDL_Surface* surface =TTF_RenderText_Solid(this->Font, message, Color);
    if(surface==(SDL_Surface*)NULL){

            std::cout<<"Could not create surface\n";
        }
texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture==(SDL_Texture* )NULL){

            std::cout<<"Could not create message box\n";
        }
    SDL_FreeSurface(surface);
    this->Message_rect.w = surface->w;
    this->Message_rect.h = surface->h;
        char i;
        int j=0;
        for(i=message[j];i!='\0';i=message[j++]){
        this->message[j]=i;
        }
        this->message[j+1]='\0';

    }
    void textBox::render(SDL_Renderer*renderer){
        SDL_SetRenderDrawColor(renderer,200,0,0,255);
        SDL_RenderFillRect(renderer,&Message_rect);
        SDL_RenderCopy(renderer, this->texture, NULL, &this->Message_rect);
    }
    SDL_Texture* textBox::getTexture(){

        return this->texture;
    }
    int textBox::getXPos(){

    return this->Message_rect.x;

    }
    int textBox::getYPos(){

    return this->Message_rect.y;

    }

    int textBox::getWidth(){
    return this->Message_rect.w;
    }
    int textBox::getHeight(){
    return this->Message_rect.h;
    }
    SDL_Color textBox::getTextColor(){

    return this->Color;
    }
    SDL_Color textBox::getBoxColor(){

    return {200,0,0,255};
    }
    void textBox::updateText(SDL_Renderer* renderer,const char* str){
        char i;
        int j=0;
        for(i=message[j];i!='\0';i=str[j++]){
        this->message[j]=i;
        }
        this->message[j+1]='\0';

SDL_Surface* surface =TTF_RenderText_Solid(this->Font, str, Color);
    if(surface==(SDL_Surface*)NULL){

            std::cout<<"Could not create surface\n";
        }
texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture==(SDL_Texture* )NULL){

            std::cout<<"Could not create message box\n";
        }
    SDL_FreeSurface(surface);
    this->Message_rect.w = surface->w;
    this->Message_rect.h = surface->h;

    }
    char * textBox::printMsg(){
    return this->message;
    }

    textBox::~textBox(){
    TTF_CloseFont(this->Font);
    SDL_DestroyTexture(this->texture);


    }

