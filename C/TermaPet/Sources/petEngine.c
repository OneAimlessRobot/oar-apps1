#include <unistd.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "../Include/aux.h"
#include "../Include/petEngine.h"

void handleBodyFunctions(Animal * an){
if(!an->dying){
    if(!an->gotPee&&!an->gotPoo){
        if(an->sleeping){


        handleSleeping(an);

        }
        else{

            if(an->hydrating){
                handleHydration(an);
            }

            if(an->digesting){
                handleDigestion(an);

            }



        }

    }
    else{
        handleExcretion(an);

    }
    }
else{
    an->dyingCounter--;
    if(an->dyingCounter<=0){

        an->dead=1;
    }
}

    if(!(an->health>0)||!(an->energy>0)||!(an->thirst>0)||!(an->hunger>0)||!an->peeToleranceCounter||!an->pooToleranceCounter){
    if(!an->dying){

        an->dyingCounter=INT_MAX;
        an->dying=1;
	wprintf(stdscr,"%d\n",an->peeToleranceCounter);
    }
    handleDying(an);
    }

}

void handleDying(Animal * an){


    if(!(an->health>0)){

        an->dead=1;
        return;
    }
    if(!(an->energy>0)){

        an->dyingCounter=min(an->dyingCounter,DYINGCOUNTERSLEEP);

    }
    if(!(an->hunger>0)){
        an->dyingCounter=min(an->dyingCounter,DYINGCOUNTERHUNGER);


    }
    if(an->holdingPoo){
        an->dyingCounter=min(an->dyingCounter,HOLDINGPOODYINGCOUNTER);

    }

    if(an->holdingPee){

        an->dyingCounter=min(an->dyingCounter,HOLDINGPEEDYINGCOUNTER);

    }
    if(!(an->thirst>0)){

        an->dyingCounter=min(an->dyingCounter,DYINGCOUNTERTHIRST);


    }





}
void handleExcretion(Animal *an){

if(an->gotPee&&!an->holdingPee){

    an->holdingPee=1;
    an->peeToleranceCounter=PEE_TOLERANCE_COUNTER;
    return;
}


if(an->gotPoo&&!an->holdingPoo){

    an->holdingPoo=1;
    an->pooToleranceCounter=POO_TOLERANCE_COUNTER;
    return;
}
if(an->holdingPoo){

    incAndTruncateInt(&an->pooToleranceCounter,0,0,1);



}
if(an->holdingPee){


    incAndTruncateInt(&an->peeToleranceCounter,0,0,1);



}
if(!an->gotPee){

    an->peeToleranceCounter=PEE_TOLERANCE_COUNTER;
}
if(!an->gotPoo){

    an->pooToleranceCounter=POO_TOLERANCE_COUNTER;
}
}
void handleSleeping(Animal * an){

    an->digesting=0;
    an->hydrating=0;
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

    an->thirst+=HYDRATION_THIRST_SCORE;
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

    an->hunger+=DIGESTION_HUNGER_SCORE;
    incAndTruncateNum(&an->thirst,1,an->maxThirst,DIGESTION_THIRST_SCORE);
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


void spawnAnimal(Animal * an,float health,float thirst,float boredom,float hunger, float energy,char* name){

an->health=an->maxHealth=health;
an->hunger=an->maxHunger=hunger;
an->thirst=an->maxThirst=thirst;
an->boredom=an->maxBoredom=boredom;
an->energy=an->maxEnergy=energy;

an->sleepCounter=SLEEPCOUNTER;
an->digestionCounter=DIGESTIONCOUNTER;
an->hydrationCounter=HYDRATIONCOUNTER;

an->peeToleranceCounter=PEE_TOLERANCE_COUNTER;
an->pooToleranceCounter=POO_TOLERANCE_COUNTER;

an->dyingCounter=INT_MAX-1;

an->digesting=an->hydrating=an->dying=an->dead=an->gotPee=an->gotPoo=an->sleeping=an->holdingPee=an->holdingPoo=an->age=0;

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
    if(!an->dying){
    
    incAndTruncateNum(&an->boredom,1,BASESTAT,PLAY_BOREDOM_SCORE);
    incAndTruncateNum(&an->energy,0,0,2*PLAY_BOREDOM_SCORE);
    incAndTruncateNum(&an->thirst,0,0,PLAY_THIRST_SCORE);
    incAndTruncateNum(&an->hunger,0,0,PLAY_HUNGER_SCORE);

    }
    break;
    case(2):
    an->hydrating=1;

        an->dying=0;
    break;
    case(3):
        incAndTruncateNum(&an->health,1,BASESTAT,TREATMENT_SCORE);

    break;
    case(4):
    if(an->gotPee){

    an->peeToleranceCounter=PEE_TOLERANCE_COUNTER;
        an->gotPee=0;
        an->holdingPee=0;
    }
    if(an->gotPoo){

    an->pooToleranceCounter=POO_TOLERANCE_COUNTER;
        an->gotPoo=0;
        an->holdingPoo=0;
    }
        an->dying=0;
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

int ageTicks=0;
while(1){
    if(!(paused)){
    handleBodyFunctions(an);
    usleep((int)(TICK_DURATION_MICROSECS));
    incAndTruncateNum(&an->boredom,0,0,BOREDOMDECAY);
    incAndTruncateNum(&an->health,0,0,HEALTHDECAY);
    incAndTruncateNum(&an->hunger,0,0,HUNGERDECAY);
    incAndTruncateNum(&an->thirst,0,0,THIRSTDECAY);
    incAndTruncateNum(&an->energy,0,0,ENERGYDECAY);
    ageTicks++;
    if(ageTicks==(int)AGE_TICK_DURATION){
        
        an->age++;
        ageTicks=0;
    
    }
    }
    }



}
