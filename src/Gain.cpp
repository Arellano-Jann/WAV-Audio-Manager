#include "../headers/Gain.h"

    /**
     * @brief Constructs a new Gain object. \n
     * This constructor initializes it's parameters into the class's private members using an initializer list. \n
     * This constructor calls the Processor class's constructor using samples. \n
     * The constructor calls the private void process() method. \n
     * 
     * @param samples (A vector that will be processed using private methods.) \n
     * @param scale (A float (multiplied by .01) used to scale values. The input is a percentage.) \n
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
     * @brief Scales the volume of the vector and checks if the values are valid. \n
     * Calls the void adjustGain() method to scale the volume of the vector. \n
     * After, it saves the new vector by calling the inherited setSample() method from the Processor class. \n
     * It then checks the values of the saved vector by the inherited checkVals() method from the Processor class. \n
     * 
     */
    void Gain::process(){
        adjustGain();
        setSample(gain);
        checkVals();
    }
    /**
     * @brief Scales the samples and puts it into a new vector. \n
     * Iterates through each element in the sample. Then, it scales the element by scale, a class member. \n
     * Finally, it adds it to the gain vector, a class member. \n
     * 
     */
    void Gain::adjustGain(){
        for (auto x : getSample()){
            gain.push_back(x *= scale);
        }
    }