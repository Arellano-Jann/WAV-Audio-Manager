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
    Processor(std::vector<float> samples) : sample(samples){}

    void setVec(std::vector<float> samples){ sample = samples;}

    std::vector<float> getVec() { return sample; }
    float getMaxVal() { return maxVal; }
    float getMinVal() { return minVal; }

    float ask(std::string question);
};