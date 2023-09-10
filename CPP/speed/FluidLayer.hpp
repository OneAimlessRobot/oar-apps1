#ifndef FLUID_H
#define FLUID_H

class FluidLayer:public Obstacle{

std::vector<Throwable*> bodies;
GeometricVector<int>* flowVec;
double density;

public:
//    FluidLayer(SDL_Renderer*renderer,int x,int y, int w, int h, int thickness,int type,SDL_Color color,const char* path,int dX,int dY,int flowSpeed,double density);
    FluidLayer(SDL_Renderer*renderer,int x,int y, int w, int h, int thickness,int type,SDL_Color color,const char* path,double density);

    double getDensity();
    void addThrowable(Throwable*throwable);
    void updateVectors();
    void removeThrowables();
//    int getVecDx();
//    int getVecDy();
//    int getFluidSpeed();
    double getFluidDragOnBody(double speed,double DCoefficient,double area);
    ~FluidLayer();



};


#endif