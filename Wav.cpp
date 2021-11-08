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
        f.read((char*)&header, sizeof(header));
        rawData = new char[header.dataBytes];
        f.read(rawData, sizeof(header.dataBytes));
    }
    f.close();
}
