// Name: Jann Arellano
#include "../headers/Processor.h"

    /**
     * @brief Checks if the values in sample are valid
     * Iterates through sample and sets the element to the max possible value if it exceeds the max possible value. It sets the element to the least possible value if it is below the least possible value.
     * The element is set to the max possible value by the getMaxVal() method.
     * The element is set to the least possible value by the getMinVal() method. 
     * 
     */
    void Processor::checkVals(){
        for (auto &x : sample){
            if (x > getMaxVal()) 
                x = getMaxVal();
            if (x < getMinVal()) 
                x = getMinVal();
        }
    
    }