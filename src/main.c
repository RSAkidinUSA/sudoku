#include <stdio.h>
#include <stdbool.h>
#include "sudoku.h"
#include "format.h"


int main(int argc, char **argv) {
    Board *b;
    if (argc < 2) {
        printf("Usage: %s file_to_solve\n");
        return 1;
    }
    b = malloc(sizeof(*b));
    for (int i = 1; i < argc; i++) {
        int retval;
        retval = load_board(b, argv[i]);
        if (retval) {
            printf("Unable to load board from file %s\n");
            continue;
        }
    }
}
