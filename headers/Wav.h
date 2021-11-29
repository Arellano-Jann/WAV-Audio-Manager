// Created by Andrew Kalb
#pragma once
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
    std::string GetFileName() { return file; }
    std::string GetStereo();
    int GetSampleRate(){ return header.sampleRate; }
    int GetByteRate(){ return header.byteRate; }
    short GetBitsPerSample(){ return header.bitDepth; }
    short GetBlockAlign(){ return header.sampleAlignment; }
    std::vector<float>& GetSamples() { return samples; }

    // fails if filename not available
    bool CreateFile(std::string newFileName);
    
private:
    float Convert16BitToFloat(short data);
    float Convert8BitToFloat(unsigned char data);
    short ConvertFloatTo16Bit(float sample);
    unsigned char ConvertFloatTo8Bit(float sample);
    

    void FillFloatSamplesFromRawData();
    std::string file;
    char* rawData;
    std::vector<float> samples;
    WaveHeader header;
};