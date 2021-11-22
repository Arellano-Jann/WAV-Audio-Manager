// Created by Alec Redera

#include <iostream>
#include <string>
#include "Wav.h"
#include "UI.h"
#include "Processor.h"

std::string InputVariable;
UI ui;

int main()
{    
    ui.UIStartMenu();

    while(true) {
        ui.UIInputPrompt();

        //UI::InputQuitMenu();
        std::cin >> InputVariable;

        if (InputVariable == "QUIT" || "Quit" || "quit") {
            ui.UIExitMenu();
            break;
        }

        else {
            ui.UIMeta(InputVariable);
            ui.UIProcessor();
            ui.UIRunProcessor();
        };
    }
return 0;
}