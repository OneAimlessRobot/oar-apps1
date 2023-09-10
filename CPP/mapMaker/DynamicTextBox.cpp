#include "DynamicTextBox.hpp"




    DynamicTextBox::DynamicTextBox(SDL_Renderer* renderer,int size,int x,int y,const char* fontFileName,Uint8 r, Uint8 g,Uint8 b,Uint8 a,const char* message):textBox(SDL_Renderer* renderer,int size,int x,int y,const char* fontFileName,Uint8 r, Uint8 g,Uint8 b,Uint8 a,const char* message){
        char i;
        int j=0;
        for(i=message[j];i!='\0';i=message[j++]){
        this->message[j]=i;
        }
        this->message[j+1]='\0';


    }

    void DynamicTextBox::updateText(const char* str){
        char i;
        int j=0;
        for(i=message[j];i!='\0';i=str[j++]){
        this->message[j]=i;
        }
        this->message[j+1]='\0';



    }
