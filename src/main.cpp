// Created by Alec Redera

#include <iostream>
#include <string>
#include "../headers/UI.h"
#include "../headers/Wav.h"
#include "../headers/Processor.h"
#include "../headers/Normalization.h"
#include "../headers/Gain.h"
#include "../headers/Echo.h"
#include "../headers/Compressor.h"
#include "../headers/LowPassFilter.h"

int main()
{   
    // std::vector<float> examples;
    // examples.push_back(.1f);
    // examples.push_back(.2f);
    // examples.push_back(.3f);
    // examples.push_back(-.4f);
    // Processor p(examples);
    // p = Compressor(examples, 50, 1);
    // for (auto x : p.getSample()){
    //     std::cout << x << std::endl;
    // }
    // std::cout << std::endl;
    // p = Normalization(examples);
    // for (auto x : p.getSample()){
    //     std::cout << x << std::endl;
    // }
    UI ui;
    ui.StartMenu();
    //Getting Filename
    std::string filename = ui.Input();
    if (!ui.checkInput(filename)){
        ui.ExitMenu();
        exit(0);
    }
    
    //Setting Files
    Wav wav;
    if(wav.SetFile(filename))
    {
        wav.AnalyzeFile();

        ui.PrintMetaData(wav);

        // bool done = false;
        // while(!done)
        // {
            ui.ProcessorMenu();
            int selection = ui.selectProcessor();
            
            // Processing
            Processor p(wav.GetSamples());
            switch (selection){
                float parameterOne;
                float parameterTwo;
                case 1: 
                    p = Normalization(wav.GetSamples());
                    break;
                case 2:
                    ui.askProcessorQuestions(1);
                    std::cin >> parameterOne;
                    ui.askProcessorQuestions(2);
                    std::cin >> parameterTwo;
                    p = Echo(wav.GetSamples(), parameterOne, parameterTwo);
                    break;
                case 3:
                    ui.askProcessorQuestions(1);
                    std::cin >> parameterOne;
                    p = Gain(wav.GetSamples(), parameterOne);
                    break;
                case 4:
                    ui.askProcessorQuestions(5);
                    std::cin >> parameterOne;
                    p = LowPassFilter(wav.GetSamples(), parameterOne);
                    break;
                case 5:
                    ui.askProcessorQuestions(3);
                    std::cin >> parameterOne;
                    ui.askProcessorQuestions(4);
                    std::cin >> parameterTwo;
                    p = Compressor(wav.GetSamples(), parameterOne, parameterTwo);
                    break;
                case 6:
                    // std::string output = ui.OutputFileName();
                    // wav.setSamples(p.getSample());
                    // wav.CreateFile(output);
                    // done = true;
    std::cout << "is this where you're breaking 91";
                    break;
            // }
        }
    }
    else
    {
        // ui.InvalidFileName();
    }
    // go to start
    std::cout << "is this where you're breaking 100";

    

    // tested to do gain and then normalization one after another
    // another with echo and then normalization
    // it doesn't work when two compounding processors are one after another
    // this is because examples isn't hard changed. will need to fix that?

    /*
    
    UI ui;
    bool done = false;
    while(!done)
    {
        ui.StartMenu();
        std::string in = ui.InputFileName();
        std::transform(in.begin(), in.end(), in.begin(), std::tolower);
        if(in == "quit")
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
                    std::transform(selection.begin(), selection.end(), selection.begin(), std::tolower);
                    if(selection == "1")
                    {
                        Normalization n(w.GetSamples());
                    }
                    else if(selection == "2")
                    {
                        // get scale, delay
                        Echo e(w.GetSamples());
                    }
                    else if(selection == "3")
                    {
                        // get scale
                        Gain g(w.GetSamples());
                    }
                    else if(selection == "4")
                    {
                        // get scale
                        LowPassFilter f(w.GetSamples());
                    }
                    else if(selection == "5")
                    {
                        // get scale
                        Compressor c(w.GetSamples());
                    }
                } while(selection != "s" && selection != "S");
                std::string newFileName = ui.OutFileName();
                if(w.CreateFile(newFileName))
                {
                    
                }
                else
                {

                }                
            }
            else
            {
                std::cout << "File doesn't exist or is not a valid .wav file.";
                // go to start menu
            }
        }
    } 
    */
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