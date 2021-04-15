#include <stdio.h>
#include "format.h"

// returns 0 if no errors, else 1
int read_file(Board *b, int f) {
    char c;
    // TODO: psuedocode

    // read the first char of each line to determine if it's a header or data

    // header lines
    for (int i = 0; i < HEADER_LEN; i++) {
        c = readchar(f);
        if (c != HEADER[i]) {
            printf("Warning: Header format mismatch");
        }
    }

    // data lines should alternate a number between 0 and 9 and a non-number
    // if more than 9 values, or more than 9 lines, there's an issue
}

