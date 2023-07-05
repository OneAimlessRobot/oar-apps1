#ifndef AUX_H

#define AUX_H

namespace AuxFuncs{



float getRandomFloat(float min, float max);
template<typename T>
T randItemFromList(std::vector<T>& vec);
}


#include "auxFuncs.tpp"
#endif
