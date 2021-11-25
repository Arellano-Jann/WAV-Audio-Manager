// Name: Jann Arellano
#include "../headers/Processor.h"

    float Processor::ask(std::string question){ // overload to have a second param?
        float answer;
        std::cout << "What is the " << question << "? ";
        std::cin >> answer;
        return answer;
    }

    void Processor::checkVals(){
        for (auto &x : sample){
            if (x > getMaxVal()) 
                x = getMaxVal(); // checks if value is above maxVal
            if (x < getMinVal()) 
                x = getMinVal(); // checks if value is above maxVal
        }
    
    }