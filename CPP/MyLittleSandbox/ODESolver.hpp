#ifndef SOLVER_H
#define SOLVER_H

class ODESolver{
//
//    std::vector<GeometricVector<float>*> slopeField;
    int x,y,width, height, stepW,stepH;
    float(*Yprime)(float, float);
public:
    ODESolver(int x, int y, int width,int height,int stepW,int stepH,float(*Yprime)(float, float));
    void drawCurve(SDL_Renderer* renderer, SDL_FPoint point,float step, int n);
    void drawSlopeField(SDL_Renderer*renderer, SDL_Color color);


};

#endif