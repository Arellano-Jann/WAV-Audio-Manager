// Created by Alec Redera

#include <iostream>
#include "Wav.h"
#include "UI.h"

int main()
{    
    while() {
        UI::UIStartMenu()

        //UI::InputQuitMenu()
        std::cin >> InputVariable;

        if (InputVariable == "QUIT" || "Quit" || "quit") {
            UI::UIExitMenu()
        }

        else {
            Wav file;
            if(!file.SetFile(InputVariable)) {
                std::cout << "File doesn't exist or is not a .wav file.";
            }
            
            else {
                file.AnalyzeFile();
                std::cout << "Reading File..." << std::endl;
                file.GetFileName();
                file.GetSampleRate();
                file.GetBitsPerSample();
                file.GetStereo();
            }
        }
    }
return 0;
}