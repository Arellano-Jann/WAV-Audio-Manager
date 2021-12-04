// Created by Alec Redera
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Wav.h"
#include "Processor.h"

class UI {
    void output(std::string str);

public:
    
    UI() = default;
    void StartMenu();
    std::string Input();
    bool checkInput(std::string input);
    void InvalidFileName();
    void ExitMenu();

    void PrintMetaData(const Wav& wav);

    void ProcessorMenu();
    int selectProcessor();
    bool checkProcessor(std::string i); // private
    void askProcessorQuestions(int i);
    std::string OutputFileName();
};