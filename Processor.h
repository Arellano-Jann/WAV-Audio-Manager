// Name: Jann Arellano

#pragma once
#define PROCESSOR_H
#include <iostream>
#include "WaveHeader.h"

class Processor{
    // processes a whole vector of samples
    int scaleMax = 255; // this changes depending on bit depth 2^8 vs 2^16
    WaveHeader header;
    float sample[header.dataBytes];
public:
    void normalization(float (&sample)[]);
    // void echo();
    // void gainAdjustment();
    // void gainAdjustment(float scale);
    // void lowPassFilter();
    // void compression();

    //Helper Functions
    float findMax(float (&sample)[], float max);
    float findMin(float (&sample)[], float min);
    float findScale(float min, float max, float scale);
    float ask(std::string question);
    int size(float arr[]);
};