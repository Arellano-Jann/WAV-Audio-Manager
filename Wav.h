// Created by Andrew Kalb
// 11/4/2021

#include <string>
#include <vector>

class Wav
{
public:
    Wav();
    // Returns false if the file is invalid
    bool SetFile(const std::string& filename);
    void AnalyzeFile();
private:
    std::string file;
    unsigned int sampleRate;
    std::vector<char> data;
};