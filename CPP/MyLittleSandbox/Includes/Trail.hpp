
#ifndef TRAIL_H
#define TRAIL_H

class Trail{


    std::vector<SDL_FPoint> trailPoints;
    SDL_Color color;
    float trailLength,trailThickness,currentX,currentY;
public:

    Trail(float length,float width,float xInit,float yInit,SDL_Color color);

    float getThickness();
    void render(SDL_Renderer* renderer);
    SDL_FPoint getCurrentPos();
    void setPos(float x, float y);
    void setThickness(float value);
    float getLength();
    ~Trail();


};

#endif
