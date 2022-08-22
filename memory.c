//
//  memory.c
//  c_playground
//
//  Created by Constantine Shatalov on 9/21/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include "memory.h"

// MEMORY:
// * Stack (fixed size, holds local/static/named variables)
// * Heap (dynamic, unnamed allocated blocks for dynamic things)
// * Global (holds global variables)
//  
// PROGRAM:
// Function 1: calls func. 2,                   declares 2 variables
// Function 2: calls func. 3, has 2 parameters, declares 2 variables
// Function 3:                has 2 parameters, declares 2 variables
//
// STACK:
// F3 Var 2 • • • • • • • • | F3  S  F
// F3 Var 1 • • • • • • • • | F3  T  R
// F2 Return address (PC) • | F3  A  A
// F3 Parameter 2 • • • • • | F3  C  M
// F3 Parameter 1 • • • • • | F3  K  E
// -
// F2 Var 2 • • • • • • • • | F2  S  F
// F2 Var 1 • • • • • • • • | F2  T  R
// F1 Return address (PC) • | F2  A  A
// F2 Parameter 2 • • • • • | F2  C  M
// F2 Parameter 1 • • • • • | F2  K  E
// -
// F1 Var 2
// F1 Var 1

void pointers() {
    int a = 10; // lives in stack
    printf("%d @ %p \n", a, (void *)&a); // value @ address in stack
    int *b = &a; // pointer b points to a (both in stack)
    b = (int *)malloc(sizeof(int)); // allocate heap memory and return address to b pointer
    *b = 5; // assign value to allocated memory @ adddress b, a remains untouched
    printf("%d @ %p\n", *b, b);
    free(b);
    
    int *d;
    int *e = (int *)malloc(sizeof(int));
    d = e; // d and e point to the same heap memory
    *e = 15;
    printf("%d @ %p\n", *e, e); // 15 @ some address
    free(e); // or d
    *d = 100; // !!!: Accessing free'd memory may result into segmentation fault / access violation
    printf("%d @ %p (free'd)\n", *e, e);
}
