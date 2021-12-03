#include "../headers/Gain.h"

    /**
     * @brief Construct a new Gain object
     * This constructor initializes it's parameters into the class's private members using an initializer list.
     * This constructor calls the Processor class's constructor using samples.
     * The constructor calls the private void process() method.
     * 
     * @param samples A vector that will be processed using private methods.
     * @param scale A float (multiplied by .01) used to scale values. The input is a percentage.
     */
    Gain::Gain(std::vector<float> samples, float scale)
        : Processor(samples)
        , scale(scale*.01f)
        {
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file
        process();
    }

    /**
     * @brief Scales the volume of the vector and checks if the values are valid.
     * Calls the void adjustGain() method to scale the volume of the vector. After, it saves the new vector by calling the inherited setSample() method from the Processor class. It then checks the values of the saved vector by the inherited checkVals() method from the Processor class
     * 
     */
    void Gain::process(){
        adjustGain();
        setSample(gain);
        checkVals();
    }
    /**
     * @brief Scales the samples and puts it into a new vector.
     * Iterates through each element in the sample. Then, it scales the element by scale, a class member. Finally, it adds it to the gain vector, a class member.
     * 
     */
    void Gain::adjustGain(){
        for (auto x : getSample()){
            gain.push_back(x *= scale);
        }
    }