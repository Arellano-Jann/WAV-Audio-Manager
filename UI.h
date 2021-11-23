// Created by Alec Redera
#pragma once
#include <iostream>
#include <string>
#include "Wav.h"
#include "Processor.h"

class UI {
public:
    UI() = default;
    void StartMenu();
    std::string InputFileName();
    void ExitMenu();
    //void InputQuitMenu();
    void PrintMeta(Wav wav);
    std::string ProcessorMenu();
    void RunProcessor();
};