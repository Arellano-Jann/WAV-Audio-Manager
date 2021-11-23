// Created by Alec Redera

#include <iostream>
#include <string>
#include "UI.h"
#include "Processor.h"
#include "Wav.h"

int main()
{   
    std::vector<float> examples;
    examples.push_back(1.45f);
    examples.push_back(1);
    examples.push_back(0.0f);
    examples.push_back(-.99f);
    Processor p(examples);
    p.compression();
    for (auto x : p.getVec()){
        std::cout << x << std::endl;
    }
    
    /*UI ui;
    bool done = false;
    while(!done)
    {
        ui.StartMenu();
        std::string in = ui.InputFileName();
        if(tolower(in) == "quit")
        {
            ui.ExitMenu();
            done = true;
        }
        else
        {
            Wav w;
            if(w.SetFile(in))
            {
                w.AnalyzeFile();
                ui.PrintMeta(w);
                std::string selection;
                do
                {
                    selection = ui.ProcessorMenu();
                    switch(selection)
                    {
                        case "1":
                        {
                            break;
                        }
                        case "2":
                        {
                            break;
                        }
                        case "3":
                        {
                            break;
                        }
                        case "4":
                        {
                            break;
                        }
                        case "5":
                        {
                            break;
                        }
                        default:
                        {
                            
                        }
                    }
                } while(selection != "save")
            }
            else
            {
                std::cout << "File doesn't exist or is not a valid .wav file.";
                // go to start menu
            }
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