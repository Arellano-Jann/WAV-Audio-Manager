#include "../headers/Gain.h"

    Gain::Gain(std::vector<float> samples, float scale)
        : Processor(samples)
        , scale(scale*.01)
        {
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file
        process();
    }

    void Gain::process(){
        adjustGain();
        setSample(gain);
        checkVals();
    }
    void Gain::adjustGain(){
        for (auto x : getSample()){
            gain.push_back(x *= scale);
        }
    }