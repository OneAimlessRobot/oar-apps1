#ifndef PLANET_H
#define PLANET_H


class Planet:public Object{

std::vector<Planet*> satelites;
GeometricVector<float>* speedVec;
float width,constant;

public:
    Planet(SDL_Renderer* renderer,float xInit,float yInit,float width,const char* imgPath,SDL_Color color,float constant,float DCoefficient);

    void updateVectors();
    void deleteSatelites();
    float getConstant();
    void addPlanet(Planet*planet);
    void shoot();
    void setVector(GeometricVector<float>*vec);
    GeometricVector<float>* getVector();
    float getIntensity(float xPos,float yPos);
    ~Planet();

};
#endif
