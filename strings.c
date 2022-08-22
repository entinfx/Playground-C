//
//  strings.c
//  c_playground
//
//  Created by Constantine Shatalov on 9/22/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include "strings.h"

void charFunctions() {
    /* isalpha */
    char a = 'A';
    int b = 123; // Not inside ASCII character range: 65(A)-...-122(z)
    printf("%c is %salpha (ASCII %d).\n", a, isalpha(a) ? "" : "not an ", (int)a); // a is alpha cause in range
    printf("%c is %salpha (ASCII %d).\n", b, isalpha(b) ? "" : "not an ", b); // b isn't cause 123 is not in ASCII range

    /* isupper */
    printf("%c is %s\n", a, isupper(a) ? "uppercase" : "lowercase");

    /* strcat */
    // It's important to avoid buffer overflow when using strcat.
    // The first strcat parameter should be a pointer that points
    // to memory allocated FOR BOTH STRINGS, otherwise the second
    // string won't fit into the first one, resulting in buffer
    // overflow.
    char *str1 = (char *)malloc(15 * sizeof(char)); // allocate memory for 15 chars
    // Note: the following doesn't work because it makes str1 pointer to point to a new string literal
    // in stack. It does not put the string literal at pointer's memory address as it might intuitively
    // seem.
    // *str1 = "I like";
    strcpy(str1, "I like"); // put a string in this memory, still enough memory for the second one
    char *str2 = " you."; // ! points to literal in stack
    strcat(str1, str2); // concat str2 into str1, no buffer overflow
    // Realloc new memory for str1, free unused memory
    str1 = realloc(str1, strlen(str1) * sizeof(char)); // strlen counts until meets nul terminator
    printf("%s\n", str1);
    free(str1);

    /* gets/puts/ */
    puts("Enter something:");
    char *userInput = (char *)malloc(128 * sizeof(char));
    gets(userInput); // Will crash if > 128 entered
    puts(userInput);
    free(userInput);

    /* fgets */
    puts("Enter something (enter 'quit' or send SIGINT to quit)");
    char *userInputSafe = (char *)malloc(12 * sizeof(char));
    // fgets will allow 11 characters + '\r', stdin - standard console input   
    while (fgets(userInputSafe, 12, stdin)) {
        if (!strncmp(userInputSafe, "quit", 4)) {
            break;
        }
        puts(userInputSafe);
        // To make fgets return 0 or false press ctrl+c or hit pause in Xcode
        // and type to LLVM: process signal SIGINT.
        // This will send SIGINT to the application usually
        // causing termination.
        // Signals are asynchronous notifications to a process.
        // They are mediated by the kernel (via system calls) and handled by the processes.
        // Other signals include SIGKILL, SIGTERM, etc.
        // Interrupts in contrast to signals are mediated by the processor and handled
        // by a kernel.
    }
    free(userInputSafe);
}
