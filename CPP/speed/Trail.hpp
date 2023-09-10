
#ifndef TRAIL_H
#define TRAIL_H

class Trail{


    std::vector<SDL_Point> trailPoints;
    SDL_Color color;
    int trailLength,trailThickness,currentX,currentY;
public:

    Trail(int length,int width,int xInit,int yInit,SDL_Color color);

    int getThickness();
    void render(SDL_Renderer* renderer);
    SDL_Point getCurrentPos();
    void setPos(int x, int y);
    void setThickness(int value);
    int getLength();
    ~Trail();


};

#endif
