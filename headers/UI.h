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
public:
    // he talked about static functions and they looks cool so i'm gonna make all of these static functions
    UI() = default;
    static void StartMenu();
    void Input();
    void checkInput();
    static void ExitMenu();
    //void InputQuitMenu();
    static void PrintMeta(Wav wav);
    static std::string ProcessorMenu();
    static std::string OutFileName();
    std::string getInput() const{ return input; }
    void setInput(std::string i) { input = i;}
};