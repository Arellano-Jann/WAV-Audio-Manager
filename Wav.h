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
    ~Wav();
    // Returns false if the file is invalid
    bool SetFile(const std::string& filename);
    void AnalyzeFile();
    bool IsStereo() { return header.numChannels - 1; }
    
private:
    void FillFloatSamplesFromRawData();
    std::string file;
    unsigned int sampleRate;
    char* rawData;
    float* samples;
    WaveHeader header;
};