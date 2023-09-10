#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include "Obstacle.hpp"

#ifndef OBS_ITERATOR_H
#define OBS_ITERATOR_H
class ObstacleIterator{

std::vector<Obstacle*> internalVec;
 int cursor;

public:
        ObstacleIterator(std::vector<Obstacle*> &vec);

      std::vector<Obstacle*>::iterator spawnIterator();

        void increment();

        int isOver();

        Obstacle* getCurrent();

        ~ObstacleIterator();



};
#endif