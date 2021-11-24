#pragma once
#define GAIN_H
#include "Processor.h"


class Gain : public Processor{
    
    void gainAdjustment();
    void gainAdjustment(float scale);
};