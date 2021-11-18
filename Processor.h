// Name: Jann Arellano

#pragma once
#define PROCESSOR_H
#include <iostream>

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
public:
    void normalization(float sample[]);
    void echo(float sample[]);
    void gainAdjustment(float sample[]);
    void gainAdjustment(float sample[], float scale);
    void lowPassFilter(float sample[]);
    void compression(float sample[]);

    //Helper Functions
    float findMax(float max);
    float findMin(float min);
    float findScale(float min, float max, float scale);
    float ask(std::string question);
};