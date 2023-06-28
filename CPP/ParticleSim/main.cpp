#include "includes.h"
int main(int argc,char **argv){
if(argc>5){
Interactive * mgr= new Interactive(atof(argv[1]),atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]));
mgr->mainLoop();
delete mgr;

}
else{
std::cout<<"morre demonio\n";
}
return 0;
}
