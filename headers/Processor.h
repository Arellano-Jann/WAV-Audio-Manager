// Name: Jann Arellano

#pragma once
#define PROCESSOR_H
#include <iostream>
#include <vector>

class Processor{
    // processes a whole vector of samples
    std::vector<float> sample; // this works by having a constructor. 
    // the wav is casted as a processor object now.
    float maxVal = 1;
    float minVal = -1;
public:
    Processor(std::vector<float> &samples) : sample(samples){}

    void setSample(std::vector<float> samples){ sample = samples;}
    std::vector<float> getSample() const { return sample; }

    float getMaxVal() { return maxVal; }
    float getMinVal() { return minVal; }
    void checkVals();
};