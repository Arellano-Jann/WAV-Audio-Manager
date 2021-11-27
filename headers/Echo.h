#pragma once
#define ECHO_H
#include "Processor.h"

/**
 * @brief A sound echoing class that inherits from the Processor class
 * This class has a public constructor that calls private processing methods.
 * It also has three private member variables which are initialized by the constructor.
 * 
 */
class Echo : public Processor{
    std::vector<float> echo;
    float scale = 10; 
    int delay = 10;
    void checkScale();
    void setEcho();
    void calculateFinalEcho();
    void process();
public:
    Echo(std::vector<float> samples, float scale, int delay);
};