#ifndef LTEXTURE_H
#define LTEXTURE_H
class LTexture{

    SDL_Texture*texture;
    SDL_Rect* rect;

public:
    LTexture(SDL_Renderer* renderer,int x, int y, int w, int h, const char* path);
    void setXPos(int value);
    void setYPos(int value);
    SDL_Point getPos();
    SDL_Texture* getTexture();
    void render(SDL_Renderer* renderer);
    ~LTexture();



};
#endif