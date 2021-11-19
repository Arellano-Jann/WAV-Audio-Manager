// Created by Alec Redera

#include <iostream>
#include <string>
//#include "Wav.h"
#include "UI.h"

std::string InputVariable;
UI ui;

int main()
{    
    while(true) {
        ui.UIStartMenu();

        //UI::InputQuitMenu();
        std::cin >> InputVariable;

        if (InputVariable == "QUIT" || "Quit" || "quit") {
            ui.UIExitMenu();
            break;
        }

        else {
            ui.UIProgram(InputVariable);
        };
    }
return 0;
}