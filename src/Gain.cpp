#include "../headers/Gain.h"

    Gain::Gain(){
        process(scale);
    }
    Gain::Gain(float scale) : scale(scale){
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file
        process(scale);
    }

    void Gain::process(float scale){
        for (auto &x : getSample()){
            x *= scale;
        }
        checkVals();
    }