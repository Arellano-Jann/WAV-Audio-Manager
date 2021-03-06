// Created by Andrew Kalb

#include "../headers/Wav.h"
#include <ios>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>

/**
 * @brief Constructs a new Wav::Wav object, and initializes member variables. \n
 * 
 */
Wav::Wav()
    : file("")
    , rawData(NULL)
    , samples()
    , header()
{
}

/**
 * @brief Attempts to set file member variable and tests if the file is valid to be opened. \n
 * 
 * @param filename (The name of the file to be opened.) \n
 * @return true (If the file opened successfully.) \n
 * @return false (If the file couldn't be opened or is an invalid type.) \n
 */
bool Wav::SetFile(const std::string& filename)
{
    std::ifstream f;
    f.open(filename, std::ios::binary | std::ios::in);
    if(f)
    {
        // check RIFF? 
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

/**
 * @brief Opens the file, and reads the WaveHeader and data information in. \n
 * 
 */
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

/**
 * @brief Returns what type of numbered channel audio data the wav file is. \n
 * 
 * @return std::string (Mono or Stereo, or Undefined if neither.) \n
 */
std::string Wav::GetStereo() const
{
    std::string numChannels = "Undefined";
    if(header.numChannels == 1)
    {
        numChannels = "Mono";
    }
    else if(header.numChannels == 2)
    {
        numChannels = "Stereo";
    }
    return numChannels; 
}

/**
 * @brief Converts raw signed short data to a float sample. \n
 * 
 * @param data (Raw signed short data.) \n
 * @return float (Sample converted value.) \n
 */
float Wav::Convert16BitToFloat(short data)
{
    // 32768 is the negative maximum value of a 16 bit binary number (signed short)       
    float val = 0.0f + (1.0f / 32768.0f) * static_cast<float>(data);
    return val;
}

/**
 * @brief Converts raw unsigned char data to a float sample. \n
 * 
 * @param data (Raw unsigned char data.) \n
 * @return float (Sample converted value.) \n
 */
float Wav::Convert8BitToFloat(unsigned char data)
{
    // 255 is the maximum value of a 8 bit number (unsigned char)
    float val = -1.0f + (2.0f / 255.0f) * static_cast<float>(*(reinterpret_cast<unsigned char*>(&data)));
    return val;
}

/**
 * @brief Converts a float sample back to raw short data. \n
 * 
 * @param sample (Float sample value.) \n
 * @return short (Converted back raw short data.) \n
 */
short Wav::ConvertFloatTo16Bit(float sample)
{
    short data = sample / (1.0f/32768.0f);
    return data;
}

/**
 * @brief Converts a float sample back to unsigned char data. \n
 * 
 * @param sample (Float sample value.) \n
 * @return unsigned char (Converted back raw unsigned char data.) \n
 */
unsigned char Wav::ConvertFloatTo8Bit(float sample)
{
    unsigned char data = (sample + 1.0f)/(2.0f / 255.0f);
    return data;
}

/**
 * @brief Attempts to create a file with the data stored in this wav object. \n
 * 
 * @param newFileName (The new file name to store the data in.) \n
 * @return true (If the file could successfully be created.) \n
 * @return false (If the file could not be created.) \n
 */
bool Wav::CreateFile(std::string newFileName)
{
    unsigned int numBytesPerSample = header.bitDepth / 8;
    bool success = true;
    
    std::ofstream file(newFileName, std::ios::binary);
    if(file)
    {
        file.write((char*) &header, sizeof(header));
        if(header.numChannels == 1 || header.numChannels == 2)
        {
            // 8 bit mono
            if(numBytesPerSample == 1)
            {
                for(size_t i = 0; i < header.dataBytes; i++)
                {    
                    unsigned char data = ConvertFloatTo8Bit(samples[i]);
                    rawData[i] = data;
                }
            }
            else if(numBytesPerSample == 2)
            {
                // 16 bit stereo and mono
                if(header.numChannels == 1 || header.numChannels == 2)
                {
                    int count = 0;
                    for(size_t i = 0; i < header.dataBytes; i+= 2)
                    {
                        short data = ConvertFloatTo16Bit(samples[count]);
                        unsigned char lsb = *(reinterpret_cast<unsigned char*>(&data));
                        unsigned char msb = *(reinterpret_cast<unsigned char*>(&data) + 1);
                        rawData[i] = lsb;
                        rawData[i + 1] = msb;
                        count++;
                    }
                }
            }
            else
            {
                assert(false);
            }
        }
        else
        {
            assert(false);
        }
        file.write(rawData, header.dataBytes);
    }
    else
    {
        success = false;
    }
    file.close();
    return success;
}

/**
 * @brief Fills the float samples member variable vector from the raw data read from the wav file. \n
 * 
 */
void Wav::FillFloatSamplesFromRawData()
{
    unsigned int numBytesPerSample = header.bitDepth / 8;
    if(header.numChannels == 1 || header.numChannels == 2)
    {
        // 8 bit
        if(numBytesPerSample == 1)
        {
            for(size_t i = 0; i < header.dataBytes; i++)
            {    
                float val = Convert8BitToFloat(*(reinterpret_cast<unsigned char*>(&rawData[i])));
                samples.push_back(val);
            }
        }
        // 16 bit
        else if (numBytesPerSample == 2)
        {
            for(size_t i = 0; i < header.dataBytes; i+=2)
            {
                short sampleValue = 0;
                *(reinterpret_cast<char*>(&sampleValue)) = rawData[i];
                *(reinterpret_cast<char*>(&sampleValue) + 1) = rawData[i + 1]; // ah yes, direct memory manipulation
                float val = Convert16BitToFloat(sampleValue);
                samples.push_back(val);
            }
        }
        else
        {
            assert(false);
        }
    }
    else
    {
        assert(false);
    }
}

/**
 * @brief Destroys the Wav::Wav object. \n
 * 
 */
Wav::~Wav()
{
    delete [] rawData;
}




