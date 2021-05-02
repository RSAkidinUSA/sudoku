#include <stdlib.h>
#include "sudoku.h"
#include "format.h"
#include "ui.h"

int main(int argc, char **argv) {
    Board *b;
    if (argc < 2) {
        printf("Usage: %s file_to_solve\n", argv[0]);
        return 1;
    }
    b = malloc(sizeof(*b));
    init_board(b);
    for (int i = 1; i < argc; i++) {
        int retval;
        retval = load_board(b, argv[i]);
        if (retval) {
            fprintf(stderr, "Error: Unable to load board from file %s\n",
                    argv[i]);
            continue;
        }
        if (menu(b, argv[i])) {
            break;
        }
    }
    free(b);
}
