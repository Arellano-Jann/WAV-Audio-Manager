// Created by Alec Redera

#include <iostream>
#include <string>
#include "Wav.h"
#include "UI.h"

std::string InputVariable;

int main()
{    
    while() {
        UI::UIStartMenu()

        //UI::InputQuitMenu()
        std::cin >> InputVariable;

        if (InputVariable == "QUIT" || "Quit" || "quit") {
            UI::UIExitMenu()
            break;
        }

        else {
            UI::UIProgram()
        }
    }
return 0;
}