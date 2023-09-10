#ifndef AUX_H
#define AUX_H
typedef struct GameState{



int         mSpeed,
            jSpeed,
            mouseX1,
            mouseY1,
            mouseX2,
            mouseY2;
uint16_t      mask;


}GameState;

typedef struct GameVariables{



int     fontSize,
        winWidth,
        winHeight;
float   gravity,
        throwingSpeed,
        floorLevel,
        hitBoxThickness,
        fps;


}GameVariables;

namespace aux{
    int randNumBetween(int bottom,int top);
    int randNumBetZeroAnd(int lim);
    int OnesAreContained(Uint16 mask1,Uint16 mask2);
    std::string printMask(Uint16 mask);
    textBox* createTextBoxForVariable(SDL_Renderer* renderer,int fontSize,int x,int y,const char* fontFileName,Uint8 r, Uint8 g,Uint8 b,Uint8 a,int*variable,const char* label);
    float distBetPoints(SDL_FPoint *src, SDL_FPoint *dest);
    float distBetPointsFloats(float x1,float y1,float x2,float y2);
};

#endif