#ifndef CRUSH_H
#define CRUSH_H
class Inclination{
public:
float heart,reason,reactiveness,ego,strength,openness,neuroticism,cynnicism;

//Esta funcao devolve uma representaçao desta Inclination em texto.
std::string toString();

//This creates a football game.
//Rule 1
//rule 2
//...
FootballGame create(Pitch pitch,team A, team B, Ball ball);




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

typedef Interest Trait;
class Crush{
std::string name;
float mass,age,height;
std::list<Interest> interests;
std::list<Trait> traits;
Inclination inc;
public:
Crush(std::string name,float mass,float age,float height,Inclination inc);
Crush();
float getMass();
float getAge();
float getHeight();
Inclination getInclination();
void setInclination(Inclination inc);
std::string toString();
void addInterest(Interest added);

void addTrait(Trait added);
void removeLastInterest();
};

#endif
