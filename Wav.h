<<<<<<< HEAD
// Name:

=======
// Created by Andrew Kalb
// 11/4/2021
>>>>>>> a9a42eedef958cc983c565f4ef40e3601d7d2162

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