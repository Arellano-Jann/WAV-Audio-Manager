#pragma once
#define NORMALIZATION_H
#include "Gain.h"

/**
 * @brief A sound normalization class that inherits from the Gain class. \n
 * This class has a public constructor that calls private processing methods. \n
 * It also has no private member variables which are initialized by the constructor. \n
 * 
 */
class Normalization : public Gain{
    float findMax();
    float findMin();
    float findScale(float min, float max);
    void process(std::vector<float> samples);
public:
    Normalization(std::vector<float> samples);
};