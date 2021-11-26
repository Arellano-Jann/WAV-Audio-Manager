#pragma once
#define COMPRESSOR_H
#include "Processor.h"


class Compressor : public Processor{
    std::vector<float> compressed;
    float max;
    float ratio;
    void compress();
    void process();
public:
    Compressor(std::vector<float> samples, float ratio, float max);
};