//
//  tools.c
//  c_playground
//
//  Created by Constantine Shatalov on 9/30/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include "tools.h"

void randWord(char *word, int length) {
    for (int i = 0; i < length; i++) {
        word[i] = (char)(rand() % (97 - 26) + 26);
    }
}
