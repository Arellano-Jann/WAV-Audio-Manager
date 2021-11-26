// Name: Jann Arellano
#include "../headers/Processor.h"

    void Processor::checkVals(){
        for (auto &x : sample){
            if (x > getMaxVal()) 
                x = getMaxVal(); // checks if value is above maxVal
            if (x < getMinVal()) 
                x = getMinVal(); // checks if value is above maxVal
        }
    
    }