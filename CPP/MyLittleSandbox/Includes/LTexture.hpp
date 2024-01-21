#ifndef LTEXTURE_H
#define LTEXTURE_H
class LTexture{

    SDL_Texture*texture;
    SDL_FRect* rect;

public:
    LTexture(SDL_Renderer* renderer,float x, float y, float w, float h, const char* path);
    void setXPos(float value);
    void setYPos(float value);
    SDL_FPoint getPos();
    SDL_Texture* getTexture();
    void render(SDL_Renderer* renderer);
    ~LTexture();



};
#endif