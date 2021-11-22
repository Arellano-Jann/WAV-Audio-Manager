// Created by Alec Redera
#include "UI.h"
#include <iostream>

void UI::StartMenu() {
    std::cout << "This Program Can Load and Modify WAV Files." << std::endl;
    std::cout << "To Begin, ";
}

std::string UI::InputFileName() {
    std::string name;
    std::cout << "Please Enter the Name of a WAV File, or Enter \"Quit\" to Exit the Program." << std::endl;
    std::cout << "Enter WAV Filename:" << std::endl;
    std::cin >> name;
    return name;
}

void UI::ExitMenu() {
    std::cout << "Goodbye!" << std::endl;
}

//void UI::InputQuitMenu() {
/*    std::cin >> InputVariable;

        if (InputVariable == "QUIT" || "Quit" || "quit") {
            ui.ExitMenu();
        }

        else {
            ui.Meta(filename);
        }
*/
}

void UI::Meta(std::string filename) {
    if(!w.SetFile(filename))
    {
        std::cout << "File doesn't exist or is not a .wav file.";
    }
    w.AnalyzeFile();

    //No idea if I did this right. HELP REQUESTED.
    std::cout << filename << std::endl;
    std::cout << w.GetStereo();
    std::cout << w.GetSampleRate();
    std::cout << w.GetByteRate();
    std::cout << w.GetBitsPerSample();
    std::cout << w.GetBlockAlign();
    //std::cout << w.GetSamples();
    //GetSamples has some errors I don't know how to fix.
}

void UI::Processor() {
    std::cout << "This Program Allows You to Edit the Following:" << std::endl;
    std::cout << "- Normalization" << std::endl;
    std::cout << "- Echo" << std::endl;
    std::cout << "- Gain" << std::endl;
    std::cout << "- Low Pass Filter" << std::endl;
    std::cout << "- Compression" << std::endl;
    std::cout << std::endl;
    std::cout << "Please Enter the Name of Your Output File,";
    std::cout << "Then Enter the Name of the Processor Function You Would Like to Use." << std::endl;
}

void UI::RunProcessor() {
    std::cout << "Enter the Name of Your Output File:" << std::endl;

    std::cin >> OutputFileName;

    std::cout << "Enter the Name of the Processor Function You Would Like to Use:" << std::endl;

    std::cin >> ProcessorName;

    if(ProcessorName == "Normalization" || "NORMALIZATION" || "normalization"){
        p.normalization();
        //Save File (OutputFileName?)
    }

    else if(ProcessorName == "Echo" || "ECHO" || "echo") {
        p.echo();
        //Save File (OutputFileName?)
    }

    else if(ProcessorName == "Gain" || "GAIN" || "gain") {
        //So... There are two gainAdjustment functions?
        //Not sure what to do here.
        p.gainAdjustment();
        //Save File (OutputFileName?)
    }

    else if(ProcessorName == "LowPassFilter" || "LOWPASSFILTER" || "lowpassfilter") {
        p.lowPassFilter();
        //Save File (OutputFileName?)
    }

    else if(ProcessorName == "Compression" || "COMPRESSION" || "compression") {
        p.compression();
        //Save File (OutputFileName?)
    }
}

//Pseudo ~
/*
// So what i kinda want you to do is separate all of these functions into
// different functions. like how start menu and exit has it's own function
// i will be marking what you can put in a function below

//Complete
Start: Present start menu
If user selects quit, exit program
Else
  Request filename from user
  Open file specified by filename
  If file does not exist or file is not wav file
    display error message and goto start

//Incomplete
  else
    read file metadata // doable. write a function to call the getters in wav.cpp
(1) display metadata to user // ^^ conjunction with above

//Complete
    present user with processor menu // create a function with some UI for calling my code.
                                    // doesn't matter how you call my code
                                    // you can even just put normalization(). should be fine
    If user selects processor option // this running should be it's own function ex: run(normalization()) etc.
      request output filename // the run command would do this and below
      run processor
      save file // can't do this yet. just comment where this would go
      goto Start // doable
*/