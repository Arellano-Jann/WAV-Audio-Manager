// Name: Jann Arellano
#include "Processor.h"

    void Processor::normalization(){
        //Algo: The largest sample value in the data is found, and 
        //then the data is scaled so that that value is the maximum possible value. 
        //This maximizes the amplitude of the final waveform.
        
        //Takes in a vector sample and normalizes it to max amplitude.
        ///How do we output? Does this need to be a void?
        float max = 0;
        float min = 255;
        float scale = 0;
        int scaleMax = 255; // this changes depending on bit depth 2^8 vs 2^16
        for (auto x : sample){ // find max in data sample 
        /// find absolute value of max (if this doesn't work)
            if (x > max){
                max = x;
            }
        }
        for (auto x : sample){ // find min in data sample
            if (x < min){
                min = x;
            }
        }
        scale = findMax(min, max); // figure out if max or min is closer to cap
        if (scale < 128) // ensures correct scaling to caps
            scale = 255 - scale;
        scale /= scaleMax; // finds scaleValue to normalize sample

        for (auto &x : sample){ // scale data sample
            x *= scale; /// can be simplified by gainAdjustment
        }
        /// need check if any value is above 255 or 0???
    }
    
    void Processor::echo(float scale, int delay){
        //Algo: Samples are copied, scaled, and 
        //added to later locations in the sample buffer to create an echo effect.

        //Takes in a float scale and delay. Copies a vector and combines both vectors.
        std::vector<float> echo = sample;
        for (auto i = 0; i < sample.size(); i++){ // creates scaled echo vector
            echo[i] = sample[i] * scale; /// add a check to see if it's more than 255
        }

        //how to implement the addition of the scales??
        for (auto i = 0; i < delay; i++){ // adds 0 to the start of the array "delay" times
            echo.insert(echo.begin(), 0); /// should i add 0 or 128?
            sample.push_back(0);
        }
        
        //add echo[i] to sample[i] to calculate total wavelength
        for (auto i = 0; i < echo.size(); i++){
            echo[i] += sample[i]; /// does this work? hopefully.
        }

        ///an echo is usually quieter than original so maybe 
        ///scale the scale so that it's lower than 1?
    }

    void Processor::gainAdjustment(float scale){
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file

        for (auto &x : sample){// creates scaled echo vector
            x *= scale;
        }
    }


    // Helper Functions
    
    float Processor::findMax(float min, float max){
        float temp = max - 255;
        temp -= temp*2; // temp = temp - (temp*2)
        if (temp > min){
            return min;
        }
        return max;
    }