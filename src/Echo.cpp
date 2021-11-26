#include "../headers/Echo.h"

    Echo::Echo(std::vector<float> samples, float scale, int delay)
        : Processor(samples)
        , scale{scale*.01}
        , delay{delay}
        {
        //Algo: Samples are copied, scaled, and 
        //added to later locations in the sample buffer to create an echo effect.
        // calcs from the back to delay. sets i to scaled delayed element added to itself.

        //Takes in a float scale and int delay. Vector scales itself and adds to itself.
        process();
    }

    void Echo::process(){
        checkScale();
        setEcho();
        calculateFinalEcho();
        setSample(echo);
        checkVals();
    }
    void Echo::checkScale(){
        if (scale > 1) scale = 1;
    }
    void Echo::setEcho(){
        echo = getSample();
    }
    void Echo::calculateFinalEcho(){
        for (int i = echo.size()-1; i >= delay; i--){
            echo[i] += (echo[i-delay] * scale); 
        }
    } // calcs from the back to delay. sets i to scaled delayed element added to itself.