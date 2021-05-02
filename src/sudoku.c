#include "sudoku.h"
#include "format.h"

// Square Functions

// Resets a square
void reset_square(Square *s) {
    s->value = 0;
    for (int i = 0; i < 9; i++) {
        s->possible[i] = true;
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
            count += (s->possible[i]) ? 1 : 0;
        }
    }
    return count;
}

// Group Functions

bool is_valid(Group *g) {
    bool used[9] = {false, };
    for (int i = 0; i < GROUP_SIZE; i++) {
        int tmp = -1;
        switch(num_options(g->square[i])) {
        case 0:
            return false;
        case 1:
            tmp = g->square[i]->value - 1;
            if (used[tmp]) {
                return false;
            } else {
                used[tmp] = true;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            break;
        // This should never happen but just in case
        default:
            return false;
        }
    }
    return true;
}

// Print a group using the designated length
static void print_group(FILE *f, Group *g, int len) {
    fputc(BORDER_CHAR, f);
    for (int i = 0; i < 9; i++) {
        fputc(g->square[i]->value + '0', f);
        if ((i + 1) % len) {
            if ((i + 1) % 3) {
                fputc(SPACE_CHAR, f);
            } else {
                fputc(BORDER_CHAR, f);
            }
        } else {
            fputc(BORDER_CHAR, f);
            fputc('\n', f);
        }
    }
}

// Board Functions

// Initializes the board
void init_board(Board *b) {
    for (int i = 0; i < GROUP_SIZE; i++) {
        for (int j = 0; j < NUM_GROUPS; j++) {
            int l, m;
            // setup the rows
            l = i;
            m = j;
            b->row[i].square[j] = &(b->square[l * GROUP_SIZE + m]);
            // setup the columns
            l = j;
            m = i;
            b->col[i].square[j] = &(b->square[l * GROUP_SIZE + m]);
            // setup the boxes
            l = (i / 3) * 3 + (j / 3);
            m = (i % 3) * 3 + (j % 3);
            b->box[i].square[j] = &(b->square[l * GROUP_SIZE + m]);
        }
    }
}

// Resets the board
void reset_board(Board *b) {
    for (int i = 0; i < NUM_SQUARES; i++) {
        reset_square(&(b->square[i]));
    }
}

// Loads the board from a given file based on format in format.h
// returns: 1 if unable to open file, 2 if can't read
int load_board(Board *b, char *filename) {
    FILE *f = NULL;
    int retval = 0;
    // reset the board
    reset_board(b);
    // Open the file
    if (filename) {
        f = fopen(filename, "r");
    } else {
        f = stdin;
    }
    // Check for error doing so
    if (!f) {
        retval = 1;
    } else if (read_file(b, f)) {
        retval = 2;
    }
    if (f && f != stdin) {
        fclose(f);
    }
    
    return retval;
}

// TODO: make one generic print option which takes a filler char, an
// array of 9 characters to print, and a start/stop char
static void print_header_row(FILE *f) {
    for (int i = 0; i < 3; i++) {
        fputc(HEADER_CHAR, f);
        fputc(HEADER_BORDER_CHAR, f);
        for (int j = 0; j < 2; j++) {
            fputc(HEADER_BORDER_CHAR, f);
            fputc(HEADER_BORDER_CHAR, f);
        }
    }
    fputc(HEADER_CHAR, f);
    fputc('\n', f);
}

static void fprint_row(FILE *f, Board *b, int row) {
    print_group(f, &(b->row[row]), 9);
}

// Print out a row
void print_row(Board *b, int row) {
    print_group(stdout, &(b->row[row]), 9);
}

// Print out a column
void print_col(Board *b, int col) {
    print_group(stdout, &(b->col[col]), 1);
}

// Print out a box
void print_box(Board *b, int box) {
    print_group(stdout, &(b->box[box]), 3);
}

// Print the board to the given filename
// args: filename: string to print to, if NULL, print to stdout
// returns: 0 on success, 1 on failure

int print_board(Board *b, char *filename) {
    FILE *f = NULL;
    if (filename) {
        f = fopen(filename, "w");
        if (!f) {
            return 1;
        }
    } else {
        f = stdout;
    }
    for (int i = 0; i < 9; i++) {
        if (! (i % 3)) {
            print_header_row(f);
        }
        fprint_row(f, b, i);
    }
    print_header_row(f);
    if (f != stdout) {
        fclose(f);
    }
    return 0;
}
