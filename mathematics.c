//
//  mathematics.c
//  c_playground
//
//  Created by Constantine Shatalov on 9/26/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include "mathematics.h"

void rounding() {
    double a = 5.95;
    double b = 2.2;
    double c = 3.467;

    printf("Original: %.2f \t Floored: %.f\n", a, floor(a)); // 5
    printf("Original: %.2f \t Ceiled: %.f\n", a, ceil(a)); // 6
    printf("Original: %.1f \t Floored: %.f\n", b, floor(b)); // 2
    printf("Original: %.1f \t Ceiled: %.f\n", b, ceil(b)); // 3
    printf("Original: %.3f \t Floored: %.f\n", c, floor(c)); // 3
    printf("Original: %.3f \t Ceiled: %.f\n", c, ceil(c)); // 4
}

void absoluteValues() {
    int a = 1024;
    int b = 2000;
    printf("a = %d, b = %d, a - b = %d, (abs: %d)\n", a, b, a - b, abs(a - b));
}

void randomNumbers() {
    /* rand() */
    // Formula: rand() % (maxNumber + 1 - minNumber) + minNumber
    // Example 18 to 65, ruby analogy: (0...47).each do |n|; n += 18; # n is each result

    /* 0-4 */
    for(int i = 0; i < 10; i++) {
        int a = rand() % 5;
        printf("%d%s", a, i < 9 ? ", " : "");
    }
    printf("\n");

    /* 3-8 */
    for(int i = 0; i < 10; i++) {
        int a = rand() % (9 - 3) + 3;
        printf("%d%s", a, i < 9 ? ", " : "");
    }
    printf("\n");
}
