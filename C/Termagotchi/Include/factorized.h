#ifndef FACTORIZED_H
#define FACTORIZED_H
char* makeNamedFormattedString(int size);
void initNcursesAndGame(); //A
void killAnimalAndGame(); //B
// A is to B what malloc is to free. ALLWAYS MATCH THEM!!!!!

void initBuffers(Animal * an,char** buffs); //takes a char** buffer with 4 * char* size
void initWindows(WINDOW** needs); //takes a WINDOW** buffer with 11 * WINDOW* size
void initAllColors();

void killAllBuffs(char** buffs );
void killAllWindows(WINDOW** needs);

#endif





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
