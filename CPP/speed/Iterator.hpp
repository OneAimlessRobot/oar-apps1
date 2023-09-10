

#ifndef OBS_ITERATOR_H
#define OBS_ITERATOR_H

template<typename T>
class Iterator{
std::vector<T> internalVec;
 int cursor;

public:
        Iterator<T>(std::vector<T> &vec);

      typename std::vector<T>::iterator spawnIterator();

        void increment();

        int isOver();

        T getCurrent();

        ~Iterator();



};
#include "Iterator.tpp"
#endif