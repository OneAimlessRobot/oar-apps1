#ifndef FFIELD_H
#define FFIELD_H

class ForceField:public Object{

    std::vector<Throwable*> bodies;

    GeometricVector<int>* forceVec;

    public:

    ForceField(SDL_Renderer* renderer,int x,int y, int width,int trailLength,int trailThickness,SDL_Color color,const char* imgPath,double DCoefficient,int dX,int dY,int magnitude);

    void addBody(Throwable* throwable);

    void updateVectors();

    void removeBodies();

    ~ForceField();


};

#endif