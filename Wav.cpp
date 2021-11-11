// Created by Andrew Kalb

#include "Wav.h"
#include <ios>
#include <iostream>
#include <fstream>
#include <cmath>

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
        samples = new float[header.dataBytes];
        f.read(rawData, header.dataBytes);
        FillFloatSamplesFromRawData();
    }
    f.close();
}

void Wav::FillFloatSamplesFromRawData()
{
    std::cout << "bit depth : " << header.bitDepth << std::endl;
    std::cout << "bytes per floating point value : " << header.bitDepth / 8 << std::endl;
    std::cout << "max size of a section of bytes this size : " << pow(2, header.bitDepth) / 2;
    
    for(size_t i = 0; i < header.dataBytes; i+=(header.bitDepth / 8))
    {
        float val = 1.0f * rawData[i] / (pow(2, header.bitDepth) / 2);
        samples[i] = val;
        std::cout << samples[i] << std::endl;
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

int Wav::GetSampleRate(){ return header.sampleRate; }
int Wav::GetByteRate(){ return header.byteRate; }
short Wav::GetBitsPerSample(){ return header.bitDepth; }
short Wav::GetBlockAlign(){ return header.sampleAlignment; }



Wav::~Wav()
{
    delete [] rawData;
    delete [] samples;
}