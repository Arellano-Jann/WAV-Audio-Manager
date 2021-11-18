// Created by Alec Redera

#include <iostream>
#include <string>
#include "UI.h"

std::string InputVariable;
UI ui;

void UIStartMenu() {
    std::cout << "This Program Can Load and Modify WAV Files." << std::endl;
    std::cout << "To Begin, Please Enter the Name of a WAV File, or Enter \"Quit\" to Exit the Program." << std::endl;
    std::cout << "Enter WAV Filename:" << std::endl;
}

void UIExitMenu() {
    std::cout << "Goodbye!" << std::endl;
}

void UIInputQuitMenu() {
    std::cin >> InputVariable;

        if (InputVariable == "QUIT" || "Quit" || "quit") {
            ui.UIExitMenu();
        }

        else {
            ui.UIProgram();
        }
}

void UIProgram(){

}