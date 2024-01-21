

#ifndef CIRCLER_H
#define CIRCLER_H

class Circler{
SDL_Rect*body;
SDL_Color color;
clockCounter* counter;
Trail*trail;
SDL_Texture* texture;
std::string imagePath;
int x,y,size,speed,radius,xCenter,yCenter,precision;

public:

    Circler(SDL_Renderer*renderer,int xInit,int yInit,int size,int speedInit,const char* imagePath,SDL_Color color,int trailW,int trailL,int radius,int precision);

    void parametricEquationCalculation();

    void setPos(int x,int y);
    void setCenter(int x,int y);
    SDL_Point getCenter();
    void render(SDL_Renderer* renderer);
    SDL_Point getPos();
    int getSize();

    ~Circler();

};


#endif
