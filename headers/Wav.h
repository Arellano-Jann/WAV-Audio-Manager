// Created by Andrew Kalb
#pragma once
#include "WaveHeader.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief A Wav class. \n
 * This class has a public constructor and destructor. \n
 * It also has four private member variables which is the sound data, file name and WaveHeader. \n
 * The class has multiple methods for handling wav files and converting floating points to 8/16 bits and vice versa. \n
 * 
 */
class Wav
{
    float Convert16BitToFloat(short data);
    float Convert8BitToFloat(unsigned char data);
    short ConvertFloatTo16Bit(float sample);
    unsigned char ConvertFloatTo8Bit(float sample);
    

    void FillFloatSamplesFromRawData();
    std::string file;
    char* rawData;
    std::vector<float> samples;
    WaveHeader header;
public:
    Wav();
    ~Wav();
    
    // Returns false if the file is invalid
    bool SetFile(const std::string& filename);
    void AnalyzeFile();
    /**
     * @brief Get the File Name associated with this Wav Object. \n
     * 
     * @return std::string file
     */
    std::string GetFileName() const { return file; }
    std::string GetStereo() const;
    /**
     * @brief Get the Sample Rate of the wav file associated with this object. \n
     * 
     * @return int sampleRate
     */
    int GetSampleRate() const { return header.sampleRate; }
    /**
     * @brief Get the Byte Rate of the wav file associated with this object. \n
     * 
     * @return int byteRate
     */
    int GetByteRate() const { return header.byteRate; }
    /**
     * @brief Get the Bits Per Sample (bitdepth) of the wav data associated with this object. \n
     * 
     * @return short bitDepth
     */
    short GetBitsPerSample() const { return header.bitDepth; }
    /**
     * @brief Get the Block Align of the wav data associated with this object. \n
     * 
     * @return short sampleAlignment
     */
    short GetBlockAlign() const { return header.sampleAlignment; }
    /**
     * @brief Get the vector of samples converted from the raw wav data (this holds float values from -1.0f to 1.0f). \n
     * 
     * @return const std::vector<float>& samples
     */
    const std::vector<float>& GetSamples() const { return samples; }

    // fails if filename not available
    bool CreateFile(std::string newFileName);
    /**
     * @brief Sets the samples vector to be converted back into new wav audio data. \n
     * 
     * @param sample std::vector<float> (Samples that have just been modified.) \n
     */
    void setSamples(std::vector<float> sample){ samples = sample; }
    
};