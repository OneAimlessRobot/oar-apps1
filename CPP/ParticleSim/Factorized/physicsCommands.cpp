#include <list>
#include <iterator>
#include "../Types/GVector.h"
#include "../Types/Entity.h"
#include "../Types/physicsAux.h"
#include "../Types/Collider.h"
#include "../aux.h"
#include "physicsCommands.h"





void PhysicsCommands::handleCollisions(int collisionsEnabled,std::list<Entity*> entList,std::list<Gun*> gunList){

    //broken. Maybe will fix
    if(collisionsEnabled){
      handleInterparticleCollisions<Entity>(entList);
    }

     handleCollisionsWithArena<Entity>(entList);
    handleCollisionsWithArena<Gun>(gunList);

}
void PhysicsCommands::handleForces(std::list<Entity*> entList,Collider* arena){

    handleDrag(entList, arena);

}
void PhysicsCommands::handleDrag(std::list<Entity*> entList,Collider* arena){


    std::list<Entity*>::iterator it;
    for (it = entList.begin(); it != entList.end(); ++it) {

        SDL_FPoint dragVec=PhysicsAux::dragNeutralWindVector((*it)->getVec(),(*it)->getDragConstant(),arena->getAirDensity());
        PhysicsAux::accelerateEntity((*it),dragVec);


}



}
void PhysicsCommands::handleMovements(int collisionsEnabled,std::list<Entity*> entList,Collider* arena,std::list<Gun*> gunList){

    handleForces(entList,arena);

    handleCollisions(collisionsEnabled,entList,gunList);



}
void PhysicsCommands::doBlast(std::list<Entity*> entList,float x, float y){


    std::list<Entity*>::iterator it;
    for (it = entList.begin(); it != entList.end(); ++it) {
    SDL_FPoint master=(SDL_FPoint){x,y},
                slave=(*it)->getPos();
        SDL_FPoint forceVec=PhysicsAux::blastVector(master,slave,5000000);

        PhysicsAux::accelerateEntity((*it),forceVec);
}

}
void PhysicsCommands::orbit(std::list<Entity*> entList,float x, float y){


    std::list<Entity*>::iterator it;
    for (it = entList.begin(); it != entList.end(); ++it) {
    SDL_FPoint master=(SDL_FPoint){x,y},
                slave=(*it)->getPos();
        SDL_FPoint forceVec=PhysicsAux::gravVector(master,slave,10000,(*it)->getMass());
        PhysicsAux::accelerateEntity((*it),forceVec);

}

}
void PhysicsCommands::homming(std::list<Entity*> entList,float x, float y){

    std::list<Entity*>::iterator it;
    for (it = entList.begin(); it != entList.end(); ++it) {
    SDL_FPoint master=(SDL_FPoint){x,y},
                slave=(*it)->getPos();
        SDL_FPoint newVec=Aux::makeUnitVector(slave,master);
        Aux::scaleVec(&newVec,homingSpeed);

        (*it)->setVec(newVec);


}


float PhysicsCommands::getAverageSpeed(std::list<Entity*> entList){
    float speedSum=0;
    int totalBodies=0;
        std::list<Entity*>::iterator it;
            for (it = entList.begin(); it != entList.end(); ++it) {

                speedSum+=GVector::getNorm((*it)->getVec());
                totalBodies++;

        }
        return speedSum/totalBodies;

}


float PhysicsCommands::getAverageQuality(std::list<Entity*> entList){
    float qualitySum=0;
    int totalBodies=0;
        std::list<Entity*>::iterator it;
            for (it =entList.begin(); it != entList.end(); ++it) {

                qualitySum+=(*it)->getQuality();
                totalBodies++;

        }
        return qualitySum/totalBodies;
}
float PhysicsCommands::getTotalEnergy(std::list<Entity*> entList){
    float energySum=0;
        std::list<Entity*>::iterator it;
            for (it = entList.begin(); it != entList.end(); ++it) {

                energySum+=(*it)->getTotalEnergy();

        }
        std::cout<<"Energia total: "<<energySum<<"\n";
        return energySum;
}
