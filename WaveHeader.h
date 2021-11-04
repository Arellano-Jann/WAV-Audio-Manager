<<<<<<< HEAD
// Name:

=======
// Created by Andrew Kalb
// 11/4/2021
>>>>>>> a9a42eedef958cc983c565f4ef40e3601d7d2162

struct WaveHeader
{
    char riffHeader[4];
    int wavSize;
    char waveHeader;

    char fmtHeader[4];
    int fmtChunkSize;
    short audioFmt;
    short numChannels;
    int sampleRate;
    int byteRate;
    short sampleAlignment;
    short bitDepth;

    char dataHeader[4];
    int dataBytes;
    // everything after is the actual data
};