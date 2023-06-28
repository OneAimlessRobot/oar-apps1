#include "includes.h"
int main(int argc,char **argv){
if(argc>3){
ScreenSaverSystem * mgr= new ScreenSaverSystem(atof(argv[1]),atof(argv[2]),atof(argv[3]));
mgr->mainLoop();
delete mgr;

}
else{
std::cout<<"morre demonio\n";
}
return 0;
}
