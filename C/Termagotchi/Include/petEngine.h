
#define DYINGCOUNTERTHIRST 5
#define DYINGCOUNTERHUNGER 20
#define DYINGCOUNTERSLEEP 100


#define DIGESTIONCOUNTER 10
#define SLEEPCOUNTER 30
#define HYDRATIONCOUNTER 10



#define SLEEPING_ENERGY_SCORE 50
#define SLEEPING_HUNGER_SCORE 10
#define SLEEPING_DIGESTION_SCORE 30
#define SLEEPING_HYDRATION_SCORE 10


#define HUNGER_ENERGY_SCORE 10
#define HUNGER_DIGESTION_SCORE 30
#define HUNGER_HYDRATION_SCORE 10

#define PLAY_BOREDOM_SCORE 60

#define TREATMENT_SCORE 60

#define HEALTHDECAY 2
#define ENERGYDECAY 6
#define THIRSTDECAY 4
#define HUNGERDECAY 2
#define BOREDOMDECAY 2



void petCare(Animal* an,int option);

void petCareLoop(Animal* an);

void petDecayLoop(Animal* an);

void spawnAnimal(Animal* an,int health,int thirst,int boredom, int hunger, int energy,const char* name);

void handleDigestion(Animal * an);

void handleSleeping(Animal * an);

void handleDying(Animal * an);

void handleHydration(Animal * an);

void handleExcretion(Animal *an);


void handleBodyFunctions(Animal * an);
