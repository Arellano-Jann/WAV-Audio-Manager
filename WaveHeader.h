// Created by Andrew Kalb
// 11/4/2021

struct WaveHeader
{
    char riffHeader[4];
    int wavSize; // 4 bit thing not all ints are 4 bit
    char waveHeader[4];

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