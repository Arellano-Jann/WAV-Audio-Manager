// Created by Alec Redera
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Wav.h"
#include "Processor.h"

class UI {
    static std::string lower(std::string str);
    static void output(std::string str);

public:
    // he talked about static functions and they looks cool so i'm gonna make all of these static functions
    UI() = default;
    static void StartMenu();
    static std::string Input();
    static bool checkInput(std::string input);
    static void ExitMenu();

    static void PrintMetaData(Wav wav);

    static void ProcessorMenu();
    static int selectProcessor();
    static void checkProcessor(std::string i); // private
    static void askProcessorQuestions(int i);
    static std::string OutputFileName();
};