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