//
// Created by Kevin on 1/29/2020.
//
#include <stdlib.h>
#include <stdio.h>

#ifndef INC_343PRJ1_FILE_H
#define INC_343PRJ1_FILE_H
//malloc here

size_t read_file(char* filename, char **buffer );

size_t write_file( char* filename, char *buffer, size_t size);

#endif //INC_343PRJ1_FILE_H
