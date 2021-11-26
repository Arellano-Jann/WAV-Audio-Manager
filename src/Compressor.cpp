#include "../headers/Compressor.h"

    Compressor::Compressor(std::vector<float> samples, float ratio, float max)
        : Processor(samples)
        , max(max)
        , ratio(ratio)
        {
        // core dumps
        //Algo: For volume over a specified max, it is scaled by a ratio
        // max by "increase".
        // this overloads with int hold because it needs to be non linear
        // only compresses for a certain time after first instance
        
        // has to be non linear so setup how long compressor can hold
        //https://www.reddit.com/r/explainlikeimfive/comments/1zfmew/eli5_compression_music_making/
        process();
    }

    void Compressor::process(){
        compress();
        checkVals();
    }

    void Compressor::compress(){
        float overflow;
        for (auto &x : getSample()){
            if (x > max){
                overflow = x - max;
                x = max + ratio * overflow;
            }
        }
    }
