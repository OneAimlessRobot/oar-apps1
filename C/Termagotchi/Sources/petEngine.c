#include <unistd.h>
#include <ncurses.h>
#include <menu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/engine.h"
#include "../Include/petEngine.h"

void handleBodyFunctions(Animal * an){
if(!an->dying){
    if(!an->gotPee&&!an->gotPoo&&an->sleeping){
    handleSleeping(an);
    }
    if(!an->gotPoo&&an->digesting){
    handleDigestion(an);


    }
    if(!an->gotPoo&&!an->gotPee&&an->hydrating){

    handleHydration(an);
    }
    if(!an->health||!an->hunger||!an->thirst||!an->energy){

        handleDying(an);
    }

    }
else{

    incAndTruncateNum(&an->dyingCounter,0,0,1);
    if(!an->dyingCounter){

        an->dead=1;
    }

}


}

void handleDying(Animal * an){


    if(!an->health){

        an->dead=1;
        return;
    }
        an->dying=1;
    if(!an->energy){

        an->dyingCounter=DYINGCOUNTERSLEEP;

    }
    if(!an->hunger){
        an->dyingCounter=DYINGCOUNTERHUNGER;

    }
    if(!an->thirst){
        an->dyingCounter=DYINGCOUNTERTHIRST;

    }





}

void handleSleeping(Animal * an){

    an->health+=HEALTHDECAY;
    an->energy+=SLEEPING_ENERGY_SCORE;
    an->sleepCounter--;
    if(an->energy>an->maxEnergy){

        an->energy=an->maxEnergy;
        an->sleepCounter=SLEEPCOUNTER;
        an->sleeping=0;

    }
    else if(an->sleepCounter==0){

    an->sleepCounter=SLEEPCOUNTER;
    an->sleeping=0;
    }


}


void handleHydration(Animal * an){

    an->thirst+=30;
    an->hydrationCounter--;
    if(an->thirst>=an->maxThirst){

        an->thirst=an->maxThirst;
        an->hydrationCounter=HYDRATIONCOUNTER;
        an->hydrating=0;
        an->gotPee=1;

    }
    else if(an->hydrationCounter==0){

        an->hydrationCounter=HYDRATIONCOUNTER;
        an->hydrating=0;
        an->gotPee=1;

    }
}


void handleDigestion(Animal * an){

    an->hunger+=40;
    an->digestionCounter--;
    if(an->hunger>=an->maxHunger){

        an->hunger=an->maxHunger;
        an->digestionCounter=DIGESTIONCOUNTER;
        an->gotPoo=1;
        an->digesting=0;

    }
    else if(an->digestionCounter==0){

        an->digestionCounter=DIGESTIONCOUNTER;
        an->digesting=0;
        an->gotPoo=1;

    }



}


void spawnAnimal(Animal * an,int health,int thirst,int boredom,int hunger, int energy,const char* name){

an->health=an->maxHealth=health;
an->hunger=an->maxHunger=hunger;
an->thirst=an->maxThirst=thirst;
an->boredom=an->maxBoredom=boredom;
an->energy=an->maxEnergy=energy;

an->sleepCounter=SLEEPCOUNTER;
an->digestionCounter=DIGESTIONCOUNTER;
an->hydrationCounter=HYDRATIONCOUNTER;

an->digesting=an->hydrating=an->dyingCounter=an->dying=an->dead=an->gotPee=an->gotPoo=an->sleeping=an->age=0;

an->name=name;

}

void petCare(Animal* an,int option){
    if(!an->sleeping){
    switch(option){

    case(0):
        an->digesting=1;
        an->dying=0;
    break;
    case(1):
    an->boredom+=PLAY_BOREDOM_SCORE;
    an->energy-=2*PLAY_BOREDOM_SCORE;
    an->thirst-=4*PLAY_BOREDOM_SCORE;
    an->hunger-=PLAY_BOREDOM_SCORE;

    if(an->boredom>=an->maxBoredom){

        an->boredom=an->maxBoredom;

    }
    break;
    case(2):
    an->hydrating=1;

        an->dying=0;
    break;
    case(3):
    an->health+=TREATMENT_SCORE;
    if(an->health>=an->maxHealth){

        an->health=an->maxHealth;

    }
    break;
    case(4):
        an->gotPee=0;
        an->gotPoo=0;
    break;
    case(5):
    an->sleeping=1;
        an->dying=0;
    break;
    default:
    break;
    }
    }


}
void petDecayLoop(Animal* an){

while(true){
    if(!paused){
    handleBodyFunctions(an);
    usleep(1000000);
    incAndTruncateNum(&an->boredom,0,0,BOREDOMDECAY);
    incAndTruncateNum(&an->health,0,0,HEALTHDECAY);
    incAndTruncateNum(&an->hunger,0,0,HUNGERDECAY);
    incAndTruncateNum(&an->thirst,0,0,THIRSTDECAY);
    incAndTruncateNum(&an->energy,0,0,ENERGYDECAY);
    an->age++;
    }
    }



}
