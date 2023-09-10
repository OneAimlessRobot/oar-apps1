
#ifndef LEVEL_H
#define LEVEL_H

class Level{
    std::vector<Obstacle*> obstacles;
    std::vector<Planet*>planets;
    FluidLayer* air;
    std::string skyTexturePath,objectTexturePath,planetTexturePath;
    int xInit,yInit,worldWidth,worldHeight;

public:
    Level(SDL_Renderer*renderer,int worldWidth,int worldHeight,std::string filePath);

    Iterator<Obstacle*>* obstacleIterator();
    SDL_Point getPos();
    void renderSky(SDL_Renderer*renderer);
    void renderObstacles(SDL_Renderer*renderer);
    void renderPlanets(SDL_Renderer*renderer);
    Obstacle * getAirBox();
    void removeBoxes();
    void removePlanets();
    void removeThrowables();
    double getAirDensity();
    void addThrowable(Throwable*throwable);
    void addBox(Obstacle* obstacle);
    void updateMovements();
//    int getFluidDx();
//    int getFluidDy();
//    int getFluidSpeed();
    void addPlanet(Planet*planet);
    std::string getSkyImagePath();
    std::string getObjectImagePath();
    std::string getPlanetImagePath();
    int getObstacleCount();
    int getPlanetCount();
    Iterator<Planet*>* planetIterator();
    ~Level();



};
#endif