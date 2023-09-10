#ifndef OBJECT_H
#define OBJECT_H



class Object{



    SDL_Color color;
    SDL_FRect *body;
    LTexture* texture;
    float DCoefficient;
public:

    Object(SDL_Renderer* renderer,float x,float y, float width,float trailLength,float trailThickness,SDL_Color color,const char* imgPath,float DCoefficient);
    void setPos(float x, float y);
    SDL_FPoint getPos();
    SDL_FPoint getCenter();
    SDL_FRect* getBody();
    float getSize();
    float getDCoefficient();
    void setDCoefficient(float value);
    SDL_Color getColor();
    void render(SDL_Renderer *renderer);
    ~Object();

};

#endif