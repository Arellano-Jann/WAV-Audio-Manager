// Name: Jann Arellano
#include "../headers/Processor.h"

    float Processor::ask(std::string question){ // overload to have a second param?
        float answer;
        std::cout << "What is the " << question << "? ";
        std::cin >> answer;
        return answer;
    }