// Created by Alec Redera

#include <iostream>
#include <string>
#include "Wav.h"
#include "WaveHeader.h"

class UI {

public:
    void UIStartMenu();
    void UIInputPrompt();
    void UIExitMenu();
    void UIInputQuitMenu();
    void UIMeta(std::string filename);
    void UIProcessor();
    void UIRunProcessor();

    std::string InputVariable;
    std::string filename;
    std::string ProcessorName;
    std::string OutputFileName;
};