
#ifndef PEN_H
#define PEN_H

class Pen{

std::vector<SDL_FRect> drawing;
SDL_Color inkColor;
float thickness;

public:
    Pen(float thickness,SDL_Color color);


    void renderDrawing(SDL_Renderer* renderer);
    void draw(float x,float y);
    void clearDrawing();

    ~Pen();

};

#endif
