
#include <random>
#include <cmath>
#include <ctime>
#include <set>
#include "auxFuncs.h"

float AuxFuncs::getRandomFloat(float min, float max) {
    std::random_device rd;                          // Obtain a random seed from the hardware
    std::mt19937 eng(rd());                         // Seed the generator
    std::uniform_real_distribution<float> distr(min, max); // Define the range

    return distr(eng);                              // Generate and return a random float
}

