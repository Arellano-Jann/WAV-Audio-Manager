// Created by Andrew Kalb

#include "Wav.h"
#include <ios>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>

Wav::Wav()
    : file("")
    , rawData(NULL)
    , samples()
    , header()
{
}
// add Wav constructor with filename param


bool Wav::SetFile(const std::string& filename)
{
    std::ifstream f;
    f.open(filename, std::ios::binary | std::ios::in);
    if(f)
    {
        // change to check to RIFF
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
    std::ifstream f;
    f.open(file, std::ios::binary | std::ios::in);
    if(f)
    {
        f.read((char*) &header, sizeof(header));
        rawData = new char[header.dataBytes];
        f.read(rawData, header.dataBytes);
        FillFloatSamplesFromRawData();
    }
    f.close();
}

void Wav::FillFloatSamplesFromRawData()
{
    //std::cout << "bit depth : " << header.bitDepth << std::endl;
    unsigned int numBytesPerSample = header.bitDepth / 8;
    //std::cout << "bytes per floating point value : " << header.bitDepth / 8 << std::endl;
    //std::cout << "max size of a section of bytes this size : " << pow(2, header.bitDepth) / 2;
    unsigned int maxPossibleValue = pow(2, header.bitDepth) / 2;
    if(numBytesPerSample == 1)
    {
        for(size_t i = 0; i < header.dataBytes; i++)
        {    
            float val = -1.0f + (2.0f / 255.0f) * static_cast<float>(*(reinterpret_cast<unsigned char*>(&rawData[i])));
            samples.push_back(val);
        }
    }
    else if (numBytesPerSample == 2)
    {
        assert(sizeof(short) == 2);
        for(size_t i = 0; i < header.dataBytes; i+=2)
        {
            short sampleValue = 0;
            *(reinterpret_cast<char*>(&sampleValue)) = rawData[i];
            *(reinterpret_cast<char*>(&sampleValue) + 1) = rawData[i + 1];            
            float val = 0.0f + (2.0f / 32768.0f) * static_cast<float>(sampleValue);
            samples.push_back(val);
        }
    }
    else
    {
        assert(false);
    }

    // testing code
    for(std::vector<float>::iterator it = samples.begin(); it != samples.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

std::string Wav::GetStereo()
{
    std::string numChannels = "Mono";
    if(header.numChannels == 2)
    {
        numChannels = "Stereo";
    }
    return numChannels; 
}

Wav::~Wav()
{
    delete [] rawData;
}

// Make getter and setter for float vector samples thing  DONE (just need getter since reference to a vector)
// Fix fillfloat function 
// Write a write function to convert the data back 
// and store into a new file




