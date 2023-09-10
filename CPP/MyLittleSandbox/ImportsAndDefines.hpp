#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include"Menu.hpp"
#include"gridObject.hpp"
#include<math.h>
#include<iostream>
#include<vector>
#include<string>
#include"graphicalLib1.hpp"
#include<cstring>
#include"auxFunctions.h"
#include "Trail.hpp"
#include"HitBox.hpp"
#include <fstream>
#include<limits>
#include "TemporaryTexture.hpp"
#include "LTexture.hpp"
#include "FadingTexture.hpp"
#include "Pen.hpp"
#include "Sprite.hpp"
#include <algorithm>
#include "Obstacle.hpp"
#include "Iterator.hpp"
#include "Object.hpp"
#include "Circler.hpp"
#include "GeometricVector.hpp"
#include"throwable.hpp"
#include"jumper.hpp"
#include "Planet.hpp"
#include "FluidLayer.hpp"
#include "ForceField.hpp"
#include "Level.hpp"
#include "ODESolver.hpp"

#define DEFAULT_WIN_WIDTH 960
#define DEFAULT_FRAMERATE 60
#define DEFAULT_HITBOX_THICKNESS 1
#define DEFAULT_FONTSIZE 30
#define DEFAULT_THROWINGSPEED 20
#define DEFAULT_FLOOR_LEVEL 500
#define DEFAULT_GRAVITY_CONST 10

#define OBSTACLE_IMAGE_PATH ("/home/oneaimlessrobot/speed/res/images/brickwall.png")
#define FFIELD_IMAGE_PATH ("/home/oneaimlessrobot/speed/res/images/ffield.png")
#define THROWABLE_IMAGE_PATH ("/home/oneaimlessrobot/speed/res/images/ball.png")
#define SKY_IMAGE_PATH ("/home/oneaimlessrobot/speed/res/images/sky.png")
#define SUN_IMAGE_PATH ("/home/oneaimlessrobot/speed/res/images/SUN.png")
#define FADING_IMAGE_PATH ("/home/oneaimlessrobot/speed/res/images/keichii.png")
#define TEST_SPRITE_PATH ("/home/oneaimlessrobot/speed/res/sprites/test.spr")
#define DEFAULT_MAP_PATH ("/home/oneaimlessrobot/speed/maps/vcx.map")
#define MAPS_FOLDER_PATH ("/home/oneaimlessrobot/speed/maps/")

//                                FEDCBA9876543210
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