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
std::list<GLauncher*> mLauncherList;
std::list<Grenade*> missileList;
Entity* worldMassParticle;
SDL_Color bgrclr;
float maxSpeed, maxSize, ammount,maxMass, airDensity,maxcharge;
int thetime,mouseX,mouseY,genCount;
int pause,rendering,collisions,selection,gravity,drag,electricity;
void keyboard(SDL_Event event);
void populateEntityList(int ammount);
void teleportEntityList(float x, float y);
void makeSelection();
void generationHandling();


int processBulletChoice(caliber* caliber);

void shootGuns();
void monitorGuns();
void monitorGrenades();
void monitorMissiles();
void cleanGrenades();
void explodeGrenades();
void attentionEveryone();
void freezeEveryone();
void processGunChoice(float x,float y);
void printGunMenu();
void printSpeedsAndPos();
void spawnGun(std::string filePath,float x,float y,caliber bType);

void spawnGLauncher(float x,float y);

void spawnMLauncher(GLauncher* mlauncher,float x,float y);

void printSimVarsAndStats();
void printKeyboardHelp();


void destroyEntities();
void destroyGuns();
void processDeletion();

public:
InteractiveSim(float maxSpeed,float maxSize,int ammount,float maxMass,float maxcharge);
InteractiveSim();
~InteractiveSim();
int init(float maxSpeed,float maxSize,int ammount,float maxMass,float maxcharge);
void mainLoop();
void handleToggles(const Uint8* KEYS);
void handleContPresses(const Uint8* KEYS);
void doRendering();
static InteractiveSim* parseGame();
static InteractiveSim* defaultGame();
void handleEntities();
};
#endif
