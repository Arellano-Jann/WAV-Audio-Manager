#include "../headers/Gain.h"

    Gain::Gain(std::vector<float> samples, float scale)
        : Processor(samples)
        , scale(scale)
        {
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file
        process();
    }

    void Gain::process(){
        adjustGain();
        checkVals();
    }
    void Gain::adjustGain(){
        for (auto &x : getSample()){ 
            // might not work since sample is a private variable
            // might need a sample member variables
            x *= scale;
        }
    }