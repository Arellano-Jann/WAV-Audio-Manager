#pragma once
#define GAIN_H
#include "Processor.h"


class Gain : public Processor{
    float scale = 10;
    void process();
    void adjustGain();
public:
    Gain(std::vector<float> samples, float scale);
};