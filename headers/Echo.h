#pragma once
#define ECHO_H
#include "Processor.h"


class Echo : public Processor{
    std::vector<float> echo;
    float scale = 10; 
    int delay = 10;
    void checkScale();
    void setEcho();
    void scaleEcho();
    void calculateFinalEcho();
    void process();
public:
    Echo(std::vector<float> samples, float scale, int delay);
};