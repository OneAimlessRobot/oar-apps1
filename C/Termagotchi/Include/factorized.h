


int hudx,
    hudy;
WINDOW* pet,*title,*menu,*stats,*sleepMeter,*boredWarning,*hungryWarning,*thirstWarning,*tiredWarning,*pooWarning,*peeWarning;

char* makeNamedFormattedString(int size);
void initNcursesAndGame(); //A
void killAnimalAndGame(); //B
// A is to B what malloc is to free. ALLWAYS MATCH THEM!!!!!


void initWindows();
void initAllColors();






//
//char* makeNamedFormattedString(int size){
//
//
//char* buff=malloc(1000);
//memset(buff,0,1000);
//
// sprintf(buff,"vida maxima: %d\ntedio maximo:%d\nsede maxima:%d\nfome maxima:%d\nenergia maxima:%d\n",
//            an->maxHealth,
//            an->maxBoredom,
//            an->maxThirst,
//            an->maxHunger,
//            an->maxEnergy);
//
//return buff;
//
//}
