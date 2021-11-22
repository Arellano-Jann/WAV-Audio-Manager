// Created by Alec Redera
#pragma once
#include <iostream>
#include <string>
#include "Wav.h"
#include "Processor.h"

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