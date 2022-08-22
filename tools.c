#include "tools.h"

void randWord(char *word, int length) {
    for (int i = 0; i < length; i++) {
        word[i] = (char)(rand() % (97 - 26) + 26);
    }
}
