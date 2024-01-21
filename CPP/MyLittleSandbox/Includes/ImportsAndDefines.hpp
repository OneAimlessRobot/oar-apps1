#ifndef IMP_H
#define IMP_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include "../Includes/TextBox.hpp"
#include "../Includes/gridObject.hpp"
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "../Includes/graphicalLib1.hpp"
#include <cstring>
#include "../Includes/auxFunctions.h"
#include "../Includes/Trail.hpp"
#include "../Includes/HitBox.hpp"
#include <fstream>
#include <signal.h>
#include <limits>
#include "../Includes/TemporaryTexture.hpp"
#include "../Includes/LTexture.hpp"
#include "../Includes/FadingTexture.hpp"
#include "../Includes/Pen.hpp"
#include "../Includes/Sprite.hpp"
#include <algorithm>
#include "../Includes/Obstacle.hpp"
#include "../Includes/Iterator.hpp"
#include "../Includes/Object.hpp"
#include "../Includes/Circler.hpp"
#include "../Includes/GeometricVector.hpp"
#include "../Includes/throwable.hpp"
#include "../Includes/jumper.hpp"
#include "../Includes/Planet.hpp"
#include "../Includes/FluidLayer.hpp"
#include "../Includes/ForceField.hpp"
#include "../Includes/Level.hpp"
#include "../Includes/ODESolver.hpp"
#include "../Includes/Game.hpp"

#define DEFAULT_WIN_WIDTH 960
#define DEFAULT_FRAMERATE 60
#define DEFAULT_HITBOX_THICKNESS 1
#define DEFAULT_FONTSIZE 30
#define DEFAULT_THROWINGSPEED 20
#define DEFAULT_FLOOR_LEVEL 500
#define DEFAULT_GRAVITY_CONST 10
#define PROJECT_PATH "/home/oar_X_I/oar-apps1-priv/CPP/MyLittleSandbox"
#define RESOURCES_PATH PROJECT_PATH "/resources"
#define OBSTACLE_IMAGE_PATH RESOURCES_PATH "/res/images/brickwall.png"
#define FFIELD_IMAGE_PATH  RESOURCES_PATH "/res/images/ffield.png"
#define THROWABLE_IMAGE_PATH RESOURCES_PATH "/res/images/ball.png"
#define SKY_IMAGE_PATH  RESOURCES_PATH "/res/images/sky.png"
#define SUN_IMAGE_PATH RESOURCES_PATH "/res/images/SUN.png"
#define FADING_IMAGE_PATH RESOURCES_PATH "/res/images/keichii.png"
#define TEST_SPRITE_PATH RESOURCES_PATH "/res/sprites/test.spr"
#define DEFAULT_MAP_PATH RESOURCES_PATH "/maps/vcx.map"
#define MAPS_FOLDER_PATH RESOURCES_PATH "/maps/"
#define SETTINGS_PATH RESOURCES_PATH "/settings.txt"


//		             FEDCBA9876543210
//#define TRAILS_MASK            (0b0000000000000001)
#define COLLISIONS_MASK        (0b0000000000000010)
#define NEW_OBSTACLE_MASK      (0b0000000000000100)
#define ARMY_MASK              (0b0000000000001000)
#define RUN_MASK               (0b0000000000010000)
#define PLANET_MASK            (0b0000000000100000)
#define REMOVE_ENTITIES_MASK   (0b0000000001000000)
#define THROWABLE_ADD_MASK     (0b0000000010000000)
#define DRAW_MASK              (0b0000000100000000)
#define SAVE_LEVEL_MASK        (0b0000001000000000)
#define LOAD_LEVEL_MASK        (0b0000010000000000)
#define THROWING_SPEED_MASK    (0b0000100000000000)
//    #define UNDEFINED_MASK         (0b0001000000000000)
//    #define UNDEFINED_MASK         (0b0010000000000000)
//    #define UNDEFINED_MASK         (0b0100000000000000)
//    #define UNDEFINED_MASK         (0b1000000000000000)



//#define N_TRAILS_MASK          (0b1111111111111110)
#define N_COLLISIONS_MASK      (0b1111111111111101)
#define N_NEW_OBSTACLE_MASK    (0b1111111111111011)
#define N_ARMY_MASK            (0b1111111111110111)
#define N_RUN_MASK             (0b1111111111101111)
#define N_PLANET_MASK          (0b1111111111011111)
#define N_REMOVE_ENTITIES_MASK (0b1111111110111111)
#define N_THROWABLE_ADD_MASK   (0b1111111101111111)
#define N_DRAW_MASK            (0b1111111011111111)
#define N_SAVE_LEVEL_MASK      (0b1111110111111111)
#define N_LOAD_LEVEL_MASK      (0b1111101111111111)
#define N_THROWING_SPEED_MASK  (0b1111011111111111)
//    #define N_UNDEFINED_MASK       (0b1110111111111111)
//    #define N_UNDEFINED_MASK       (0b1101111111111111)
//    #define N_UNDEFINED_MASK       (0b1011111111111111)
//    #define N_UNDEFINED_MASK       (0b0111111111111111)
#endif
