// Name:


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