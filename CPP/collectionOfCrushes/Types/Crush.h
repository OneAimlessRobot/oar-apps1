#ifndef CRUSH_H
#define CRUSH_H
class Inclination{
public:
float heart,reason,reactiveness,ego,strength,openness,neuroticism,cynnicism;
std::string toString();
static Inclination add(Inclination inc1,Inclination inc2);
static Inclination multiply(Inclination inc, float factor);
static Inclination normalize(Inclination inc);
static float norm(Inclination inc);
};

class Interest{
public:
std::string name;
float intensity;
std::string toString();


};
class Crush{

float mass,age,height;
std::list<Interest> interests;
Inclination inc;
public:
Crush(float mass,float age,float height,Inclination inc);
Crush();
float getMass();
float getAge();
float getHeight();
Inclination getInclination();
void setInclination(Inclination inc);
std::string toString();
void addInterest(Interest added);
void removeLastInterest();
};

#endif
