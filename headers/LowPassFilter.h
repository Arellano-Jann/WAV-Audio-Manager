#pragma once
#define LOWPASSFILTER_H
#include "Processor.h"


class LowPassFilter : public Processor{
    std::vector<float> lpf;
    int destruction;
    float scale = 1.0;
    void process();
    void destroyHighFreq();
    void setLowPassFilter();
public:
    LowPassFilter(std::vector<float> samples, int destruction);
};