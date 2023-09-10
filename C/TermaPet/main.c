#include "Include/preprocessorStuff.h"

void graphics(Animal* an,char** buffs,WINDOW** needs);
void displayHud(Animal * an,WINDOW** needs);
void cmdFunc(Animal* an,int option);
void input(MENU**menu,Animal*an,int*online);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
void flashingDyingAlert(Animal* an);
void checkValue(int *isZero);

int main(int argc, char** argv){


paused=0;
int online=1;


char* name;


if(argc<2){

    name="Francisco";

}
else{

    name=argv[1];

}
Animal an;
PackagedMenu pMenu;
	MENU *cmdMenu;


char** buffs= malloc(sizeof(char*)*NUM_OF_BUFFERS);
WINDOW** needs=malloc(sizeof(WINDOW*)*(NUM_OF_WINDOWS));



initscr();
start_color();
initAllColors();
keypad(stdscr,TRUE);
halfdelay(1);
refresh();
noecho();
curs_set(0);
erase();

int baseStat=840;
spawnAnimal(&an,baseStat,baseStat,baseStat,baseStat,baseStat*4,name);

initWindows(needs);
initBuffers(&an,buffs);


showTitleScreen(needs[0],buffs[2],0,0);


int nCmd = ARRAY_SIZE(cmdMenuLabels);

ITEM** cmdItems = (ITEM **)calloc(nCmd + 1, sizeof(ITEM *));

    initMenu(&pMenu,&cmdMenu,nCmd,needs[2],cmdFunc,cmdMenuLabels,cmdItems);

pthread_t biologyWorker,alertWorker;

 pthread_create(&biologyWorker,NULL,petDecayLoop,(&an));
 pthread_detach(biologyWorker);
 pthread_create(&alertWorker,NULL,flashingDyingAlert,&an);
 pthread_detach(alertWorker);


	while(online && !an.dead)
	{
        input(&cmdMenu,&an,&online);

	print_in_middle(needs[2], 1, 0, 10, "Commands:", COLOR_PAIR(33));

		graphics(&an,buffs,needs);
	refresh();

post_menu(cmdMenu);
wrefresh(needs[2]);

	}

destroyMenu(&pMenu);

nocbreak();

if(online){
bkgd(COLOR_PAIR(32));
makeWinWithText(stdscr,buffs[0],0,0);
refresh();
getch();
}
killAllWindows(needs);
killAllBuffs(buffs);
endwin();

return 0;
}

void input(MENU**menu,Animal*an,int*online){
    int c=(int) wgetch(menu_win(*menu));
        switch(c)
	    {	case KEY_DOWN:
		        menu_driver(*menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(*menu, REQ_UP_ITEM);
				break;
			case 10:
			{	ITEM *cur;
				void (*p)(Animal*,int);
				cur = current_item(*menu);
				p = item_userptr(cur);
				p(an,item_index(cur));
				pos_menu_cursor(*menu);
				break;
			}
			case 'q':
			{
                *online=0;
                break;
			}
            default:
                break;
		}

}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{	int x, y;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
		x = startx;
		y = starty;
	if(width == 0)
		width = 80;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

void cmdFunc(Animal* an,int option){
    beep();
    if(option < 6){
    if(!(paused)){
    petCare(an,option);
    }
    else{
    return;
    }
    }
    else{

        if(paused){
            paused=0;
        }
        else{
            paused=1;
        }
    }

}

void graphics(Animal* an,char** buffs,WINDOW** needs){
if(paused){

    wbkgd(needs[3],COLOR_PAIR(31));
    makeWinWithText(needs[3],buffs[1],0,0);

 }
 else if(an->dying){
    wbkgd(needs[3],COLOR_PAIR(32));
    if(!(an->energy>0)){
    makeWinWithText(needs[3],buffs[1],0,0);
    }
    if(an->holdingPee||an->holdingPoo){
    makeWinWithText(needs[3],buffs[5],0,0);
    }
    else{

    makeWinWithText(needs[3],buffs[6],0,0);

    }
}
 else{
    wbkgd(needs[3],COLOR_PAIR(9));
    if(an->holdingPee||an->holdingPoo){
    makeWinWithText(needs[3],buffs[5],0,0);
    }
    else if(an->sleeping){
    makeWinWithText(needs[3],buffs[1],0,0);
    }
    else{
    makeWinWithText(needs[3],buffs[7],0,0);
    }


 }
 wrefresh(needs[3]);
 free(buffs[3]);
 buffs[3]=animalStatHud(*an);
 makeWinWithText(needs[1],buffs[3],0,0);
 wrefresh(needs[1]);
 displayHud(an,needs);

}
void displayHud(Animal * an,WINDOW** needs){
    if(!(an->boredom>0)){
    wbkgd(needs[5],COLOR_PAIR(8));
     makeWinWithText(needs[5],"BORED!\n",0,0);

    }
    else{

    wbkgd(needs[5],COLOR_PAIR(7));

     makeWinWithText(needs[5],"      \n",0,0);

    }

    wrefresh(needs[5]);

    if(!(an->hunger>0)){
    wbkgd(needs[6],COLOR_PAIR(2));
     makeWinWithText(needs[6],"HUNGRY!\n",0,0);

    }
    else{

    wbkgd(needs[6],COLOR_PAIR(7));
     makeWinWithText(needs[6],"       \n",0,0);


    }

    wrefresh(needs[6]);
    if(!(an->thirst>0)){
    wbkgd(needs[7],COLOR_PAIR(3));
     makeWinWithText(needs[7],"THIRSTY!\n",0,0);

    }
    else{

    wbkgd(needs[7],COLOR_PAIR(7));
     makeWinWithText(needs[7],"       \n",0,0);


    }

    wrefresh(needs[7]);
    if(!(an->energy>0)){
    wbkgd(needs[8],COLOR_PAIR(4));
     makeWinWithText(needs[8],"TIRED!\n",0,0);

    }
    else{

    wbkgd(needs[8],COLOR_PAIR(7));
     makeWinWithText(needs[8],"      \n",0,0);


    }

    wrefresh(needs[8]);
    if(an->gotPoo){
    wbkgd(needs[9],COLOR_PAIR(5));
     makeWinWithText(needs[9],"POO!\n",0,0);

    }
    else{
    wbkgd(needs[9],COLOR_PAIR(7));

     makeWinWithText(needs[9],"    \n",0,0);


    }
    wrefresh(needs[9]);
    if(an->gotPee){

    wbkgd(needs[10],COLOR_PAIR(6));
     makeWinWithText(needs[10],"PEE!\n",0,0);

    }
    else{

    wbkgd(needs[10],COLOR_PAIR(7));
     makeWinWithText(needs[10],"    \n",0,0);


    }
    wrefresh(needs[10]);
    if(an->sleeping){

    wbkgd(needs[4],COLOR_PAIR(1));
        makeWinWithText(needs[4],"SLEEPING!\n",0,0);

    }
    else{
    wbkgd(needs[4],COLOR_PAIR(7));

        makeWinWithText(needs[4],"         \n",0,0);


    }
    wrefresh(needs[4]);


}

void flashingDyingAlert(Animal* an){
    while(!an->dead){
        if(an->dying){

            flash();
            usleep((int)(TICK_DURATION_MICROSECS*GAME_SMOOTHNESS_FACTOR));
        }

    }



}

void checkValue(int * isZero){

    while(true){
        if(*isZero==0){

            printf("SIMMM!!!!!\n");
        }

    }

}
