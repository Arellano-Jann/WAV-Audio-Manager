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
                float parameterThree;
                case 1: 
                    p = std::shared_ptr<Processor> {new Normalization(wav.GetSamples())};
                    wav.setSamples(p->getSample());
                    break;
                case 2:
                    ui.askProcessorQuestions(1);
                    std::cin >> parameterOne;
                    ui.askProcessorQuestions(2);
                    std::cin >> parameterTwo;
                    ui.askProcessorQuestions(6);
                    std::cin >> parameterThree;
                    p = std::shared_ptr<Processor> {new Echo(wav.GetSamples(), parameterOne, parameterTwo, parameterThree)};
                    wav.setSamples(p->getSample());
                    break;
                case 3:
                    ui.askProcessorQuestions(1);
                    std::cin >> parameterOne;
                    p = std::shared_ptr<Processor> {new Gain(wav.GetSamples(), parameterOne)};
                    wav.setSamples(p->getSample());
                    break;
                case 4:
                    ui.askProcessorQuestions(5);
                    std::cin >> parameterOne;
                    p = std::shared_ptr<Processor> {new LowPassFilter(wav.GetSamples(), parameterOne)};
                    wav.setSamples(p->getSample());
                    break;
                case 5:
                    ui.askProcessorQuestions(3);
                    std::cin >> parameterOne;
                    ui.askProcessorQuestions(4);
                    std::cin >> parameterTwo;
                    p = std::shared_ptr<Processor> {new Compressor(wav.GetSamples(), parameterOne, parameterTwo)};
                    wav.setSamples(p->getSample());
                    break;
                case 6: // consider putting this outside the switch.
                    std::string output = ui.OutputFileName();
                    wav.setSamples(p->getSample());
                    wav.CreateFile(output);
                    done = true;
                    break;
            }
        }
    }
    else
    {
         ui.InvalidFileName();
    }
return 0;
}