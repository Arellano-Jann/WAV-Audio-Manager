// Name: Jann Arellano
#include "Processor.h"

// To Do:
// After tests to make sure that it's good, we can now refactor
    
    void Processor::normalization(){
        //Algo: The largest sample value in the data is found, and 
        //then the data is scaled so that that max value in the data is the maximum possible value. 
        //This maximizes the amplitude of the final waveform.
        //Takes in a vector sample and normalizes it to max amplitude.
        
        float max = findMax();
        float min = findMin();
        float scale = findScale(min, max);
        gainAdjustment(scale);
    }
    
    void Processor::echo(){
        //Algo: Samples are copied, scaled, and 
        //added to later locations in the sample buffer to create an echo effect.

        //Takes in a float scale and int delay. Copies a vector and combines both vectors.
        float scale = ask("scale");
        int delay = (int) ask("delay");

        if (scale > 1){ scale = 1; }

        std::vector<float> echo = sample; //Copies a vector

        for (auto i = 0; i < echo.size(); i++){ // creates scaled echo vector
            echo[i] *= scale; // scales echo
        }
        
        //add echo[i] to sample[i] to calculate total wavelength
        for (auto i = delay; i < echo.size(); i++){
            sample[i] += echo[i-delay]; // adds echo to sample with an offset in echo so echo starts at 0
            if (sample[i] > maxVal) 
                sample[i] = maxVal; // checks if value is above maxVal
        }
        /// do we do checks on both echo and final echo???
        // ^^ what the fuck does this mean. i forgot what this meant. was this talking about the 255 check????
    }

    void Processor::gainAdjustment(){
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file

        float scale = ask("scale");
        
        for (auto &x : sample){// creates scaled echo vector
            x *= scale;
            if (x > maxVal) x = maxVal;  // checks if value is above maxVal
            if (x < minVal) x = minVal;
        }
    }

    void Processor::gainAdjustment(float scale){
        //Algo: Samples are multiplied by a scaling factor that raises or lowers 
        //the overall amplitude of the wave file

        for (auto &x : sample){// creates scaled echo vector
            x *= scale;
            if (x > maxVal) x = maxVal;  // checks if value is above maxVal
            if (x < minVal) x = minVal;
        }
    }

// CHALLENGE LEVEL

    void Processor::lowPassFilter(){
        //Algo: Remove components above a certain frequency specified.
        // Isolate the frequencies and remove the high frequencies. Now add those frequencies back together.

        //https://www.reddit.com/r/explainlikeimfive/comments/jm6lm/eli5_how_do_audio_lowpasshighpassetc_filters_work/
        
        /////////// fix this. you are doing volum. not freq. dumbass.
        float max = ask("max");
        for (auto &x : sample){// creates scaled echo vector
            if (x > max) x = max; // it says "remove" so i'm wondering 
            // if i should set it to 0 or max 
        }
    }

    // void Processor::compression(){
    //     //Algo: For volume over a specified max, it is scaled by a ratio
    //     // pass:increase. For every units passed, it increases from 
    //     // max by "increase".
    //     float pass = ask("pass"); // maybe need to overload bc "What is the pass?" 
    //                             // does not make too much sense
    //     float increase = ask("increase");
    //     float max = ask("max");

    //     float overflow;
    //     for (auto &x : sample){
    //         if (x > max){
    //             overflow = x - max; // overflow = nums past max
    //             x = max + (pass/overflow) * increase; // compresses
    //         }
    //     }
    // }

    void Processor::compression(){ // core dumps
        //Algo: For volume over a specified max, it is scaled by a ratio
        // max by "increase".
        // this overloads with int hold because it needs to be non linear
        // only compresses for a certain time after first instance 
        //// schedule office hours so that you know what he means by nonlinear map of input to output
        
        // has to be non linear so setup how long compressor can hold
        //https://www.reddit.com/r/explainlikeimfive/comments/1zfmew/eli5_compression_music_making/
        
        float pass = ask("pass threshold");
        float increase = ask("increase threshold");
        float max = ask("max");
        float hold = ask("hold");
        
        float overflow;
        int maxIndex;

        for (int i = 0; i < sample.size(); i++){
            // iterates through sample and finds first instance of anything over max
            if (sample[i] > max){
                maxIndex = i;
                break; // breaks loop so maxindex does not change
            }
        }
        
        for (maxIndex; maxIndex < (maxIndex+hold); maxIndex++){ 
            // iterates through first instance through the hold period
            if (sample[maxIndex] > max){ // makes sure it doesn't compress under max
                overflow = sample[maxIndex] - max;
                sample[maxIndex] = max + (overflow/pass) * increase; // compresses
                // increases by this much everytime it passes the max by this much
                // o/p calcs the pass to scale it correctly
            }
        }
    }




    // Helper Functions
    
    float Processor::findMax(){ // fix for array sample
        float max = minVal;
        for (auto x : sample){ // find max in data sample 
            if (x > max) max = x; 
        } /// find absolute value of max (if this doesn't work)
        return max;
    }
    float Processor::findMin(){
        float min = maxVal;
        for (auto x : sample){ // find min in data sample 
            if (x < min) min = x; 
        }
        return min;
    }

    float Processor::findScale(float min, float max){
        // find out if max or min is closer to mid

        max = maxVal/max; // calculates scale for max to maxcap 10/5 = 2
        min = minVal/min; // assumes min is negative. needs a check
        if (min < 0) min *= -1; // makes sure that we're not comparing a negative
        if (min < max) return min;
        return max;
    }

    float Processor::ask(std::string question){ // overload to have a second param?
        float answer;
        std::cout << "What is the " << question << "?" << std::endl;
        std::cin >> answer;
        return answer;
    }