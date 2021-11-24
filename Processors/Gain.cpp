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