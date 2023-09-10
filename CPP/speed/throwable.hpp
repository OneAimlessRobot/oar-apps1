
#ifndef THROWABLE_H
#define THROWABLE_H

class Throwable: public Object
{

    std::vector<Obstacle*> boxes;
    GeometricVector<int>* speedVec;
    int value;
    double coefficient;

public:
    Throwable(SDL_Renderer*renderer,int x, int y, int width,SDL_Color color,int trailLength,int trailThickness,const char*imgPath,int value, double coefficient,double DCoefficient);

    void setValue(int value);
    int getValue();
    void shoot();
    void setVector(GeometricVector<int>* speedVec);
    int ricochete();
    void addBox(Obstacle*obstacle);
    int getNumOfBoxes();
    double getCoefficient();
    GeometricVector<int>*getVector();

    ~Throwable();
};

#endif
