#include "HitBox.hpp"
#ifndef OBSTACLE_H
#define OBSTACLE_H
class Obstacle{

    HitBox *hitBox;
    SDL_Rect*body;
    SDL_Texture *texture;
    SDL_Color color;
    int thickness;
    std::string path2Img;
public:
    Obstacle(SDL_Renderer*renderer,int x,int y, int w, int h, int thickness,int type,SDL_Color color,const char* path);

    int getHitBoxType();
    void setPos(int x,int y);
    SDL_Point getShellPos();
    SDL_Point getCorePos();
    int getThickness();
    int getOuterWidth();
    int getInnerWidth();
    int getOuterHeight();
    int getInnerHeight();
    std::string getPath2Img();
    void setInnerWidth(int value);
    void setInnerHeight(int value);
    int boxHitLeft(const SDL_Rect* rect);
    int boxHitRight(const SDL_Rect* rect);
    int boxHitUp(const SDL_Rect* rect);
    int boxHitDown(const SDL_Rect* rect);
    int boxContains(SDL_Point* point);
    void renderObstacleFillOnly(SDL_Renderer* renderer);
    void renderObstacle(SDL_Renderer* renderer);
    ~Obstacle();

};
#endif
