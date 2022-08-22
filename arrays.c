//
//  arrays.c
//  c_playground
//
//  Created by Constantine Shatalov on 9/21/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include "arrays.h"

void arrays1D() {
    /* Creating static arrays */
    // Size must be set at compile time (prior to C99)
    int animals[3];
    char cars[10][10] = {
        {'f', 'e', 'r', 'r', 'a', 'r', 'i', '\0'},
        {'t', 'e', 's', 'l', 'a', '\0'}
    };
    char cat[] = "John"; // shortcut to previous (includes nul terminator)
    char *dog = "Rex"; // pointer to string in stack
    puts(dog);
    
    /* Creating dynamic arrays */
    // Size can be set at runtime
    char *cheetah = (char *)malloc(5 * sizeof(char));
    strcpy(cheetah, "Alex"); // NOTE: cheetah = "Alex"; does a compl. different thing
    puts(cheetah);
    free(cheetah);

    /* Dynamic arrays from user input */
    int n;
    printf("How many elements?\n");
    scanf("%d", &n);
    int *dynamicArray = (int *)malloc(n * sizeof(int)); // allocates n ints of heap memory, returns adress of first
    for (int i = 0; i < n; i++) {
        printf("Enter element:\n");
        scanf("%d", dynamicArray + i); // write to each allocated address, or easier:
        // scanf("%d", &dynamicArray[i]);
        printf("Entered: %d\n", *(dynamicArray + i)); // or easier:
        // printf("\n%d", dynamicArray[i]);
    }
    free(dynamicArray);
    printf("\n");

    /* Reallocate when allocated too much memory */
    char *alphabet = (char *)malloc(10 * sizeof(char));
    for (int i = 0; i <= 5; i++) {
        * (alphabet + i) = i + 65; // or same:
        // alphabet[i] = i + 65;
        printf("%c @ %p\n", *(alphabet + i), alphabet + i);
    }
    alphabet = realloc(alphabet, 5 * sizeof(char)); // allocates new mem., returns ptr, free's old
    puts(alphabet);
    free(alphabet);
    printf("\n");
}

void arrays2D() {
    int rows;
    printf("Enter number of rows\n");
    scanf("%d", &rows);
    int cols;
    printf("Enter number of cols\n");
    scanf("%d", &cols);
    int **dynamic2DArray;

    // **A -> *B -> int
    //              int
    //              int
    //        *X -> iny
    //              int
    //              int

    dynamic2DArray = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        *(dynamic2DArray + i) = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            *((*(dynamic2DArray + i)) + j) = 0;
            printf("%d\t", *((*(dynamic2DArray + i)) + j));
        }
        printf("\n");
    }

    free(dynamic2DArray);
}

// VLA were added in C99
void variableLengthArrays() {
    int n;
    puts("Enter the size of an array:");
    scanf("%d", &n);
    char str[n]; // setting size during runtime
    randWord(str, n);
    puts(str);
}
