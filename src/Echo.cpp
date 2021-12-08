#include "../headers/Echo.h"

    /**
     * @brief Constructs a new Echo object. \n
     * This constructor initializes its parameters into the class's private members using an initializer list. \n
     * This constructor calls the Processor class's constructor using samples. \n
     * The constructor calls the private void process() method. \n
     * 
     * @param samples A vector that will be processed using private methods.
     * @param scale A float (multiplied by .01) that will be used to scale the echos volume. The input is a percentage.
     * @param delay An int that will be used to delay the sound of the echo by number of elements.
     */
    Echo::Echo(std::vector<float> samples, float scale, int delay, int repeat)
        : Processor(samples)
        , scale{scale*.01f}
        , delay{delay}
        , repeat{repeat}
        {
        //Algo: Samples are copied, scaled, and 
        //added to later locations in the sample buffer to create an echo effect.
        // calcs from the back to delay. sets i to scaled delayed element added to itself.

        //Takes in a float scale and int delay. Vector scales itself and adds to itself.
        process();
    }

    /**
     * @brief Creates an echo effect and checks if values are valid. \n
     * Calls the void checkScale() method to see if the scale value is valid. \n
     * Next, it calls the void setEcho() method to create the echo vector. \n
     * After, it calls the void calculateFinalEcho() method to perform math on the sound, and create an echo effect. \n
     * After, it saves the new vector by calling the inherited setSample() method from the Processor class. \n
     * It then checks the values of the saved vector by the inherited checkVals() method from the Processor class.
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
     * @brief Checks if scale value is valid. \n
     * Checks if the scale value is more than 1. If it is over 1, it sets it to 1. Otherwise, nothing happens.
     * 
     */
    void Echo::checkScale(){
        if (scale > 1) scale = 1;
    }
    /**
     * @brief Sets echo vector. \n
     * Sets class member echo to the sample via the inherited method getSample().
     * 
     */
    void Echo::setEcho(){
        echo = getSample();
    }
    /**
     * @brief Performs math to create an echo effect. \n
     * Iterates from the back of the echo vector to the delay point, both are class members. \n
     * It scales each element specially thus creating an echo effect. \n
     * It scales each element by setting the element to the scaled delayed element added to itself. \n
     * The scaled delayed element is calculated by the product of the scale and the previous element delay times before the current element.
     * 
     */
    void Echo::calculateFinalEcho(){
        for (int r = 0; r < repeat; r++){
            for (int i = echo.size()-1; i >= delay; i--){
                echo[i] += (echo[i-delay] * scale); 
            }    
        }
    }