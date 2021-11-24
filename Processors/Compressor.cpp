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
