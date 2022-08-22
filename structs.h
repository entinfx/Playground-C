#ifndef structs_h
#define structs_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

typedef struct Person {
    char *name;
    int age;
} Person;

void structs(void);
// extern means all .o files that include this .h file will
// link to point to the same function
extern void personDisplay(Person *person);
extern void personInit(Person *person, char *name, int age);
extern Person *randPersonArray(int amount);

#endif
