#ifndef CRUSH_H
#define CRUSH_H
typedef struct Inclination{

float calm,reason,reactiveness,ego,strength,openness,neuroticism,cynnicism;
std::string toString();
}Inclination;

typedef struct Interest{

std::string name;
float intensity;
std::string toString();


}Interest;
class Crush{

float mass,age,height;
Inclination inc;
public:
Crush(float mass,float age,float height,Inclination inc);
Crush();
float getMass();
float getAge();
float getHeight();
Inclination getInclination();
std::string toString();
};

#endif
