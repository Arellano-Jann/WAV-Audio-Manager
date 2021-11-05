// Name: Jann Arellano

#pragma once
#define PROCESSOR_H
#include <vector>

class Processor{
    std::vector<float> sample; // Taking the liberty to set this
public:
    void normalization();
    void echo(float scale, int delay);
    void gainAdjustment(float scale);
    float findMax(float min, float max);
};