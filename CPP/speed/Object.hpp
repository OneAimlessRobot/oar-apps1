#ifndef OBJECT_H
#define OBJECT_H



class Object{



    SDL_Color color;
    SDL_FRect *body;
    LTexture* texture;
    double DCoefficient;
public:

    Object(SDL_Renderer* renderer,double x,double y, double width,double trailLength,double trailThickness,SDL_Color color,const char* imgPath,double DCoefficient);
    void setPos(double x, double y);
    SDL_FPoint getPos();
    SDL_FPoint getCenter();
    SDL_FRect* getBody();
    double getSize();
    double getDCoefficient();
    void setDCoefficient(double value);
    SDL_Color getColor();
    void render(SDL_Renderer *renderer);
    ~Object();

};

#endif