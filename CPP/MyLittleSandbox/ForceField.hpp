#ifndef FFIELD_H
#define FFIELD_H

class ForceField:public Object{

    std::vector<Throwable*> bodies;

    GeometricVector<float>* forceVec;

    public:

    ForceField(SDL_Renderer* renderer,float x,float y, float width,float trailLength,float trailThickness,SDL_Color color,const char* imgPath,float DCoefficient,float dX,float dY,float magnitude);

    void addBody(Throwable* throwable);

    void updateVectors();

    void removeBodies();

    ~ForceField();


};

#endif