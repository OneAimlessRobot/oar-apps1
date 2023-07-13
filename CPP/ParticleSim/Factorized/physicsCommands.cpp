#include <list>
#include <vector>
#include <iostream>
#include <iterator>
#include <SDL2/SDL.h>
#include "../auxFuncs.h"
#include "../Types/GVector.h"
#include "../Types/Bullet.h"
#include "../Types/Entity.h"
#include "../Types/Gun.h"
#include "../Types/Collider.h"
#include "../Types/physicsAux.h"
#include "../Types/Grenade.h"
#include "../constantHeaders/physicsConstants.h"
#include "physicsCommands.h"





void PhysicsCommands::handleCollisions(int collisionsEnabled,std::list<Entity*>& entList,std::list<Gun*>& gunList,std::list<Grenade*>& grenadeList,Collider* arena){

    //broken. Maybe will fix
    if(collisionsEnabled){
    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
      handleInterparticleCollisions<Entity>(entList);
      handleInterparticleCollisions<Grenade>(grenadeList);
    }

    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
    deleteFreaks<Gun>(gunList);
     handleCollisionsWithArena<Entity>(entList,arena);
    handleCollisionsWithArena<Gun>(gunList,arena);
    handleCollisionsWithArena<Grenade>(grenadeList,arena);

}
void PhysicsCommands::handleForces(int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,std::list<Grenade*>& grenadeList,Collider* arena,Entity*worldParticle){

    if(gravityEnabled){
    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
      handleInterparticleGravity<Entity>(entList);
      handleInterparticleGravity<Grenade>(grenadeList);



    }
    if(dragEnabled){
    deleteFreaks<Entity>(entList);

    handleDrag<Entity>(entList, arena);
    deleteFreaks<Grenade>(grenadeList);
    handleDrag<Grenade>(grenadeList, arena);

    }
    if(GROUNDGRAVON){
    deleteFreaks<Entity>(entList);

    handleGroundGravity<Entity>(entList,worldParticle);

    deleteFreaks<Grenade>(grenadeList);
    handleGroundGravity<Grenade>(grenadeList,worldParticle);

    }

}
void PhysicsCommands::handleMovements(int collisionsEnabled,int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,Collider* arena,std::list<Gun*>& gunList,std::list<Grenade*>& grenadeList,Entity* worldMassParticle){

    handleForces(gravityEnabled,dragEnabled,entList,grenadeList,arena,worldMassParticle);

    handleCollisions(collisionsEnabled,entList,gunList,grenadeList,arena);



}
