#pragma once
#define COMPRESSOR_H
#include "Processor.h"

/**
 * @brief A sound compressor class that inherits from the Processor class. \n 
 * This class has a public constructor that calls private processing methods. \n
 * It also has three private member variables which are initialized by the constructor. \n
 * 
 */
class Compressor : public Processor{
    std::vector<float> compressed;
    float max;
    float ratio;
    void compress();
    void process();
public:
    Compressor(std::vector<float> samples, float ratio, float max);
};