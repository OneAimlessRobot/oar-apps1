
typedef struct GameState{



int         mSpeed,
            jSpeed,
            gameMode,
            mouseX1,
            mouseY1,
            mouseX2,
            mouseY2;
Uint16      mask;


}GameState;

typedef struct GameVariables{



int floorLevel,
    fontSize,
    gravity,
    throwingSpeed,
    winWidth,
    winHeight,
    hitBoxThickness;
double fps;


}GameVariables;

namespace aux{
    int randNumBetZeroAnd(int lim);
    int OnesAreContained(Uint16 mask1,Uint16 mask2);
    std::string printMask(Uint16 mask);
    textBox* createTextBoxForVariable(SDL_Renderer* renderer,int fontSize,int x,int y,const char* fontFileName,Uint8 r, Uint8 g,Uint8 b,Uint8 a,int*variable,const char* label);
    double distBetPoints(SDL_Point *src, SDL_Point *dest);
    double distBetPointsInts(int x1,int y1,int x2,int y2);
};
