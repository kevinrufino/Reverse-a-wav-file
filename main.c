/** 
 * Author: Kevin Rufino
 * Version: 1.0.0.FINALLY DONE
 * */

#include "file.h"
#include "wav.h"
#include <string.h>

/**
 * This main function calls everything from our other files in conjuction
 *
 * @param argc: this is the number of argument
 * @param *argv[]: this holds the buffer
 *
 * @return 0
 * */

int main(int argc, char **argv) {

    //These are the arrays that will be modified
    char* buffer;
    char* reverse_buffer;

    //this gets the size of the buffer and mallocs space for it
    size_t size =  read_file(argv[1], &buffer);
 
    //Makes space for the reverse_bufffer
    reverse_buffer = malloc(size);

     //Parses the information from to *wav
     wav_file *wav = parse(buffer);

     printf("File: %s \n", argv[1]);
     printf("========================\n");
     printf("Filesize is %zu. Read %i bytes.\n", size, wav->chunkSize);
     printf("Format is \"%s\" with a format data length of %d.\n", wav->fmt, wav->lengthFmt);
     printf("Format type is %hd.\n", wav->fmtType);
     printf("This has %d channel(s) with a sample rate of %i.\n", wav->numChannels, wav->sampleRate);
     printf("Byte rate: %d\n", wav->byteRate);
     printf("Block alignment: %i\n", wav->blockAlgnmnt);
     printf("Bits per sample: %d\n", wav->bitPerSample);
     printf("Data is %s, and data size is %d bytes.", wav->dataSection, wav->numBytesDataSection);

     //Copy over the header to reverse_buffer
     memcpy(reverse_buffer, buffer, 44);

     //This checks if the sample size is correct
     int sample_size = (wav->bitPerSample / 8);
     printf("Sample size is %d.\n", sample_size);

     //loop reversing the contents after the header of buffer
     for (int i = 44; i < size - sample_size; i += sample_size){
          for(int j=0; j<sample_size; ++j){
		reverse_buffer[i+j] = buffer[ (size - 1) - i*sample_size + j ];
	  }
     }
    
     //This makes the revese_buffer a file that gets outputed
     write_file(argv[2], reverse_buffer, size);
    
     //releases malloced memory
     free(buffer);
     free(reverse_buffer);
     return 0;
}
