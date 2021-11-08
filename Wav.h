// Created by Andrew Kalb
// 11/4/2021

#include "WaveHeader.h"
#include <iostream>
#include <string>
#include <vector>

class Wav
{
public:
    Wav();
    // Returns false if the file is invalid
    bool SetFile(const std::string& filename);
    void AnalyzeFile();
private:
    std::string file;
    unsigned int sampleRate;
    char* rawData;
    WaveHeader header;
};