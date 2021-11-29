// Created by Alec Redera
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Wav.h"
#include "Processor.h"

class UI {
    std::string lower(std::string str);
public:
    UI() = default;
    void StartMenu();
    std::string InputFileName();
    void ExitMenu();
    //void InputQuitMenu();
    void PrintMeta(Wav wav);
    std::string ProcessorMenu();
    std::string OutFileName();
};