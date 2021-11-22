// Created by Alec Redera

#include <iostream>
#include <string>
#include "UI.h"
#include "Processor.h"
#include "Wav.h"

int main()
{   
    std::vector<float> examples;
    examples.push_back(0.45f);
    examples.push_back(0.23);
    examples.push_back(-0.45f);
    examples.push_back(0.35f);
    Processor p(examples);
    p.gainAdjustment();
    examples = p.getVec();
    for (auto x : p.getVec()){
        std::cout << x << std::endl;
    }
    
    /*UI ui;
    ui.StartMenu();
    std::string in = ui.InputFileName();
    if(tolower(in) == "quit")
    {
        ui.ExitMenu();
    }
    else
    {
        Wav w;
        if(w.SetFile(in))
        {
            
        }
        else
        {
            std::cout << "File doesn't exist or is not a .wav file.";
        }
    }*/
    /*
    while(true) {
        ui.UIInputPrompt();

        //UI::InputQuitMenu();
        std::cin >> input;

        if (input == "QUIT" || "Quit" || "quit") {
            ui.UIExitMenu();
            break;
        }

        else {
            ui.UIMeta(input);
            ui.UIProcessor();
            ui.UIRunProcessor();
        };
    }*/
return 0;
}