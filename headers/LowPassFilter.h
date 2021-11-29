#pragma once
#define LOWPASSFILTER_H
#include "Processor.h"


class LowPassFilter : public Processor{
    float max;
    void process(); // needs logic
public:
    LowPassFilter(std::vector<float> samples, float max);
};