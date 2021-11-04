// Name: Jann Arellano

#pragma once
#define PROCESSOR_H

class Processor{
    std::vector<float> sample; // Taking the liberty to set this
public:
    void normalization();
    void echo(float scale, int delay);
    void gainAdjustment(float scale);
};