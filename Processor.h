// Name: Jann Arellano

#pragma once
#define PROCESSOR_H
#include <iostream>
#include <vector>

class Processor{
    // processes a whole vector of samples
    int scaleMax = 255; // this changes depending on bit depth 2^8 vs 2^16
    std::vector<float> sample; // this works by having a constructor. 
    // the wav is casted as a processor object now.
    // need to have extra method so that 
public:
    Processor(std::vector<float> sample) : sample(sample){}
    void normalization();
    void echo();
    void gainAdjustment();
    void gainAdjustment(float scale);
    void lowPassFilter();
    void compression();

    //Helper Functions
    float findMax();
    float findMin();
    float findScale(float min, float max);
    float ask(std::string question);
};