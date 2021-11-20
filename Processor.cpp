// Name: Jann Arellano
#include "Processor.h"

//Steps:
// Convert all methods so that it only takes in the array
// Double check all methods
/// make sure it converts between -1 and 1
// After tests to make sure that it's good, we can now 

// just use vector
// have a constructor and take in the array (hard to do since you can't have a member variable as an array without knowing size)
// ^^ try that again
// take in an array into processor methods. 
    
    void Processor::normalization(float (&sample)[]){
        //Algo: The largest sample value in the data is found, and 
        //then the data is scaled so that that max value in the data is the maximum possible value. 
        //This maximizes the amplitude of the final waveform.
        //Takes in a vector sample and normalizes it to max amplitude.
        
        float max = 0;
        float min = 255;
        float scale = 0;
        max = findMax(sample, max); // (max) is not needed here
        // ^^ i think i need to pass in sample here
        min = findMin(sample, min); // but used to make code less lines
        scale = findScale(min, max, scale);
        // gainAdjustment(scale);
    }
    
//     void Processor::echo(){
//         //Algo: Samples are copied, scaled, and 
//         //added to later locations in the sample buffer to create an echo effect.

//         //Takes in a float scale and int delay. Copies a vector and combines both vectors.
//         float scale = ask("scale");
//         int delay = (int) ask("delay");

//         if (scale > 1){ scale = 1; }

//         float echo[size(sample)];
//         // = sample; //Copies a vector // iterate through sample and copy sample to echo one by fucking one.
//         // ^^ for each loop

//         for (auto i = delay; i < size(echo); i++){ // creates scaled echo vector
//         // potential issue: if we start from index "not 0," does that mean that everything
//         // before index "not 0" would be null or 0?
//             echo[i] = sample[i - delay] * scale; 
//         }
//         // if the above does not work, we can do a simpler algo since we have two same arrays
//         // we can just move all the elements by delay and input 0 at the start "delay times"
        
//         //add echo[i] to sample[i] to calculate total wavelength
//         for (auto i = 0; i < size(echo); i++){
//             echo[i] += sample[i]; /// does this work? hopefully.
//             if (echo[i] > 255){ // change this so that it scales with -1 and 1
//                 echo[i] = 255;
//             }
//         }
//         /// do we do checks on both echo and final echo???
//         // ^^ what the fuck does this mean. i forgot what this meant. was this talking about the 255 check????
//     }

//     void Processor::gainAdjustment(){
//         //Algo: Samples are multiplied by a scaling factor that raises or lowers 
//         //the overall amplitude of the wave file

//         ///don't know if ample is correct but we want to change sample here

//         float scale = ask("scale");
        
//         for (auto &x : sample){// creates scaled echo vector
//             x *= scale;
//             if (x > scaleMax){ x = scaleMax; } // checks if value is above 255
//             if (x < 0){ x = 0; } // checks if value is below 0
//         }
//     }

//     void Processor::gainAdjustment(float scale){
//         //Algo: Samples are multiplied by a scaling factor that raises or lowers 
//         //the overall amplitude of the wave file

//         for (auto &x : sample){// creates scaled echo vector
//             x *= scale;
//             if (x > scaleMax){ x = scaleMax; } // checks if value is above 255
//                             // scaleMax is in the h file. need to check for -1,1
//             if (x < 0){ x = 0; } // checks if value is below 0
//         }
//     }

// // CHALLENGE LEVEL

//     void Processor::lowPassFilter(){
//         //Algo: Remove components above a certain frequency specified.
//         // Isolate the frequencies and remove the high frequencies. Now add those frequencies back together.

//         //https://www.reddit.com/r/explainlikeimfive/comments/jm6lm/eli5_how_do_audio_lowpasshighpassetc_filters_work/
//         // fix this. you are doing volum. not freq
//         float max = ask("max");
//         for (auto &x : sample){// creates scaled echo vector
//             if (x > max){
//                 x = max; // it says "remove" so i'm wondering 
//             } // if i should set it to 0 or max 
//         }
//     }

//     // void Processor::compression(){
//     //     //Algo: For volume over a specified max, it is scaled by a ratio
//     //     // pass:increase. For every units passed, it increases from 
//     //     // max by "increase".
//     //     float pass = ask("pass"); // maybe need to overload bc "What is the pass?" 
//     //                             // does not make too much sense
//     //     float increase = ask("increase");
//     //     float max = ask("max");

//     //     float overflow;
//     //     for (auto &x : sample){
//     //         if (x > max){
//     //             overflow = x - max; // overflow = nums past max
//     //             x = max + (pass/overflow) * increase; // compresses
//     //         }
//     //     }
//     // }

//     void Processor::compression(){
//         // this overloads with int hold because it needs to be non linear
//         // only compresses for a certain time after first instance 
//         //// schedule office hours so that you know what he means by nonlinear map of input to output
        
//         // has to be non linear so setup how long compressor can hold
//         //https://www.reddit.com/r/explainlikeimfive/comments/1zfmew/eli5_compression_music_making/
        
//         float pass = ask("pass"); // maybe need to overload bc "What is the pass?" 
//                                 // does not make too much sense
//         float increase = ask("increase");
//         float max = ask("max");
//         float hold = ask("hold");
        
//         float overflow;
//         int maxIndex;
//         for (int i = 0; i < size(sample); i++){
//             // iterates through sample and finds first instance of anything over max
//             if (sample[i] > max){
//                 maxIndex = i;
//                 break; // breaks loop so maxindex does not change
//             }
//         }
        
//         for (maxIndex; maxIndex < (maxIndex+hold); maxIndex++){ 
//             // iterates through first instance through the hold period
//             if (sample[maxIndex] > max){ // makes sure it doesn't compress under max
//                 overflow = sample[maxIndex] - max;
//                 sample[maxIndex] = max + (overflow/pass) * increase; // compresses
//             }
//         }
//     }




    // Helper Functions
    
    float Processor::findMax(float (&sample)[], float max){ // fix for array sample
        for (auto x : sample){ // find max in data sample 
            if (x > max){ max = x; }
        } /// find absolute value of max (if this doesn't work)
        return max;
    }
    float Processor::findMin(float (&sample)[], float min){
        for (auto x : sample){ // find min in data sample 
            if (x < min){ min = x; }
        }
        return min;
    }

    float Processor::findScale(float min, float max, float scale){
        // find out if max or min is closer to mid
        float temp = max - 255; // 255 needs to change depending on the bit depth
        temp -= temp*-1; // gives absolute value by multiplying by -1
        if (temp > min){ scale = min; }
        else { scale = max; }
        
        if (scale < 128) // ensures correct scaling to caps
            scale = 255 - scale; // 255 needs to change
        return scale /= 255; // finds scaleValue to normalize sample
    }

    float Processor::ask(std::string question){ // overload to have a second param?
        float answer;
        std::cout << "What is the " << question << "?" << std::endl;
        std::cin >> answer;
        return answer;
    }

    int Processor::size(float arr[]){
      return sizeof(&arr)/sizeof(arr[0]);
    }