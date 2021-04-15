#include "sudoku.h"
#include "format.h"

// Square Functions

// Resets a square
void reset_square(Square *s) {
    s->value = 0;
    for (int i = 0; i < 9; i++) {
        s->possible = True;
    }
}

// Checks if a square is set
bool is_set(Square *s) {
    return (bool) (s->value);
}

// Checks how many possible values remain
int num_options(Square *s) {
    int count = 0;
    if (s->value) {
        count = 1;
    } else {
        for (int i = 0; i < GROUP_SIZE; i++) {
            count += (s->possible) ? 1 : 0;
        }
    }
    return count;
}

// Group Functions

bool is_valid(Group *g) {
    bool vals
    for (int i = 0; i < GROUP_SIZE; i++) {
    
    }
}

// Board Functions

// Resets the board
void reset_board(Board *b) {
    for (int i = 0; i < NUM_SQUARES; i++) {
        reset_square(b->square[i]);
    }
}

// Loads the board from a given file based on format in format.h

int load_board(Board *b, char *filename) {
    // Open the file
    f = open(filename, "r")
    // TODO: check for error doing so

    // reset the board
    reset_board(b);
    // read the file
    if (read_file(b, f)) {
        return 1;
    }
    // Go through and set all of the
}

// Print the board to the given filename
// args: filename: string to print to, if NULL, print to stdout
// returns: 0 on success, 1 on failure

int print_board(Board *b, char *filename) {
    int f;
    if (filename) {

    } else {
        f = stdout;
    }
    return 0;
}
