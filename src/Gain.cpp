#include "../headers/Gain.h"

void Gain::gainAdjustment(){
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file

        float scale = ask("scale");
        
        for (auto &x : sample){// creates scaled echo vector
            x *= scale;
            if (x > getMaxVal()) x = getMaxVal();
            if (x < getMinVal()) x = getMinVal();
        }
    }

    void Gain::gainAdjustment(float scale){
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file

        for (auto &x : sample){// creates scaled echo vector
            x *= scale;
            if (x > getMaxVal()) x = getMaxVal();  // checks if value is above maxVal
            if (x < getMinVal()) x = getMinVal();
        }
    }