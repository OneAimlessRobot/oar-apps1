#ifndef MGR_H
#define MGR_H
#define WIDTH 800
#define HEIGHT 600
#define FRAMERATE 60.0
class ScreenSaverSystem{
private:

SDL_Window* win;
Collider* arena;
SDL_Renderer* ren;
SDL_Texture * bgr,*ents;
std::list<Entity*> entList;
SDL_Color bgrclr;
public:
ScreenSaverSystem(float maxSpeed,float maxSize,int ammount);
~ScreenSaverSystem();
void initMovements();
void mainLoop();
void handleKeyboard();
void doRendering();
void handleMovements();


};

#endif