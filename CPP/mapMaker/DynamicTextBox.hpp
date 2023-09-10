#include"Menu.hpp"

class DynamicTextBox: textBox{
 char message[128];
public:
DynamicTextBox(SDL_Renderer* renderer,int size,int x,int y,const char* fontFileName,Uint8 r, Uint8 g,Uint8 b,Uint8 a,const char* message):textBox(SDL_Renderer* renderer,int size,int x,int y,const char* fontFileName,Uint8 r, Uint8 g,Uint8 b,Uint8 a,const char* message);

    void updateText(const char* str);
};
