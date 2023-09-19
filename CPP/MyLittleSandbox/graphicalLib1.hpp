
#ifndef GRAPHICAL_1_H
#define GRAPHICAL_1_H
class graphicalLib1{
public:
    static void drawLineThisThick(float thickness,SDL_Renderer* renderer,SDL_Color color,float x1,float y1,float x2,float y2,int mode);

    static void drawWireFrameNAgon(SDL_Renderer* renderer,SDL_Color color,int xOrigin,int yOrigin,int radius,int nSides,int facing);

    static void drawEquation(SDL_Renderer*renderer,int (*f)(int),SDL_Color color, int xOrigin,int yOrigin,int xEnd);

    static void drawLineFromPointVector(SDL_Renderer*renderer,SDL_Color color, std::vector<SDL_FPoint> vec);

    static void drawThickLineFromPointVector(SDL_Renderer*renderer,SDL_Color color, float thickness,std::vector<SDL_FPoint> vec);

    static void drawCircle(SDL_Renderer*renderer,SDL_Color color, float radius,float x,float y);

    static void drawCircunference(SDL_Renderer*renderer,SDL_Color color, float radius,float xCenter,float yCenter,float precision);
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
