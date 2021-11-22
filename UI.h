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
    void Meta(std::string filename);
    void Processor();
    void RunProcessor();

private:
    std::string InputVariable;
    std::string filename;
    std::string ProcessorName;
    std::string OutputFileName;
    Wav w;
    //Processor p;
};