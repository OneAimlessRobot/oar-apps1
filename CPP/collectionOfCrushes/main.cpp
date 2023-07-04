#include <string>
#include <iostream>
#include <vector>
#include "Types/Crush.h"

int main(int argc, char**argv){

Crush *crush=new Crush();
std::cout<<crush->toString()<<"\n";

return 0;

}
