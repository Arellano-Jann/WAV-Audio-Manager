// Name: Jann Arellano

#pragma once
#define PROCESSOR_H
#include <vector>

class Processor{
    // processes a whole vector of samples
    int scaleMax = 255; // this changes depending on bit depth 2^8 vs 2^16
    std::vector<float> sample; // Taking the liberty to set this
public:
    void normalization();
    void echo(float scale, int delay);
    void gainAdjustment(std::vector<float> &sample, float scale);
    void lowPassFilter(float max);
    void compression(float pass, float increase, float max, int hold);

    //Helper Functions
    float findMax(float max);
    float findMin(float min);
    float findScale(float min, float max, float scale);
};