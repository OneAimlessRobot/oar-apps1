#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Obstacle.hpp"
#include "ObstacleIterator.hpp"

#ifndef LEVEL_H
#define LEVEL_H

class Level{
    std::vector<Obstacle*> obstacles;
    Obstacle* air;
    std::string skyTexturePath;
    int xInit,yInit,worldWidth,worldHeight;

public:
    Level(SDL_Renderer*renderer,int worldWidth,int worldHeight,std::string filePath);


    ObstacleIterator* obstacleIterator();
    SDL_Point getPos();
    void renderSky(SDL_Renderer*renderer);

    void updateSky(SDL_Renderer* renderer,std::string path2Img);
    void renderObstacles(SDL_Renderer*renderer);
    Obstacle * getAirBox();
    void removeBoxesOnly();
    void addBox(Obstacle* obstacle);
    std::string getSkyImagePath();
    int getObstacleCount();
    ~Level();



};
#endif