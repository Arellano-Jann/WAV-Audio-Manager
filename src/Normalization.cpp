#include "../headers/Normalization.h"
#include <iostream>

    Normalization::Normalization(std::vector<float> samples)
    : Gain(samples, 1)
    {
        //Algo: The largest sample value in the data is found, and 
        //then the data is scaled so that that max value in the data is the maximum possible value. 
        //This maximizes the amplitude of the final waveform.
        //Takes in a vector sample and normalizes it to max amplitude.
        process(samples);
    }    

    void Normalization::process(std::vector<float> samples)
    {
        float max = findMax();
        float min = findMin();
        float scale = findScale(min, max);
        Gain g(samples, scale);
        setSample(g.getGain());
        checkVals();
    }

    float Normalization::findMax(){
        float max = getMinVal();
        for (auto x : getSample()){ 
            if (x > max) max = x; 
        }
        return max;
    }
    float Normalization::findMin(){
        float min = getMaxVal();
        for (auto x : getSample()){ 
            if (x < min) min = x;
            // Using Ternary: x = (x < min) ? min : x;
        }
        return min;
    }

    float Normalization::findScale(float min, float max){
        // find out if max or min is closer to mid

        max = getMaxVal()/max; // calculates scale for max to maxcap 10/5 = 2
        min = getMinVal()/min; // assumes min is negative
        if (min < 0) min *= -1; // makes sure that we're not comparing a negative
        if (min < max) return min;
        return max;
    }
