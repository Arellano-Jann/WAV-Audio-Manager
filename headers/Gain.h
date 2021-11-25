#pragma once
#define GAIN_H
#include "Processor.h"


class Gain : public Processor{
    float scale = 10;
    void process(float scale);
public:
    Gain() = default;
    Gain(float scale);
};