#include<vector>
#ifndef GRAPHICAL_1_H
#define GRAPHICAL_1_H
class graphicalLib1{
public:
    static void drawLineThisThick(int thickness,SDL_Renderer* renderer,SDL_Color color,int x1,int y1,int x2,int y2,int mode);

    static void drawWireFrameTriangle(SDL_Renderer* renderer,SDL_Color color,int xOrigin,int yOrigin,int radius);

    static void drawWireFrameNAgon(SDL_Renderer* renderer,SDL_Color color,int xOrigin,int yOrigin,int radius,int nSides,int facing);

    static void drawEquation(SDL_Renderer*renderer,int (*f)(int),SDL_Color color, int xOrigin,int yOrigin,int xEnd);

    static void drawLineFromPointVector(SDL_Renderer*renderer,SDL_Color color, std::vector<SDL_Point> vec);

    static void drawThickLineFromPointVector(SDL_Renderer*renderer,SDL_Color color, int thickness,std::vector<SDL_Point> vec);

//
//    static void drawWireFrameArrow(SDL_Renderer* renderer,SDL_Color color,int xOrigin,int yOrigin,int radius,int tailLength);


};
class clockCounter{
int modulus,current, unlimitted;
public:
    clockCounter(int initial,int modulus,int unlimitted);

    void increment();
    void decrement();
    int getCurrent();
    int getModulus();
    void setCurrent(int value);
    void setModulus(int value);

};
#endif
