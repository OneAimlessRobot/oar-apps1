#ifndef FLUID_H
#define FLUID_H

class FluidLayer:public Obstacle{

std::list<Throwable*> bodies;
GeometricVector<float>* flowVec;
float density;

public:
//    FluidLayer(SDL_Renderer*renderer,int x,int y, int w, int h, int thickness,int type,SDL_Color color,const char* path,int dX,int dY,int flowSpeed,float density);
    FluidLayer(SDL_Renderer*renderer,float x, float y, float w, float h, float thickness,int type,SDL_Color color,const char* path,float density);

    float getDensity();
    void addThrowable(Throwable*throwable);
    void updateVectors();
    void removeThrowables();
//    int getVecDx();
//    int getVecDy();
//    int getFluidSpeed();
    float getFluidDragOnBody(float speed,float DCoefficient,float area);
    ~FluidLayer();



};


#endif