#include <iostream>

#ifndef G_VEC
#define G_VEC
class GVector {

private:
float x,y;

public:
    GVector(float x,float y);
    float getX();
    float getY();
    void setX(float newX);
    void setY(float newY);
    ~GVector();





};
#endif
