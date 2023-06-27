#ifndef INT_H
#define INT_H
#define WIDTH 800
#define HEIGHT 600
#define FRAMERATE 180.0
constexpr int selectFrameInt= 480;
constexpr int addMoreInt= 160;
constexpr int howManyToAdd= 5;
constexpr int homingSpeed= 5;
class Interactive{
private:
SDL_Window* win;
Collider* arena;
SDL_Renderer* ren;
SDL_Texture * bgr,*ents;
std::list<Entity*> entList;
SDL_Color bgrclr;
SDL_bool pause,rendering;
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
void printSpeedsAndPoss();
void makeSelection();
void addMore();
float getAverageSpeed();
float getAverageQuality();
public:
Interactive(float maxSpeed,float maxSize,int ammount,float maxMass,float airDensity);
~Interactive();
void initMovements();
void mainLoop();
void handleToggles(const Uint8* KEYS);
void handleContPresses(const Uint8* KEYS);
void doRendering();
void handleMovements();


};

#endif
