#include <string>
#include <vector>

class Wav
{
public:
    Wav(std::string filename);
private:
    std::string file;
    unsigned int sampleRate;
    std::vector<char> data;
};