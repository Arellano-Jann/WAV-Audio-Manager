#pragma once
#define NORMALIZATION_H
#include "Gain.h"


class Normalization : public Gain{
    float findMax();
    float findMin();
    float findScale(float min, float max);
    void process(std::vector<float> samples);
public:
    Normalization(std::vector<float> samples);
};