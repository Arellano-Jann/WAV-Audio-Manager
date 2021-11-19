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
    read file metadata
(1) display metadata to user
    present user with processor menu
    If user selects processor option
      request output filename
      run processor
      save file
      goto Start
*/