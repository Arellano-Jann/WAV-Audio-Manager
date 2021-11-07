// Created by Andrew Kalb
// 11/4/2021

struct WaveHeader
{
    char riffHeader[4];
    int wavSize;
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
    //char data[dataBytes];
    // everything after is the actual data
};