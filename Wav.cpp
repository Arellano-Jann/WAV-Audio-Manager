// Created by Andrew Kalb
// 11/4/2021

#include "Wav.h"
#include <ios>
#include <iostream>
#include <fstream>

Wav::Wav()
    : file("")
    , sampleRate(0)
    , samples()
    , header()
{
}

bool Wav::SetFile(const std::string& filename)
{
    std::ifstream f;
    f.open(filename, std::ios::binary | std::ios::in);
    if(f)
    {
        if(filename.substr(filename.size() - 4) == "wav")
        {
            return true;
        }
        /*f.read((char*)&header, sizeof(header));
        f.close();
        if(header.riffHeader == "RIFF")
        {
            file = filename;
            return true;
        }*/
    }
    return false;
}

void Wav::AnalyzeFile()
{
    std::ifstream f(file, std::ios::binary | std::ios::in);
    if(f.is_open())
    {
        f.read((char*)&header, sizeof(header));
    }
}
