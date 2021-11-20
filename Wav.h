// Created by Andrew Kalb

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
    std::string GetStereo();
    int GetSampleRate();
    int GetByteRate();
    short GetBitsPerSample();
    short GetBlockAlign();
    
private:
    void FillFloatSamplesFromRawData();
    std::string file;
    char* rawData;
    float* samples;
    WaveHeader header;
};