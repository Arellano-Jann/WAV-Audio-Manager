// Created by Alec Redera
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Wav.h"
#include "Processor.h"

class UI {
    std::string lower(std::string str);
    std::string input = "q"; 
    static void output(std::string str);
    void setInput(std::string i) { input = i;}
    float parameterOne;
    float parameterTwo;

public:
    // he talked about static functions and they looks cool so i'm gonna make all of these static functions
    UI() = default;
    static void StartMenu();
    void Input();
    bool checkInput();
    static void ExitMenu();

    static void PrintMetaData(Wav wav);

    void ProcessorMenu();
    int selectProcessor();
    void checkProcessor(std::string i);
    void callProcessor(); // needs implement
    void askProcessorQuestions(int i); //
    static std::string OutputFileName();

    std::string getInput() const{ return input; }
};