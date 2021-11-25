#pragma once
#define ECHO_H
#include "Processor.h"


class Echo : public Processor{
    std::vector<float> echo;
    float scale = 10; 
    int delay = 10;
    void setEcho();
    void scaleEcho(float scale);
    void calculateFinalEcho(int delay);
    void process(float scale, int delay);
public:
    Echo(std::vector<float> samples, float scale, int delay);
};