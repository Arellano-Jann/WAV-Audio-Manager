// Name:


#include "Wav.h"
#include <ios>
#include <iostream>
#include <fstream>

Wav::Wav()
    : file("")
    , sampleRate(0)
    , data()
{
}

bool Wav::SetFile(const std::string& filename)
{
    std::ifstream f;
    f.open(filename, std::ios::binary | std::ios::in);
    if(f)
    {
        f.close();
        file = filename;
        return true;
    }
    else
    {
        return false;
    }
}

void Wav::AnalyzeFile()
{
    
}
