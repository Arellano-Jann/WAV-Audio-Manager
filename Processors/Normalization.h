#pragma once
#define NORMALIZATION_H
#include "Processor.h"


class Normalization : public Processor{
    
    void normalization();
    float findMax();
    float findMin();
    float findScale(float min, float max);
};