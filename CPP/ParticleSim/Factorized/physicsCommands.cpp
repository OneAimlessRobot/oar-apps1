#include <list>
#include <vector>
#include <iostream>
#include <iterator>
#include <SDL2/SDL.h>
#include "../Types/GVector.h"
#include "../Types/Bullet.h"
#include "../Types/Entity.h"
#include "../Types/Gun.h"
#include "../Types/Collider.h"
#include "../Types/physicsAux.h"
#include "../aux.h"
#include "physicsCommands.h"





void PhysicsCommands::handleCollisions(int collisionsEnabled,std::list<Entity*>& entList,std::list<Gun*>& gunList,Collider* arena){

    //broken. Maybe will fix
    if(collisionsEnabled){
    deleteFreaks<Entity>(entList);
      handleInterparticleCollisions<Entity>(entList);
    }

    deleteFreaks<Entity>(entList);
     handleCollisionsWithArena<Entity>(entList,arena);
    deleteFreaks<Gun>(gunList);
    handleCollisionsWithArena<Gun>(gunList,arena);

}
void PhysicsCommands::handleForces(int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,Collider* arena){

    if(gravityEnabled){
    deleteFreaks<Entity>(entList);
      handleInterparticleGravity<Entity>(entList);


    }
    if(dragEnabled){
    deleteFreaks<Entity>(entList);

    handleDrag(entList, arena);

    }

}
void PhysicsCommands::handleDrag(std::list<Entity*>& entList,Collider* arena){


    std::list<Entity*>::iterator it;
    for (it = entList.begin(); it != entList.end(); ++it) {

        SDL_FPoint dragVec=PhysicsAux::dragNeutralWindVector((*it)->getVec(),(*it)->getDragConstant(),arena->getAirDensity());
        PhysicsAux::accelerateEntity((*it),dragVec);


}



}
void PhysicsCommands::handleMovements(int collisionsEnabled,int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,Collider* arena,std::list<Gun*>& gunList){

    handleForces(gravityEnabled,dragEnabled,entList,arena);

    handleCollisions(collisionsEnabled,entList,gunList,arena);



}
void PhysicsCommands::doBlast(std::list<Entity*>& entList,float x, float y){


    std::list<Entity*>::iterator it;
    for (it = entList.begin(); it != entList.end(); ++it) {
    SDL_FPoint master=(SDL_FPoint){x,y},
                slave=(*it)->getPos();
        SDL_FPoint forceVec=PhysicsAux::blastVector(master,slave,5000000);

        PhysicsAux::accelerateEntity((*it),forceVec);
}

}
void PhysicsCommands::orbit(std::list<Entity*>& entList,float x, float y){


    std::list<Entity*>::iterator it;
    for (it = entList.begin(); it != entList.end(); ++it) {
    SDL_FPoint master=(SDL_FPoint){x,y},
                slave=(*it)->getPos();
        SDL_FPoint forceVec=PhysicsAux::gravVector(master,slave,1000000,(*it)->getMass());
        PhysicsAux::accelerateEntity((*it),forceVec);

}

}
void PhysicsCommands::homming(std::list<Entity*>& entList,float x, float y){

    std::list<Entity*>::iterator it;
    for (it = entList.begin(); it != entList.end(); ++it) {
    SDL_FPoint master=(SDL_FPoint){x,y},
                slave=(*it)->getPos();
        SDL_FPoint newVec=Aux::makeUnitVector(slave,master);
        Aux::scaleVec(&newVec,homingSpeed);

        (*it)->setVec(newVec);


}
}


float PhysicsCommands::getAverageSpeed(std::list<Entity*>& entList){
    float speedSum=0;
    int totalBodies=0;
        std::list<Entity*>::iterator it;
            for (it = entList.begin(); it != entList.end(); ++it) {

                speedSum+=GVector::getNorm((*it)->getVec());
                totalBodies++;

        }
        return speedSum/totalBodies;

}


float PhysicsCommands::getAverageQuality(std::list<Entity*>& entList){
    float qualitySum=0;
    int totalBodies=0;
        std::list<Entity*>::iterator it;
            for (it =entList.begin(); it != entList.end(); ++it) {

                qualitySum+=(*it)->getQuality();
                totalBodies++;

        }
        return qualitySum/totalBodies;
}
float PhysicsCommands::getTotalEnergy(std::list<Entity*>& entList){
    float energySum=0;
        std::list<Entity*>::iterator it;
            for (it = entList.begin(); it != entList.end(); ++it) {

                energySum+=(*it)->getTotalEnergy();

        }
        std::cout<<"Energia total: "<<energySum<<"\n";
        return energySum;
}
