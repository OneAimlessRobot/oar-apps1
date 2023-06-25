#include "includes.h"
int main(int argc,char **argv){
if(argc>3){
Manager * mgr= new Manager(atof(argv[1]),atof(argv[2]),atof(argv[3]));
mgr->mainLoop();


}
else{
std::cout<<"morre demonio\n";
}
return 0;
}
