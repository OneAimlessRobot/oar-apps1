#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include "ObstacleIterator.hpp"

       ObstacleIterator::ObstacleIterator(std::vector<Obstacle*> &vec){

            this->internalVec=vec;
            this->cursor=0;


        }

        void ObstacleIterator::increment(){

            cursor++;


        }

        int ObstacleIterator::isOver(){

           return this->cursor>=internalVec.size();

        }

        Obstacle* ObstacleIterator::getCurrent(){

            return internalVec[cursor];
        }

        ObstacleIterator::~ObstacleIterator(){



        }


