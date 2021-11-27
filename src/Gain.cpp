#include "../headers/Gain.h"

    /**
     * @brief Construct a new Gain object
     * This constructor initializes it's parameters into the class's private members using an initializer list.
     * This constructor calls the Processor classes constructor using samples.
     * The constructor calls the private void process() method.
     * 
     * @param samples A vector that will be processed using private methods.
     * @param scale A float (multiplied by .01) used to scale values. The input is a percentage.
     */
    Gain::Gain(std::vector<float> samples, float scale)
        : Processor(samples)
        , scale(scale*.01)
        {
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file
        process();
    }

    /**
     * @brief 
     * 
     */
    void Gain::process(){
        adjustGain();
        setSample(gain);
        checkVals();
    }
    void Gain::adjustGain(){
        for (auto x : getSample()){
            gain.push_back(x *= scale);
        }
    }