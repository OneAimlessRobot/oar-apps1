#ifndef INT_H
#define INT_H
class InteractiveSim{
private:
SDL_Window* win;
Collider* arena;
SDL_Renderer* ren;
SDL_Texture * bgr,*ents;
std::list<Entity*> entList;
std::list<Gun*> gunList;
std::list<GLauncher*> gLauncherList;
std::list<Grenade*> grenadeList;
Entity* worldMassParticle;
SDL_Color bgrclr;
float maxSpeed, maxSize, ammount,maxMass, airDensity;
int thetime,mouseX,mouseY,genCount;
int pause,rendering,collisions,selection,gravity,drag;
void keyboard(SDL_Event event);
void populateEntityList(int ammount);
void makeSelection();
void generationHandling();


void processBulletChoice(caliber* caliber);

void shootGuns();
void monitorGuns();
void monitorGrenades();
void explodeGrenades();
void processGunChoice(Gun * gun,float x,float y);
void printGunMenu();
void printSpeedsAndPos();
void spawnGun(Gun* gun,std::string filePath,float x,float y,caliber bType);

void spawnGLauncher(GLauncher* glauncher,float x,float y);

void printSimVarsAndStats();
void printKeyboardHelp();


void destroyEntities();
void destroyGuns();
void processDeletion();

public:
InteractiveSim(float maxSpeed,float maxSize,int ammount,float maxMass);
InteractiveSim();
~InteractiveSim();
int init(float maxSpeed,float maxSize,int ammount,float maxMass);
void mainLoop();
void handleToggles(const Uint8* KEYS);
void handleContPresses(const Uint8* KEYS);
void doRendering();
static InteractiveSim* parseGame();
static InteractiveSim* defaultGame();
void handleEntities();
};
#endif
