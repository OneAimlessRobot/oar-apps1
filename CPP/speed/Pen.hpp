
#ifndef PEN_H
#define PEN_H

class Pen{

std::vector<SDL_Rect> drawing;
SDL_Color inkColor;
int thickness;

public:
    Pen(int thickness,SDL_Color color);


    void renderDrawing(SDL_Renderer* renderer);
    void draw(int x, int y);
    void clearDrawing();

    ~Pen();

};

#endif