#ifndef PET_H
#define PET_H


#define DYINGCOUNTERTHIRST 5
#define DYINGCOUNTERHUNGER 20
#define DYINGCOUNTERSLEEP 100
#define HOLDINGPEEDYINGCOUNTER 10
#define HOLDINGPOODYINGCOUNTER 40

#define PEE_TOLERANCE_COUNTER 10
#define POO_TOLERANCE_COUNTER 40

#define DIGESTIONCOUNTER 10
#define SLEEPCOUNTER 30
#define HYDRATIONCOUNTER 10



#define SLEEPING_ENERGY_SCORE 50
#define SLEEPING_HUNGER_SCORE 10
#define SLEEPING_THIRST_SCORE 10


#define DIGESTION_HUNGER_SCORE 30
#define DIGESTION_THIRST_SCORE 10

#define HYDRATION_THIRST_SCORE 50

#define PLAY_BOREDOM_SCORE 60
#define PLAY_THIRST_SCORE 50
#define PLAY_HUNGER_SCORE 30

#define TREATMENT_SCORE 60

#define HEALTHDECAY 2
#define ENERGYDECAY 6
#define THIRSTDECAY 4
#define HUNGERDECAY 2
#define BOREDOMDECAY 2


typedef struct Animal{

    char* name;
    int health,
        hunger,
        boredom,
        thirst,
        energy,

        age,

        digestionCounter,
        digesting,

        sleepCounter,
        sleeping,

        hydrationCounter,
        hydrating,

        dyingCounter,
        dying,


        gotPee,
        peeToleranceCounter,
        holdingPee,
        gotPoo,
        pooToleranceCounter,
        holdingPoo,

        dead;

    int maxHealth,
        maxHunger,
        maxBoredom,
        maxThirst,
        maxEnergy;




}Animal;


int paused;


void petCare(Animal* an,int option);

void petCareLoop(Animal* an);

void petDecayLoop(Animal* an);

void spawnAnimal(Animal* an,int health,int thirst,int boredom, int hunger, int energy,char* name);

void handleDigestion(Animal * an);

void handleSleeping(Animal * an);

void handleDying(Animal * an);

void handleHydration(Animal * an);

void handleExcretion(Animal *an);


void handleBodyFunctions(Animal * an);
#endif
