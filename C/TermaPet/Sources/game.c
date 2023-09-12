
#include "../Include/preprocessorStuff.h"

void gameLoop(Game* game){



	while(game->online && !game->an->dead)
	{

        clearAll(game);
		refreshAll(game);
		doupdate();
		updateGraphics(game);
		refreshAll(game);
		        doupdate();

        input(game);
        postCurrMenu(game);

	}



}
void destroyGame(Game*game){


destroyMenu(&game->pMenus[0]);
destroyMenu(&game->pMenus[1]);
destroyMenu(&game->pMenus[2]);
destroyMenu(&game->pMenus[3]);


nocbreak();

if(game->online){
bkgd(COLOR_PAIR(32));
makeWinWithText(stdscr,game->buffs[0],0,0);
refresh();
getch();
}
erase();
refresh();
bkgd(COLOR_PAIR(31));
makeWinWithText(stdscr,"Adeus! Espero que se lembrem de fazer com que isto grave no futuro!\n",0,0);
refresh();
getch();

killAllWindows(game->needs);
killAllBuffs(game->buffs);
endwin();


}
void input(Game*game){

    int slot=game->mode;
    int c=(int) wgetch(menu_win(game->menus[slot]));
        switch(c)
	    {	case KEY_DOWN:
		        menu_driver((game->menus[slot]), REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver((game->menus[slot]), REQ_UP_ITEM);
				break;
			case 10:
			{	ITEM *cur;
				void (*p)(Game*,int);
				cur = current_item(game->menus[slot]);
				p = item_userptr(cur);
				p(game,item_index(cur));
				pos_menu_cursor(game->menus[slot]);
				break;
			}
			case 'q':
			{
                game->online=0;
                break;
			}
            default:
                break;
		}

}


void cmdFunc(Game*game,int option){
    beep();
    if(option < 6){
    if(!(game->paused)){
    petCare(game->an,option);
    }
    }
    else if(option==6){

        if(game->paused){
            game->paused=0;
        }
        else{
            game->paused=1;
        }
    }
    else if(option==7){

        game->mode=0;

    }

}

void homeFunc(Game*game,int option){

game->mode=option+1;


}


void goHomeFunc(Game*game,int option){

    game->mode=0;


}
void updateGraphics(Game* game){

enum modes currMode;

currMode=game->mode;
switch(currMode){
case commands:


    displayHud(game);
break;
case stats:

    statsGraphics(game);

break;

case pet:

    petGraphics(game);

break;
default:
break;



}

}


void postCurrMenu(Game*game){

    for(int i=0;i<NUM_OF_MODES-2;i++){
        if(i==game->mode){
            post_menu(game->menus[i]);
            }
        else{
            unpost_menu(game->menus[i]);
        }
        }




}


void petGraphics(Game* game){
if(game->paused){

    wbkgd(game->needs[3],COLOR_PAIR(31));
    makeWinWithText(game->needs[3],game->buffs[1],0,0);

 }
 else if(game->an->dying){
    wbkgd(game->needs[3],COLOR_PAIR(32));
    if(!(game->an->energy>0)){
    makeWinWithText(game->needs[3],game->buffs[1],0,0);
    }
    if(game->an->holdingPee||game->an->holdingPoo){
    makeWinWithText(game->needs[3],game->buffs[5],0,0);
    }
    else{

    makeWinWithText(game->needs[3],game->buffs[6],0,0);

    }
}
 else{
    wbkgd(game->needs[3],COLOR_PAIR(9));
    if(game->an->holdingPee||game->an->holdingPoo){
    makeWinWithText(game->needs[3],game->buffs[5],0,0);
    }
    else if(game->an->sleeping){
    makeWinWithText(game->needs[3],game->buffs[1],0,0);
    }
    else{
    makeWinWithText(game->needs[3],game->buffs[7],0,0);
    }


 }
}

void statsGraphics(Game* game){


 free(game->buffs[3]);
 game->buffs[3]=animalStatHud(*(game->an));
    wbkgd(game->needs[1],COLOR_PAIR(31));
 makeWinWithText(game->needs[1],game->buffs[3],0,0);
}
void displayHud(Game * game){
    if(!(game->an->boredom>0)){
    wbkgd(game->needs[5],COLOR_PAIR(8));
     makeWinWithText(game->needs[5],"BORED!\n",0,0);

    }
    else{

    wbkgd(game->needs[5],COLOR_PAIR(7));

     makeWinWithText(game->needs[5],"      \n",0,0);

    }


    if(!(game->an->hunger>0)){
    wbkgd(game->needs[6],COLOR_PAIR(2));
     makeWinWithText(game->needs[6],"HUNGRY!\n",0,0);

    }
    else{

    wbkgd(game->needs[6],COLOR_PAIR(7));
     makeWinWithText(game->needs[6],"       \n",0,0);


    }

    if(!(game->an->thirst>0)){
    wbkgd(game->needs[7],COLOR_PAIR(3));
     makeWinWithText(game->needs[7],"THIRSTY!\n",0,0);

    }
    else{

    wbkgd(game->needs[7],COLOR_PAIR(7));
     makeWinWithText(game->needs[7],"       \n",0,0);


    }

    if(!(game->an->energy>0)){
    wbkgd(game->needs[8],COLOR_PAIR(4));
     makeWinWithText(game->needs[8],"TIRED!\n",0,0);

    }
    else{

    wbkgd(game->needs[8],COLOR_PAIR(7));
     makeWinWithText(game->needs[8],"      \n",0,0);


    }

    if(game->an->gotPoo){
    wbkgd(game->needs[9],COLOR_PAIR(5));
     makeWinWithText(game->needs[9],"POO!\n",0,0);

    }
    else{
    wbkgd(game->needs[9],COLOR_PAIR(7));

     makeWinWithText(game->needs[9],"    \n",0,0);


    }
    if(game->an->gotPee){

    wbkgd(game->needs[10],COLOR_PAIR(6));
     makeWinWithText(game->needs[10],"PEE!\n",0,0);

    }
    else{

    wbkgd(game->needs[10],COLOR_PAIR(7));
     makeWinWithText(game->needs[10],"    \n",0,0);


    }
    if(game->an->sleeping){

    wbkgd(game->needs[4],COLOR_PAIR(1));
        makeWinWithText(game->needs[4],"SLEEPING!\n",0,0);

    }
    else{
    wbkgd(game->needs[4],COLOR_PAIR(7));

        makeWinWithText(game->needs[4],"         \n",0,0);


    }

}

void flashingDyingAlert(Animal* an){
    while(!an->dead){
        if(an->dying){

            usleep((int)(TICK_DURATION_MICROSECS*GAME_SMOOTHNESS_FACTOR));

            flash();
        }

    }



}
void clearAll(Game* game){

enum modes currMode;

currMode=game->mode;
switch(currMode){

case home:

for(int i=1;i<11;i++){
wbkgdset(game->needs[i],COLOR_PAIR(7));
if(i!=2){

    werase(game->needs[i]);
    wprintw(game->needs[i],"");
    touchwin(game->needs[i]);
}
}
break;

case commands:
for(int i=1;i<11;i++){
wbkgdset(game->needs[i],COLOR_PAIR(7));
if(i==1||i==3||i==11){

    werase(game->needs[i]);
    wprintw(game->needs[i],"");
    touchwin(game->needs[i]);
}
}


break;

case stats:

for(int i=2;i<11;i++){
wbkgdset(game->needs[i],COLOR_PAIR(7));

    werase(game->needs[i]);
    wprintw(game->needs[i],"");
    touchwin(game->needs[i]);

}

break;

case pet:
for(int i=1;i<11;i++){
wbkgdset(game->needs[i],COLOR_PAIR(7));
if(i!=3){

    werase(game->needs[i]);
    wprintw(game->needs[i],"");
    touchwin(game->needs[i]);

}
}
break;


default:
break;



}
}
void refreshAll(Game*game){


enum modes currMode;

currMode=game->mode;
switch(currMode){

case home:
wnoutrefresh(game->needs[2]);

break;

case commands:
wnoutrefresh(game->needs[2]);

for(int i=4;i<11;i++){

wnoutrefresh(game->needs[i]);

}


break;

case stats:
wnoutrefresh(game->needs[1]);


break;

case pet:
wnoutrefresh(game->needs[3]);


break;

default:
break;



}

}
