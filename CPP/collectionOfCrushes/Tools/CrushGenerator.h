#ifndef CRUSH_GEN_H
#define CRUSH_GEN_H

class CrushGenerator{
private:

float minMass,maxMass,
        minAge,maxAge,
        minHeight,maxHeight;

public:
    CrushGenerator(float minMass,float maxMass,float minAge,float maxAge,float minHeight,float maxHeight);
    Crush* gen();


};


#endif