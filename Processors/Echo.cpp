void Processor::echo(){
        //Algo: Samples are copied, scaled, and 
        //added to later locations in the sample buffer to create an echo effect.

        //Takes in a float scale and int delay. Copies a vector and combines both vectors.
        float scale = ask("scale in percent") * .01;
        int delay = (int) ask("delay");

        if (scale > 1){ scale = 1; }

        std::vector<float> echo = sample; //Copies a vector

        for (auto i = 0; i < sample.size(); i++){ // creates scaled echo vector
            echo[i] *= scale; // scales echo
        }
        
        //add echo[i] to sample[i] to calculate total wavelength
        for (auto i = delay; i < sample.size(); i++){
            sample[i] += echo[i-delay]; // adds echo to sample with an offset in echo so echo starts at 0
            if (sample[i] > maxVal) 
                sample[i] = maxVal; // checks if value is above maxVal
            if (sample[i] < minVal) 
                sample[i] = minVal; // checks if value is above maxVal
        }
        /// do we do checks on both echo and final echo???
        // ^^ what the fuck does this mean. i forgot what this meant. was this talking about the 255 check????
    }