//
//  passing.c
//  c_playground
//
//  Created by Constantine Shatalov on 10/7/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include "passing.h"

void passing() {
    int age = 22;
    passByValue(age);
    printf("Passed by value: %d\n", age); // age doesn't change
    passByPointer(&age);
    printf("Passed by value: %d\n", age); // age changes
}

void passByValue(int number) {
    // copies number
    number += 1;
}

void passByPointer(int *number) {
    // works with the actual number
    *number += 1;
}
