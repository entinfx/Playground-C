//
//  fileio.c
//  c_playground
//
//  Created by Constantine Shatalov on 9/30/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include "fileio.h"

void fileBasics() {
    FILE *fPointer; // points to memory containing the file

    // A sequence of bytes going into or out of the program
    // is called a [input or output] stream.
    // stdin - keyboard input
    // stdout - monitor output

    /* Write file */
    fPointer = fopen("/Users/konstantinshatalov/Developer/c_cpp_playgrounds/c_playground/c_playground/fileTest.txt", "w");
    fprintf(fPointer, "Ground control to Major Tom.\nPut your helmet on!");
    fclose(fPointer);

    /* Edit file */
    fPointer = fopen("/Users/konstantinshatalov/Developer/c_cpp_playgrounds/c_playground/c_playground/fileTest.txt", "r+");
    fseek(fPointer, 29, SEEK_SET); // move fPointer 29 spaces from beginning (SEEK_SET)
    // fprintf(fPointer, "Take your protein pills,\nand put your helmets on!");
    fputs("Take your protein pills,\nand put your helmet on!", fPointer);
    fclose(fPointer);

    /* Append to file */
    fPointer = fopen("/Users/konstantinshatalov/Developer/c_cpp_playgrounds/c_playground/c_playground/fileTest.txt", "a");
    fprintf(fPointer, "\n\t\t\t- David Bowie.");
    fclose(fPointer);

    /* Read file */
    fPointer = fopen("/Users/konstantinshatalov/Developer/c_cpp_playgrounds/c_playground/c_playground/fileTest.txt", "r");
    char *line = (char *)malloc(150 * sizeof(char)); // ???: Put it inside the loop?
    while (!feof(fPointer)) {
        fgets(line, 150, fPointer);
        printf("%s", line);
    }
    free(line);
    printf("\n");
    fclose(fPointer);
}
