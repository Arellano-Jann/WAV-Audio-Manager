#pragma once
#define GAIN_H
#include "Processor.h"

/**
 * @brief A gain class that inherits from the Processor class
 * This class has a public constructor that calls private processing methods.
 * It also has two private member variables which are initialized by the constructor.
 * 
 */
class Gain : public Processor{
    float scale = 10;
    std::vector<float> gain;
    void process();
    void adjustGain();
public:
    Gain(std::vector<float> samples, float scale);
    std::vector<float> getGain() const { return gain; }
};