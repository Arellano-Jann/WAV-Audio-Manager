// Created by Alec Redera

#include <iostream>
#include <string>
#include "../headers/UI.h"
#include "../headers/Processor.h"
#include "../headers/Wav.h"

int main()
{   
    std::vector<float> examples;
    examples.push_back(1.45f);
    examples.push_back(1);
    examples.push_back(0.0f);
    examples.push_back(-.99f);
    Processor p(examples);
    // p.compression();
    // test out all classes and see if it does what it needs to do
    for (auto x : p.getSample()){
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
                Processor p(w.getSamples());
                std::string selection;
                do
                {
                    selection = ui.ProcessorMenu();
                    switch(selection)
                    {
                        case "1":
                        {
                            p.normalization();
                            break;
                        }
                        case "2":
                        {
                            p.echo();
                            break;
                        }
                        case "3":
                        {
                            p.gain();
                            break;
                        }
                        case "4":
                        {
                            p.lowpass();
                            break;
                        }
                        case "5":
                        {
                            p.compression();
                            break;
                        }
                    }
                } while(tolower(selection) != "save")
                std::string newFileName = ui.OutFileName();
                
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