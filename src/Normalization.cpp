#include "../headers/Normalization.h"

void Processor::normalization(){
        //Algo: The largest sample value in the data is found, and 
        //then the data is scaled so that that max value in the data is the maximum possible value. 
        //This maximizes the amplitude of the final waveform.
        //Takes in a vector sample and normalizes it to max amplitude.
        
        float max = findMax();
        float min = findMin();
        float scale = findScale(min, max);
        gainAdjustment(scale);
    }

    float Processor::findMax(){ // fix for array sample
        float max = minVal;
        for (auto x : sample){ // find max in data sample 
            if (x > max) max = x; 
        } /// find absolute value of max (if this doesn't work)
        return max;
    }
    float Processor::findMin(){
        float min = maxVal;
        for (auto x : sample){ // find min in data sample 
            if (x < min) min = x; 
        }
        return min;
    }

    float Processor::findScale(float min, float max){
        // find out if max or min is closer to mid

        max = maxVal/max; // calculates scale for max to maxcap 10/5 = 2
        min = minVal/min; // assumes min is negative. needs a check
        if (min < 0) min *= -1; // makes sure that we're not comparing a negative
        if (min < max) return min;
        return max;
    }
