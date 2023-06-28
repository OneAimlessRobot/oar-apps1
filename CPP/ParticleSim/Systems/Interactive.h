#ifndef INT_H
#define INT_H
#define WIDTH 800
#define HEIGHT 600
#define FRAMERATE 60.0
constexpr int selectFrameInt= 180;
constexpr int addMoreInt= 60;
constexpr int howManyToAdd= 5;
constexpr int homingSpeed= 5;
class Interactive{
private:
SDL_Window* win;
Collider* arena;
SDL_Renderer* ren;
SDL_Texture * bgr,*ents;
std::list<Entity*> entList;
std::list<Gun*> gunList;
SDL_Color bgrclr;
SDL_bool pause,rendering,collisions,selection;
float maxSpeed, maxSize, ammount,maxMass, airDensity;
int thetime,mouseX,mouseY,genCount;
void keyboard(SDL_Event event);
void handleCollisions();
void orbit();
void handleInterparticleCollisions();
void handleCollisionsWithArena();
void homming();
void handleForces();
void handleDrag();
void printSpeedsAndPos();
void generationHandling();
void makeSelection();
void addMore();
float getAverageSpeed();
float getAverageQuality();
float getTotalEnergy();
void destroyGuns();
void monitorGuns();
void shootGuns();
void spawnGun(float reloadTime,int capacity,float force,float barrelLen,float x,float y);
public:
Interactive(float maxSpeed,float maxSize,int ammount,float maxMass,float airDensity);
~Interactive();
void init(float maxSpeed,float maxSize,int ammount,float maxMass,float airDensity);
void initMovements();
void mainLoop();
void handleToggles(const Uint8* KEYS);
void handleContPresses(const Uint8* KEYS);
void doRendering();
void handleMovements();


};

#endif
