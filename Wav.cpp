// Created by Andrew Kalb
// 11/4/2021

#include "Wav.h"
#include <ios>
#include <iostream>
#include <fstream>

Wav::Wav()
    : file("")
    , sampleRate(0)
    , rawData(NULL)
    , samples(NULL)
    , header()
{
}

bool Wav::SetFile(const std::string& filename)
{
    std::ifstream f;
    f.open(filename, std::ios::binary | std::ios::in);
    if(f)
    {
        if(filename.substr(filename.size() - 4) == ".wav")
        {
            file = filename;
            f.close();
            return true;
        }
    }
    f.close();
    return false;
}

void Wav::AnalyzeFile()
{
    std::cout << "analyzing file";
    std::ifstream f;
    f.open(file, std::ios::binary | std::ios::in);
    if(f)
    {
        f.read((char*) &header, sizeof(header));
        rawData = new char[header.dataBytes];
        samples = new float[header.dataBytes];
        f.read(rawData, header.dataBytes);
        FillFloatSamplesFromRawData();
    }
    f.close();
}

void Wav::FillFloatSamplesFromRawData()
{
    header.bitDepth;
    for(size_t i = 0; i < header.dataBytes; i++)
    {
        float val = 1.0f * rawData[i] / sizeof(char);
        samples[i] = val;
        std::cout << samples[i] << std::endl;
    }
}



Wav::~Wav()
{
    delete [] rawData;
    delete [] samples;
}