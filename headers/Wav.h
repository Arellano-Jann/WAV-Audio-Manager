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
    /**
     * @brief Get the File Name associated with this Wav Object
     * 
     * @return std::string name of file
     */
    std::string GetFileName() const { return file; }
    std::string GetStereo() const;
    /**
     * @brief Get the Sample Rate of the wav file associated with this object
     * 
     * @return int sample rate
     */
    int GetSampleRate() const { return header.sampleRate; }
    /**
     * @brief Get the Byte Rate of the wav file associated with this object
     * 
     * @return int byte rate
     */
    int GetByteRate() const { return header.byteRate; }
    /**
     * @brief Get the Bits Per Sample (bitdepth) of the wav data associated with this object
     * 
     * @return short bit depth
     */
    short GetBitsPerSample() const { return header.bitDepth; }
    /**
     * @brief Get the Block Align of the wav data associated with this object
     * 
     * @return short block alignment
     */
    short GetBlockAlign() const { return header.sampleAlignment; }
    /**
     * @brief Get the vector of samples converted from the raw wav data (this holds float values from -1.0f to 1.0f)
     * 
     * @return const std::vector<float>& samples
     */
    const std::vector<float>& GetSamples() const { return samples; }

    // fails if filename not available
    bool CreateFile(std::string newFileName);
    /**
     * @brief Sets the samples vector to be converted back into new wav audio data
     * 
     * @param sample std::vector<float> samples that have just been modified
     */
    void setSamples(std::vector<float> sample){ samples = sample; }
    
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