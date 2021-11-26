#include "../headers/Echo.h"

    Echo::Echo(std::vector<float> samples, float scale, int delay)
        : Processor(samples)
        , scale{scale*.01}
        , delay{delay}
        {
        //Algo: Samples are copied, scaled, and 
        //added to later locations in the sample buffer to create an echo effect.

        //Takes in a float scale and int delay. Copies a vector and combines both vectors.
        process();
    }

    void Echo::process(){
        checkScale();
        setEcho();
        scaleEcho();
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
    void Echo::scaleEcho(){
        for (auto i = 0; i < getSample().size(); i++){
            echo[i] *= scale;
        }
    }
    void Echo::calculateFinalEcho(){
        //add echo[i] to sample[i] to calculate total wavelength
        for (auto i = delay; i < echo.size(); i++){
            echo[i-delay] = echo[i] + getSample()[i]; // adds sample to echo with an offset in echo so echo starts at 0
    }