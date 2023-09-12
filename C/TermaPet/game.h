#ifndef GAME_H
#define GAME_H
typedef struct Game{

Animal* an;
char** buffs, animalName[1024];
WINDOW** needs;
int mode,online,paused;
PackagedMenu* pMenus;
MENU** menus;
pthread_t biology,alert;

}Game;
Game* initGame(char* animalName);

void gameLoop(Game* game);

void destroyGame(Game*game);
void updateGraphics(Game* game);

void statsGraphics(Game* game);
void petGraphics(Game*game);
void displayHud(Game*game);

void clearAll(Game*game);
void refreshAll(Game*game);

void cmdFunc(Game*game,int option);
void homeFunc(Game*game,int option);
void goHomeFunc(Game*game,int option);
void postCurrMenu(Game*game);

void input(Game*game);
void flashingDyingAlert(Animal* an);
#endif
