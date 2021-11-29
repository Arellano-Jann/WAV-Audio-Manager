#include "../headers/Compressor.h"

    /**
     * @brief Construct a new Compressor object
     * This constructor initializes it's parameters into the class's private members using an initializer list.
     * This constructor calls the Processor class's constructor using samples.
     * The constructor calls the private void process() method.
     * 
     * @param samples A vector that will be processed using private methods.
     * @param ratio A float (multiplied by .01) used to compress values. The input is a percentage.
     * @param max A float (multiplied by .01) used to determine the max value before compression. The input is a percentage.
     */
    Compressor::Compressor(std::vector<float> samples, float ratio, float max)
        : Processor(samples)
        , max(max*.01)
        , ratio(ratio*.01)
        {
        //Algo: For volume over a specified max, it is scaled by a ratio
        
        //https://www.reddit.com/r/explainlikeimfive/comments/1zfmew/eli5_compression_music_making/
        process();
    }

    /**
     * @brief Compresses samples and checks if values are valid.
     * Calls the void compress() method to compress the passed in vector of samples. After, it saves the new vector by calling the inherited setSample() method from the Processor class. It then checks the values of the saved vector by the inherited checkVals() method from the Processor class.
     * 
     */
    void Compressor::process(){
        compress();
        setSample(compressed);
        checkVals();
    }

    /**
     * @brief Compresses samples and puts it into a new vector.
     *  Iterates through each element in the sample. Then, if the element exceeds the class member max, it compresses the element by the class member ratio. Finally, it adds it to the compressed vector, a class member.
     * The compression is calculated by adding max to the product of ratio and overflow (max + ratio * overflow). Overflow is calculated by the difference between the current element and max.
     * 
     */
    void Compressor::compress(){
        float overflow;
        for (auto x : getSample()){
            if (x > max){
                overflow = x - max;
                x = max + ratio * overflow;
            }
            compressed.push_back(x);
        }
    }