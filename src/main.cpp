// Created by Alec Redera

#include <iostream>
#include <string>
#include <memory>
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

        bool done = false;
        std::shared_ptr<Processor> p{new Processor (wav.GetSamples())};
        while(!done)
        {
            ui.ProcessorMenu();
            int selection = ui.selectProcessor(); // uncomment
            
            // Processing

            // Processor p(wav.GetSamples());
            // std::cout << "is this where you're breaking 60";
                    // p = std::shared_ptr<Processor> {new Normalization(wav.GetSamples())};
                    // p = Normalization(wav.GetSamples());
                    // std::cout << "is this where you're breaking 62";
                    

            switch (selection){
                float parameterOne;
                float parameterTwo;
                case 1: 
                    p = std::shared_ptr<Processor> {new Normalization(wav.GetSamples())};
                    // p = Normalization(wav.GetSamples());
                    break;
                case 2:
                    ui.askProcessorQuestions(1);
                    std::cin >> parameterOne;
                    ui.askProcessorQuestions(2);
                    std::cin >> parameterTwo;
                    p = std::shared_ptr<Processor> {new Echo(wav.GetSamples(), parameterOne, parameterTwo)};
                    // p = Echo(wav.GetSamples(), parameterOne, parameterTwo);
                    break;
                case 3:
                    ui.askProcessorQuestions(1);
                    std::cin >> parameterOne;
                    for (auto x : p->getSample()){
                    std::cout << x << " ";
                    break;
                    }
                    p = std::shared_ptr<Processor> {new Gain(wav.GetSamples(), parameterOne)};
                    wav.setSamples(p->getSample());
                    for (auto x : wav.GetSamples()){
                    std::cout << x << " ";
                    break;
                    }
                    std::cout << std::endl;
                    for (auto x : p->getSample()){
                    std::cout << x << " ";
                    break;
                    }
                    // p = Gain(wav.GetSamples(), parameterOne);
                    break;
                case 4:
                    ui.askProcessorQuestions(5);
                    std::cin >> parameterOne;
                    p = std::shared_ptr<Processor> {new LowPassFilter(wav.GetSamples(), parameterOne)};
                    // p = LowPassFilter(wav.GetSamples(), parameterOne);
                    break;
                case 5:
                    ui.askProcessorQuestions(3);
                    std::cin >> parameterOne;
                    ui.askProcessorQuestions(4);
                    std::cin >> parameterTwo;
                    p = std::shared_ptr<Processor> {new Compressor(wav.GetSamples(), parameterOne, parameterTwo)};
                    // p = Compressor(wav.GetSamples(), parameterOne, parameterTwo);
                    // wav.setSamples(p->getSample());
                    break;
                case 6: // consider putting this outside the switch.
                    std::string output = ui.OutputFileName();
                    wav.setSamples(p->getSample());
                    wav.CreateFile(output);
                    done = true;
                    break;
            }
        }

        // std::string output = ui.OutputFileName();
        // wav.setSamples(p->getSample()); // same as below?
        // wav.CreateFile(output);

    }
    else
    {
         ui.InvalidFileName();
    }
    // go to start
    // std::cout << "is this where you're breaking 100";
    // std::string output = ui.OutputFileName(); // why is this and 9 lines above the same??
    // wav.setSamples(p.getSample());
    // wav.CreateFile(output);

    

    // tested to do gain and then normalization one after another
    // another with echo and then normalization
    // it doesn't work when two compounding processors are one after another
    // this is because examples isn't hard changed. will need to fix that?


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