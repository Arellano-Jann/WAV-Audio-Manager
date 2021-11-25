#include "../headers/Echo.h"

    Echo::Echo(float scale, int delay) : scale(scale), delay(delay){
        //Algo: Samples are copied, scaled, and 
        //added to later locations in the sample buffer to create an echo effect.

        //Takes in a float scale and int delay. Copies a vector and combines both vectors.
        scale *= .01;
        if (scale > 1){ scale = 1; }

        process(scale, delay); // need to see if it gets it from class members or not
    }
    Echo::Echo(){ // why does this say shit about a default ctor
        process(scale, delay);
    }

    void Echo::process(float scale, int delay){
        setEcho();
        scaleEcho(scale);
        calculateFinalEcho(delay);
        setSample(echo);
        checkVals();
    }
    void Echo::setEcho(){
        echo = getSample();
    }
    void Echo::scaleEcho(float scale){
        for (auto i = 0; i < getSample().size(); i++){
            echo[i] *= scale;
        }
    }
    void Echo::calculateFinalEcho(int delay){
        //add echo[i] to sample[i] to calculate total wavelength
        for (auto i = delay; i < echo.size(); i++){
            echo[i-delay] = echo[i] + getSample()[i]; // adds sample to echo with an offset in echo so echo starts at 0
    }