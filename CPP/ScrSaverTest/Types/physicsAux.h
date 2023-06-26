#ifndef PHYSICS_H
#define PHYSICS_H
namespace PhysicsAux{

constexpr float GCONST=0.001;
float getReboundSpeed(float initSpeed,float coeff);
float gravForce(SDL_FPoint p1,SDL_FPoint p2,float m1,float m2);

float dragNeutralWind(float k, float airD,float speed);



}
#endif
