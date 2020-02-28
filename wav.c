/**
 * 
 * @Author: Kevin Rufino
 * @Version: 1.0.0.FINALLY DONE
 * CIS 343 Project 1
 *
 **/

#include "wav.h"

/**
 * This function parses our header so that we can take data into it
 *
 * @param *contents: this is the buffer that will be parsed
 *
 * @return the *wav_file struct with specific data accessible through parsing
 **/

wav_file* parse (const char* contents){

    wav_file *parse =  malloc(sizeof(wav_file));

    parse->RIFF[0] = contents[0];
    parse->RIFF[1] = contents[1];
    parse->RIFF[2] = contents[2];
    parse->RIFF[3] = contents[3];
    parse->chunkSize = contents[4];
    parse->WAVE[0] = contents[8];
    parse->WAVE[1] = contents[9];
    parse->WAVE[2] = contents[10];
    parse->WAVE[3] = contents[11];
    parse->fmt[0] = contents[12];
    parse->fmt[1] = contents[13];
    parse->fmt[2] = contents[14];
    parse->fmt[3] = contents[15];
    parse->lengthFmt = contents[16];
    parse->fmtType = contents[20];
    parse->numChannels = contents[22];
    parse->sampleRate = contents[24];
    parse->byteRate = contents[28];
    parse->blockAlgnmnt = contents[32];
    parse->bitPerSample = contents[34];
    parse->dataSection[0] = contents[36];
    parse->dataSection[1] = contents[37];
    parse->dataSection[2] = contents[38];
    parse->dataSection[3] = contents[39];
    parse->numBytesDataSection = contents[40];

    return parse;
}
