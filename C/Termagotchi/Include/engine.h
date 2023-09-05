
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
        gotPoo,

        dead;

    int maxHealth,
        maxHunger,
        maxBoredom,
        maxThirst,
        maxEnergy;




}Animal;

void incAndTruncateNum(int* var,int sign,int value,int inc);
int getRandomInteger(int min, int max);


void printASCII(const char *end, const char *start, int dt);

char* animalStatHud(Animal animal);
char* generateStatBar(int stat,int maxStat,int step,const char* title);
void makeWinWithText(WINDOW* win,char* text,int x, int y);
char* getASCII(const char *end, const char *start, int dt);
