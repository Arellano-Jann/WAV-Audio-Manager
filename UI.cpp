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

}*/

void UI::PrintMeta(Wav wav) {
    std::cout << wav.GetFileName() << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << wav.GetStereo() << std::endl;
    std::cout << "Sample Rate: " << wav.GetSampleRate() << std::endl;
    std::cout << "Bits Per Sample: " << wav.GetBitsPerSample() << std::endl;
}

std::string UI::ProcessorMenu() {
    std::cout << "This Program Allows You to Edit the Following:" << std::endl;
    std::cout << "(1) Normalization" << std::endl;
    std::cout << "(2) Echo" << std::endl;
    std::cout << "(3) Gain" << std::endl;
    std::cout << "(4) Low Pass Filter" << std::endl;
    std::cout << "(5) Compression" << std::endl;
    std::cout << std::endl;
    std::string selection;
    do
    {
        std::cout << "Enter the Number of the Processor Function You Would Like to Use." << std::endl;
        std::cout << "Or enter \"save\" to save your progress to a wav file." << std::endl;
        std::cin >> selection;
    } while(selection != "1" &&
          selection != "2" && 
          selection != "3" &&
          selection != "4" &&
          selection != "5" &&
          tolower(selection) != "save");
    return selection;
}

std::string UI::OutFileName() {
    std::cout << "Enter the Name of Your Output File:" << std::endl;
    std::string name;
    std::cin >> name;
    return name;
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