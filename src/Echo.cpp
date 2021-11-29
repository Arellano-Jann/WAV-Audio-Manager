#include "../headers/Echo.h"

    /**
     * @brief Construct a new Echo object
     * This constructor initializes it's parameters into the class's private members using an initializer list.
     * This constructor calls the Processor class's constructor using samples.
     * The constructor calls the private void process() method.
     * 
     * @param samples A vector that will be processed using private methods.
     * @param scale A float (multiplied by .01) that will be used to scale the echos volume. The input is a percentage.
     * @param delay An int that will be used to delay the sound of the echo by number of elements.
     */
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

    /**
     * @brief Creates an echo effect and checks if values are valid.
     * Calls the void checkScale() method to see if the scale value is valid. Next, it calls the void setEcho() method to create the echo vector. After, it calls the void calculateFinalEcho() method to perform math on the sound and create an echo effect. After, it saves the new vector by calling the inherited setSample() method from the Processor class. It then checks the values of the saved vector by the inherited checkVals() method from the Processor class.
     * 
     */
    void Echo::process(){
        checkScale();
        setEcho();
        calculateFinalEcho();
        setSample(echo);
        checkVals();
    }
    /**
     * @brief Checks if scale value is valid.
     * Checks if the scale value is more than 1. If it is over 1, it sets it to 1. Otherwise, nothing happens.
     * 
     */
    void Echo::checkScale(){
        if (scale > 1) scale = 1;
    }
    /**
     * @brief Sets echo vector.
     * Sets class member echo to the sample via the inherited method getSample().
     * 
     */
    void Echo::setEcho(){
        echo = getSample();
    }
    /**
     * @brief Performs math to create an echo effect.
     * Iterates from the back of the echo vector to the delay point, both are class members. It scales each element specially thus creating an echo effect.
     * It scales each element by setting the element to the scaled delayed element added to itself. The scaled delayed element is calculated by the product of the scale and the previous element delay times before the current element.
     * 
     */
    void Echo::calculateFinalEcho(){
        for (int i = echo.size()-1; i >= delay; i--){
            echo[i] += (echo[i-delay] * scale); 
        }
    }