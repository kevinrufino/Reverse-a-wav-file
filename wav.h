//
// Created by Kevin on 1/29/2020.
//
#include <stdlib.h>
#include <stdio.h>

#ifndef INC_343PRJ1_WAV_H
#define INC_343PRJ1_WAV_H

typedef struct wav_file{
    //table of the first 44 bytes
    char RIFF[4];
    int chunkSize;
    char WAVE[4];
    char fmt[4];
    int lengthFmt;
    short fmtType;
    short numChannels;
    int sampleRate;
    int byteRate;
    short blockAlgnmnt;
    short bitPerSample;
    char dataSection[4];
    int numBytesDataSection;
} wav_file;

wav_file* parse(const char* contents);

#endif //INC_343PRJ1_WAV_H
