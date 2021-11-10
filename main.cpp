// Created by Alec Redera

#include <iostream>
#include <string>
#include "Wav.h"

std::string InputVariable;

int main()
{
    std::cout << "This Program Can Load and Modify WAV Files." << std::endl;
    std::cout << "To Begin, Please Enter the Name of a WAV File, or Enter \"Quit\" to Exit the Program." << std::endl;
    std::cout << "Enter WAV Filename:" << std::endl;

    std::cin >> InputVariable;

    if (InputVariable == "QUIT" || "Quit" || "quit") {
        std::cout << "Goodbye!" << std::endl;
    }

    else {
        //Not sure which function I'm supposed to lead into. I think Andrew's?
        std::cout << "Hi!" << std::endl;
    }

return 0;
}

//Not sure what this function in main did, or if it should be in a separate file.
/*
int main()
{
    Wav w;
    if(!w.SetFile("one_small_step.wav"))
    {
        std::cout << "File doesn't exist or is not a .wav file.";
    }
    w.AnalyzeFile();
    
    
    return 0;
}
*/