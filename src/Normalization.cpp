#include "../headers/Normalization.h"
#include <iostream>

    /**
     * @brief Constructs a new Compressor object. \n
     * This constructor calls the Gain class's constructor using samples and 100, a float. \n
     * The constructor calls the private void process() method.
     * 
     * @param samples (A vector that will be processed using private methods.)
     */
    Normalization::Normalization(std::vector<float> samples)
    : Gain(samples, 100)
    {
        //Algo: The largest sample value in the data is found, and 
        //then the data is scaled so that that max value in the data is the maximum possible value. 
        //This maximizes the amplitude of the final waveform.
        //Takes in a vector sample and normalizes it to max amplitude.
        process(samples);
    }    

    /**
     * @brief Finds the scale to use and calls the gain constructor using samples and the scale. \n
     * Finds the minimum and maximum values in samples using the float-return findMin() and findMax() method. \n
     * It saves both values to a float variable. \n
     * Next, it then calls the float-return findScale() method using the two newly saved min and maxes. \n
     * It saves the float returned to a float variable named scale. \n
     * Then, it calls the Gain constructor using samples and scale thus creating a new scaled vector within the Gain object. \n
     * After, it saves the new vector by calling the inherited setSample() method from the Processor class \n
     * and the inherited getGain() method from the Gain class. \n
     * It then checks the values of the saved vector by the inherited checkVals() method from the Processor class.
     * 
     * @param samples 
     */
    void Normalization::process(std::vector<float> samples){
        float max = findMax();
        float min = findMin();
        float scale = findScale(min, max)*100;
        Gain g(samples, scale);
        setSample(g.getGain());
        checkVals();
    }

    /**
     * @brief Finds the max value in the sample. \n
     * Sets a float max variable to the lowest possible value in the sample via the inherited method getMinVal(). \n
     * After, it iterates through the elements in the sample. \n
     * If an element exceeds the current max value, the element is saved as the new max value. \n
     * At the end of the iteration, the max value in samples is returned.
     * 
     * @return float (The max value in samples.)
     */
    float Normalization::findMax(){
        float max = getMinVal();
        for (auto x : getSample()){ 
            if (x > max) max = x; 
        }
        return max;
    }
    /**
     * @brief Finds the min value in the sample. \n
     * Sets a float min variable to the highest possible value in the sample via the inherited method getMaxVal(). \n
     * After, it iterates through the elements in the sample. \n
     * If the min value exceeds the current element, the element is saved as the new min value. \n
     * At the end of the iteration, the min value in samples is returned.
     * 
     * @return float (The min value in samples.)
     */
    float Normalization::findMin(){
        float min = getMaxVal();
        for (auto x : getSample()){ 
            if (x < min) min = x;
            // Using Ternary: x = (x < min) ? min : x;
        }
        return min;
    }

    /**
     * @brief Calculates the scale that would be used for min and max and compares them. It returns the smaller scale. \n
     * Calculates the scale for the max via the inherited getMaxVal() method divided by the inputted max. \n
     * Then, it calculates the scale for the min via the inherited getMinVal() method divided by the inputted min. \n
     * It then makes sure min is a positive by multiplying it by -1 if it is a negative. \n
     * This is to ensure that we're comparing positive values. \n
     * Finally, it returns the lesser of the two calculations.
     * 
     * @param min (The minimum possible value.)
     * @param max (the maximum possible value.)
     * @return float (The lowest scale to get a value from samples to the maximum or minimum possible value.)
     */
    float Normalization::findScale(float min, float max){
        max = getMaxVal()/max;
        min = getMinVal()/min; // assumes min is negative
        if (min < 0) min *= -1; // makes sure that we're not comparing a negative
        if (min < max) return min;
        return max;
    }
