#include "Include/preprocessorStuff.h"

char *cmdLabels[] = {
                        "Feed",
                        "Play",
                        "Quench",
                        "Heal",
                        "Poo/Pee",
                        "Rest",
                        "(un)Pause",
                        "Home",
                  };
char *homeLabels[] = {
                    "Commands",
                    "Stats",
                    "Pet",


                  };
char *goHomeLabels[] = {
                        "Go Home",
                  };


int main(int argc, char** argv){

char* name;


if(argc<2){

    name="Francisco";

}
else{

    name=argv[1];


}

Game game;
game.mode=0;
game.paused=0;
game.online=1;
game.an=malloc(sizeof(Animal));
game.buffs= malloc(sizeof(char*)*NUM_OF_BUFFERS);
game.needs=malloc(sizeof(WINDOW*)*(NUM_OF_WINDOWS));

game.pMenus=malloc(sizeof(PackagedMenu)*NUM_OF_MODES);
game.menus=malloc(sizeof(MENU*)*NUM_OF_MODES);

int nCmd = ARRAY_SIZE(cmdLabels),
    nHome = ARRAY_SIZE(homeLabels),
    nGoHome = ARRAY_SIZE(goHomeLabels);

ITEM** cmdItems = (ITEM **)calloc(nCmd + 1, sizeof(ITEM *)),
        **homeItems = (ITEM **)calloc(nHome + 1, sizeof(ITEM *)),
        **goHomeItems = (ITEM **)calloc(nGoHome + 1, sizeof(ITEM *));

initscr();
start_color();
initAllColors();
halfdelay(1);
noecho();
curs_set(0);

initWindows(game.needs);
initBuffers(game.an,game.buffs);
int baseStat=840;
spawnAnimal(game.an,baseStat,baseStat,baseStat,baseStat,baseStat*4,argv[1]);







    initMenu(&game.pMenus[0],&game.menus[0],nHome,game.needs[2],homeFunc,homeLabels,homeItems);

    initMenu(&game.pMenus[1],&game.menus[1],nCmd,game.needs[2],cmdFunc,cmdLabels,cmdItems);

    initMenu(&game.pMenus[2],&game.menus[2],nGoHome,game.needs[11],goHomeFunc,goHomeLabels,goHomeItems);


    initMenu(&game.pMenus[3],&game.menus[3],nGoHome,game.needs[11],goHomeFunc,goHomeLabels,goHomeItems);

showTitleScreen(game.needs[0],game.buffs[2],0,0);

 pthread_create(&game.biology,NULL,petDecayLoop,(game.an));
 pthread_detach(game.biology);
 pthread_create(&game.alert,NULL,flashingDyingAlert,game.an);
 pthread_detach(game.alert);


    gameLoop(&game);

    destroyGame(&game);

return 0;
}
