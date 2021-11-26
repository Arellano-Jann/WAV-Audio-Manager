#pragma once
#define COMPRESSOR_H
#include "Processor.h"


class Compressor : public Processor{
    float max;
    float ratio;
    void compress();
    void process();
public:
    Compressor(std::vector<float> samples, float ratio, float max);
    // float max needs to have a conversion bc -1 and 1
};