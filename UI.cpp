// Created by Alec Redera

#include <iostream>
#include <string>
#include "UI.h"
#include "Wav.h"

std::string InputVariable;
std::string filename;
UI ui;

void UI::UIStartMenu() {
    std::cout << "This Program Can Load and Modify WAV Files." << std::endl;
    std::cout << "To Begin, Please Enter the Name of a WAV File, or Enter \"Quit\" to Exit the Program." << std::endl;
    std::cout << "Enter WAV Filename:" << std::endl;
}

void UI::UIExitMenu() {
    std::cout << "Goodbye!" << std::endl;
}

void UI::UIInputQuitMenu() {
    std::cin >> InputVariable;

        if (InputVariable == "QUIT" || "Quit" || "quit") {
            ui.UIExitMenu();
        }

        else {
            ui.UIProgram(filename);
        }
}

void UI::UIProgram(std::string filename){
    Wav w;
    if(!w.SetFile(filename))
    {
        std::cout << "File doesn't exist or is not a .wav file.";
    }
    w.AnalyzeFile();
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
    present user with processor menu // create a function with some UI for calling my code.
                                    // doesn't matter how you call my code
                                    // you can even just put normalization(). should be fine
    If user selects processor option // this running should be it's own function ex: run(normalization()) etc.
      request output filename // the run command would do this and below
      run processor
      save file // can't do this yet. just comment where this would go
      goto Start // doable
*/