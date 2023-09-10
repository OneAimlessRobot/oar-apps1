#ifndef PLANET_H
#define PLANET_H


class Planet:public Object{

std::vector<Throwable*> satelites;
std::vector<Planet*> planets;
GeometricVector<int>* speedVec;
int width,constant;

public:
    Planet(SDL_Renderer* renderer,int xInit,int yInit,int size,const char* imgPath,SDL_Color color,int constant,double DCoefficient);

    void updateVectors();
    void deleteSatelites();
    int getConstant();
    void addThrowable(Throwable* throwable);
    void addPlanet(Planet*planet);
    void shoot();
    void setVector(GeometricVector<int>*vec);
    GeometricVector<int>* getVector();
    double getIntensity(int xPos,int yPos);
    ~Planet();

};
#endif