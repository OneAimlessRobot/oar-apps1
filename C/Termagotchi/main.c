#include "Include/preprocessorStuff.h"

void graphics(Animal* an);
void displayHud(Animal * an);
void func(Animal* an,int option);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
void flashingDyingAlert(Animal* an);
void checkValue(int *isZero);

int main(int argc, char** argv){

char* name;

if(argc<2){

    name="Francisco";

}
else{

    name=argv[1];

}

int online=1;

paused=0;
initscr();
start_color();
initAllColors();

Animal an;
spawnAnimal(&an,500,500,500,500,2000,name);
erase();


initBuffers(&an);
initWindows();
keypad(stdscr,TRUE);
halfdelay(1);
refresh();
noecho();
curs_set(0);


pthread_t biologyWorker,alertWorker;

ITEM **my_items;
	int c;
	MENU *my_menu;
	int n_choices, i;




n_choices = ARRAY_SIZE(cmdMenu);

my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
for(i = 0; i < n_choices; ++i)
	{
	my_items[i] = new_item(cmdMenu[i], cmdMenu[i]);
		/* Set the user pointer */
		set_item_userptr(my_items[i], func);
	}

my_items[n_choices] = (ITEM *)NULL;

my_menu = new_menu((ITEM **)my_items);

menu_opts_off(my_menu, O_SHOWDESC);

keypad(menu, TRUE);

set_menu_win(my_menu, menu);
set_menu_sub(my_menu, derwin(menu, 0, 0, 3, 0));




set_menu_mark(my_menu, "");




 pthread_create(&biologyWorker,NULL,petDecayLoop,&an);
 pthread_detach(biologyWorker);
 pthread_create(&alertWorker,NULL,flashingDyingAlert,&an);
 pthread_detach(alertWorker);


	while(online && !an.dead)
	{
        c=getch();
        switch(c)
	    {	case KEY_DOWN:
		        menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case 10:
			{	ITEM *cur;
				void (*p)(Animal*,int);
				cur = current_item(my_menu);
				p = item_userptr(cur);
				p(&an,item_index(cur));
				pos_menu_cursor(my_menu);
				break;
			}
			case 'q':
			{
                online=0;
                break;
			}
            default:
                break;
		}
		graphics(&an);
	print_in_middle(menu, 1, 0, 10, "Commands (Q=quit)", COLOR_PAIR(31));
	refresh();

post_menu(my_menu);
wrefresh(menu);

	}


	unpost_menu(my_menu);
	for(i = 0; i < n_choices; ++i)
		free_item(my_items[i]);
	free_menu(my_menu);



nocbreak();

if(online){
bkgd(COLOR_PAIR(32));
makeWinWithText(stdscr,deadLettering,0,0);
refresh();
getch();
}

free(petBuff);
free(titleBuff);
free(deadLettering);
free(statBuff);
killAllWindows();
killAllBuffs();
endwin();

return 0;
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

void func(Animal* an,int option){
    beep();
    if(option < 6){
    if(!paused){
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

void graphics(Animal* an){

 wbkgd(title,COLOR_PAIR(30));
 makeWinWithText(title,titleBuff,0,0);
 wrefresh(title);
 wbkgd(title,COLOR_PAIR(31));
 if(an->dying){
    wbkgd(pet,COLOR_PAIR(32));

 }
 else if(paused){

    wbkgd(pet,COLOR_PAIR(31));

 }
 else{
    wbkgd(pet,COLOR_PAIR(9));


 }
 makeWinWithText(pet,petBuff,0,0);
 wrefresh(pet);
 free(statBuff);
 statBuff=animalStatHud(*an);
 makeWinWithText(stats,statBuff,0,0);
 wrefresh(stats);
 displayHud(an);

}
void displayHud(Animal * an){
    if(!an->boredom){
    wbkgd(needs[1],COLOR_PAIR(8));
    wbkgd(pet,COLOR_PAIR(8));

     makeWinWithText(needs[1],"BORED!\n",0,0);

    }
    else{

    wbkgd(needs[1],COLOR_PAIR(7));

     makeWinWithText(needs[1],"      \n",0,0);

    }

    wrefresh(needs[1]);

    if(!an->hunger){
    wbkgd(needs[2],COLOR_PAIR(2));
     makeWinWithText(needs[2],"HUNGRY!\n",0,0);

    }
    else{

    wbkgd(needs[2],COLOR_PAIR(7));
     makeWinWithText(needs[2],"       \n",0,0);


    }

    wrefresh(needs[2]);
    if(!an->thirst){
    wbkgd(needs[3],COLOR_PAIR(3));
     makeWinWithText(needs[3],"THIRSTY!\n",0,0);

    }
    else{

    wbkgd(needs[3],COLOR_PAIR(7));
     makeWinWithText(needs[3],"       \n",0,0);


    }

    wrefresh(needs[3]);
    if(!an->energy){
    wbkgd(needs[4],COLOR_PAIR(4));
     makeWinWithText(needs[4],"TIRED!\n",0,0);

    }
    else{

    wbkgd(needs[4],COLOR_PAIR(7));
     makeWinWithText(needs[4],"      \n",0,0);


    }

    wrefresh(needs[4]);
    if(an->gotPoo){
    wbkgd(needs[5],COLOR_PAIR(5));
     makeWinWithText(needs[5],"POO!\n",0,0);

    }
    else{
    wbkgd(needs[5],COLOR_PAIR(7));

     makeWinWithText(needs[5],"    \n",0,0);


    }
    wrefresh(needs[5]);
    if(an->gotPee){

    wbkgd(needs[6],COLOR_PAIR(6));
     makeWinWithText(needs[6],"PEE!\n",0,0);

    }
    else{

    wbkgd(needs[6],COLOR_PAIR(7));
     makeWinWithText(needs[6],"    \n",0,0);


    }
    wrefresh(needs[6]);
    if(an->sleeping){

    wbkgd(needs[0],COLOR_PAIR(1));
        makeWinWithText(needs[0],"SLEEPING!\n",0,0);

    }
    else{
    wbkgd(needs[0],COLOR_PAIR(7));

        makeWinWithText(needs[0],"         \n",0,0);


    }
    wrefresh(needs[0]);


}

void flashingDyingAlert(Animal* an){
    while(!an->dead){
        if(an->dying){

            flash();
            usleep(1000000);
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
