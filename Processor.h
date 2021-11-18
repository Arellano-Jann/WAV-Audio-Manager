// Name: Jann Arellano

#pragma once
#define PROCESSOR_H

// possibly change all methods to take in a sample
// i think this is because i intended to use vector.normalization()
// but vector does not have normalization method
// you can only use dot operator on methods when the object has the method
// vector does not have normalization method
// so configure to take in a vector instead of intending it to use a dot operator
// ^^ see if it works first because it should be an easy fix

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
    void compression(float pass, float increase, float max);

    //Helper Functions
    float findMax(float max);
    float findMin(float min);
    float findScale(float min, float max, float scale);
};