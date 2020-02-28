/**
 * 
 * Created by Kevin Rufino on 1/29/2020.
 * CIS 343 Project 1
 * version: 1.0.0.FINALLY DONE
 *
 **/

#include "file.h"

/**
 * This function reads the file and mallocs memory for the pointer
 *
 * @param *filename: this takes name from argv[1]
 * @param **buffer: this takes the buffer that we will be mallocing
 *
 * @return siz: the size of file
 **/

size_t read_file (char* filename, char **buffer ) {
    //malloc for contents
    //fill malloc'ed memory with file contents
    //these dont need to know anything about wave stuff it just reads and writes to the disk
    
    //Pointer to a file type
    FILE *fptr;

    //opens file
    fptr = fopen (filename, "rb");

    fseek (fptr, 0L, SEEK_END);
    size_t sz = ftell(fptr);
    fseek (fptr, 0L, SEEK_SET);
    rewind(fptr);

    //mallocs space for the buffer file
    *buffer = malloc (sz);

    //this actually reads the file
    size_t siz = fread(*buffer, 1, sz, fptr);

    //close after opening
    fclose (fptr);

    return siz;
}

/**
 * This functions writes the new file that well be outputting
 *
 * @param *filename: this takes the name from argv[1]
 * @param *buffer: this points to the buffer well be writing to
 * @param size: this takes the size of the file so we don't have to figure it our
 *
 * @return: the size of the written file
 **/

size_t write_file ( char* filename, char *buffer, size_t size) {
    
    //Pointer to file
    FILE *fptr;

    //opens the file to be worked on
    fptr = fopen (filename,"w");

    //writes the new file of the size given
    size_t siz = fwrite(buffer, size, 1, fptr);

    //close after opening
    fclose (fptr);

    return siz;
}
