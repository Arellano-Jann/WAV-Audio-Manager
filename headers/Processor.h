// Name: Jann Arellano

#pragma once
#define PROCESSOR_H
#include <iostream>
#include <vector>

/**
 * @brief A Processor parent class.
 * This class has a public constructor that initializes the sample.
 * It also has two other private member variables which are the highest and lowest possible values in the sample.
 * The class has a setter for the sample private member.
 * The class has getters for both the maxVal and minVal private members.
 * The class has a validation method to check if the values in sample are valid.
 * 
 */
class Processor{
    // processes a whole vector of samples
    std::vector<float> sample; // this works by having a constructor. 
    // the wav is casted as a processor object now.
    float maxVal = 1;
    float minVal = -1;
public:
    Processor(std::vector<float> const &samples) : sample(samples){}

    /**
     * @brief Set the Sample vector.
     * 
     * @param samples 
     */
    void setSample(std::vector<float> samples){ sample = samples;}
    /**
     * @brief Get the Sample vector.
     * 
     * @return std::vector<float> 
     */
    std::vector<float> getSample() const { return sample; }

    /**
     * @brief Get the max value (floating point) possible.
     * 
     * @return float 
     */
    float getMaxVal() const { return maxVal; }
    /**
     * @brief Get the min value (floating point) possible.
     * 
     * @return float 
     */
    float getMinVal() const { return minVal; }
    void checkVals();
};