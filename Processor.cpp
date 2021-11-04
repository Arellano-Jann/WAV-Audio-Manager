// Name: Jann Arellano
#include "Processor.h"

    void normalization(std::vector<float> sample){
        //Algo: The largest sample value in the data is found, and 
        //then the data is scaled so that that value is the maximum possible value. 
        //This maximizes the amplitude of the final waveform.
        
        //Takes 
        float max = 0;
        float scale = 0;
        int scaleMax = 255;
        for (int i = 0; i < sample.end(); i++){ // find max in data sample
            if (vec[i] > max){
                max = vec[i];
            }
        }
        scale = scaleMax/max; // finds scaleValue to normalize sample
        for (int i = 0; i < sample.end(); i++){ // scale data sample
            vec[i] *= scale;
        }
    }
    void echo(float scale, int delay){
        
    }
    void gainAdjustment(float scale){
        
    }