
#ifndef THROWABLE_H
#define THROWABLE_H

class Throwable: public Object
{

    std::vector<Obstacle*> boxes;
    GeometricVector<float>* speedVec;
    int value;
    float coefficient;

public:
    Throwable(SDL_Renderer*renderer,float x, float y, float width,SDL_Color color,float trailLength,float trailThickness,const char*imgPath,int value, float coefficient,float DCoefficient);

    void setValue(int value);
    int getValue();
    void shoot();
    void setVector(GeometricVector<float>* speedVec);
    int ricochete();
    void addBox(Obstacle*obstacle);
    int getNumOfBoxes();
    float getCoefficient();
    GeometricVector<float>*getVector();

    ~Throwable();
};

#endif
