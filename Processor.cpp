// Name: Jann Arellano
#include "Processor.h"

    void Processor::normalization(){ 
        // need to find out if i can do wavefile.normalization() and if that work
        // or if i have to have a return type and pass in params
        ///How do we output? Does this need to be a void?

        //Algo: The largest sample value in the data is found, and 
        //then the data is scaled so that that value is the maximum possible value. 
        //This maximizes the amplitude of the final waveform.
        
        //Takes in a vector sample and normalizes it to max amplitude.
        float max = 0;
        float min = 255;
        float scale = 0;
        max = findMax(max); // (max) is not needed here
        min = findMin(min); // but used to make code less lines
        scale = findScale(min, max, scale);
        gainAdjustment(sample, scale);
    }
    
    void Processor::echo(float scale, int delay){
        //Algo: Samples are copied, scaled, and 
        //added to later locations in the sample buffer to create an echo effect.

        //Takes in a float scale and delay. Copies a vector and combines both vectors.
        std::vector<float> echo = sample;
        for (auto i = 0; i < sample.size(); i++){ // creates scaled echo vector
            echo[i] = sample[i] * scale; 
        }

        //expands arrays for addition
        for (auto i = 0; i < delay; i++){ // adds 0 to the start of the array "delay" times
            echo.insert(echo.begin(), 0); /// should i add 0 or 128?
            sample.push_back(0);
        }
        
        //add echo[i] to sample[i] to calculate total wavelength
        for (auto i = 0; i < echo.size(); i++){
            echo[i] += sample[i]; /// does this work? hopefully.
        }/// add a check to see if it's more than 255
        /// do we do checks on both echo and final echo???

        ///an echo is usually quieter than original so maybe 
        ///scale the scale so that it's lower than 1?
    }

    void Processor::gainAdjustment(std::vector<float> &sample, float scale){
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file

        ///don't know if &sample is correct but we want to change sample here

        for (auto &x : sample){// creates scaled echo vector
            x *= scale;
            if (x > scaleMax){ x = scaleMax; } // checks if value is above 255
            if (x < 0){ x = 0; } // checks if value is below 0
        }
    }

    void Processor::lowPassFilter(float max){
        //Algo: Remove components above a certain frequency specified.
        //https://www.reddit.com/r/explainlikeimfive/comments/jm6lm/eli5_how_do_audio_lowpasshighpassetc_filters_work/
        
        for (auto &x : sample){// creates scaled echo vector
            if (x > max){
                x = max; // it says "remove" so i'm wondering 
            } // if i should set it to 0 or max 
        }
    }

    void Processor::compression(float pass, float increase, float max){
        //Algo: For volume over a specified max, it is scaled by a ratio
        // pass:increase. For every units passed, it increases from 
        // max by "increase".
        float overflow;
        for (auto &x : sample){
            if (x > max){
                overflow = x - max; // overflow = nums past max
                x = max + (pass/overflow) * increase; // compresses
            }
        }
    }

    void Processor::compression(float pass, float increase, float max, int hold){
        // this overloads with int hold because it needs to be non linear
        // only compresses for a certain time after first instance 
        
        // has to be non linear so setup how long compressor can hold
        //https://www.reddit.com/r/explainlikeimfive/comments/1zfmew/eli5_compression_music_making/
        float overflow;
        int maxIndex;
        for (int i = 0; i < sample.size(); i++){
            // iterates through sample and finds first instance of anything over max
            if (sample[i] > max){
                maxIndex = i;
                break; // breaks loop so maxindex does not change
            }
        }
        
        for (maxIndex; maxIndex < (maxIndex+hold); maxIndex++){ 
            // iterates through first instance through the hold period
            if (sample[maxIndex] > max){ // makes sure it doesn't compress under max
                overflow = sample[maxIndex] - max;
                sample[maxIndex] = max + (pass/overflow) * increase; // compresses
            }
        }
    }




    // Helper Functions
    
    float Processor::findMax(float max){
        for (auto x : sample){ // find max in data sample 
            if (x > max){ max = x; }
        } /// find absolute value of max (if this doesn't work)
        return max;
    }
    float Processor::findMin(float min){
        for (auto x : sample){ // find min in data sample 
            if (x < min){ min = x; }
        }
        return min;
    }

    float Processor::findScale(float min, float max, float scale){
        // find out if max or min is closer to cap
        float temp = max - 255;
        temp -= temp*2; // temp = temp - (temp*2)
        if (temp > min){ scale = min; }
        else { scale = max; }
        
        if (scale < 128) // ensures correct scaling to caps
            scale = 255 - scale;
        return scale /= scaleMax; // finds scaleValue to normalize sample
    }