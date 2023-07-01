#include <string>
#include <fstream>
#include <iostream>
#include "../constantHeaders/IOSettings.h"
#include "../constantHeaders/bulletSettings.h"
#include "Bullet.h"

caliber caliber::defaultCaliber(){

    return (caliber){DEFAULTBULLETSIZE,DEFAULTBULLETM,DEFAULTBULLETE,DEFAULTBULLETCAR};


}
//
