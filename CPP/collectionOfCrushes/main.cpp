#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <vector>
#include "auxFuncs.h"
#include "Types/Menu.h"
#include "Types/Crush.h"
#include "resourceHeader.h"
#include "Tools/CrushGenerator.h"
#include "Managers/Master.h"
int main(int argc, char**argv){
Master master(PROGRAM_SETTINGS_PATH);
master.mainLoop();
return 0;

}
