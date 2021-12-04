#include "../headers/LowPassFilter.h"

    LowPassFilter::LowPassFilter(std::vector<float> samples, int destruction)
        : Processor(samples)
        , destruction(destruction)
        {
        //Algo: Remove components above a certain frequency specified.
        // Isolate the frequencies and remove the high frequencies. Now add those frequencies back together.

        //https://www.reddit.com/r/explainlikeimfive/comments/jm6lm/eli5_how_do_audio_lowpasshighpassetc_filters_work/
        
        process();

    }

    void LowPassFilter::process(){
        setLowPassFilter();
        destroyHighFreq();
        setSample(lpf);
        checkVals();
    }

    void LowPassFilter::setLowPassFilter(){
        lpf = getSample();
    }
    void LowPassFilter::destroyHighFreq(){ // this doesn't work/i'm not inputting the correct things. fouriers transform. i need it.
        for (int i = lpf.size()-1; i >= destruction; i--){
            lpf[i] += (lpf[i-destruction]); 
        }
    }