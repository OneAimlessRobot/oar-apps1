

WINDOW* pet,*title,*menu,*stats,*sleepMeter,*boredWarning,*hungryWarning,*thirstWarning,*tiredWarning,*pooWarning,*peeWarning;
WINDOW** needs;
char* makeNamedFormattedString(int size);
void initNcursesAndGame(); //A
void killAnimalAndGame(); //B
// A is to B what malloc is to free. ALLWAYS MATCH THEM!!!!!


void initWindows();
void initAllColors();

void killAllWindows();





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
