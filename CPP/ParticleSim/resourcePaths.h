#ifndef RES_H
#define RES_H

#define PROGRAMPATH "/home/k/oar-apps1/CPP/ParticleSim/"

#define SRIFLE_PATH PROGRAMPATH+"resources/guns/sniperRifle.gun"
#define ARIFLE_PATH PROGRAMPATH+"resources/guns/assaultRifle.gun"
#define SMG_PATH PROGRAMPATH+"resources/guns/subMG.gun"
#define PISTOL_PATH PROGRAMPATH+"resources/guns/pistol.gun"

#define CALIBERS_PATH PROGRAMPATH+"resources/guns/calibers/"

#define FIVEFIVESIX CALIBERS_PATH +"fivefivesix"

#define GUNMENU_PATH "/home/k/oar-apps1/CPP/ParticleSim/resources/menus/gunMenu"


#define DELETEMENU_PATH "/home/k/oar-apps1/CPP/ParticleSim/resources/menus/whatToDelete"

enum gunType {SRIFLE=0,ARIFLE=1,SMG=2,PISTOL=3};

namespace Resources{

std::vector<std::string> generateGunMenu();

std::vector<std::string> generateMenu(std::string filePath);


std::vector<std::string> generateDeleteMenu();

void printMenu(std::vector<std::string> menu);

}



#endif
