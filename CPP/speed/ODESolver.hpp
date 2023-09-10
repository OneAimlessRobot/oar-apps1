#ifndef SOLVER_H
#define SOLVER_H

class ODESolver{
//
//    std::vector<GeometricVector<double>*> slopeField;
    int x,y,width, height, stepW,stepH;
    double(*Yprime)(double, double);
public:
    ODESolver(int x, int y, int width,int height,int stepW,int stepH,double(*Yprime)(double, double));
    void drawCurve(SDL_Renderer* renderer, SDL_FPoint point,double step, int n);
    void drawSlopeField(SDL_Renderer*renderer, SDL_Color color);


};

#endif