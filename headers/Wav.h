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
    std::string GetFileName() const { return file; }
    std::string GetStereo() const;
    int GetSampleRate() const { return header.sampleRate; }
    int GetByteRate() const { return header.byteRate; }
    short GetBitsPerSample() const { return header.bitDepth; }
    short GetBlockAlign() const { return header.sampleAlignment; }
    std::vector<float>& GetSamples() { return samples; } // need this const somehow

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