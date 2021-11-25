#include "../headers/Gain.h"

    Gain::Gain(std::vector<float> samples, float scale)
        : Processor(samples)
        , scale(scale)
        {
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file
        process(scale);
    }

    void Gain::process(float scale){
        for (auto &x : getSample()){ 
            // might not work since private variable
            // might need a sample member variabls
            x *= scale;
        }
        checkVals();
    }