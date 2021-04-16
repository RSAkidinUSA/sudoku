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
    bool vals;
    for (int i = 0; i < GROUP_SIZE; i++) {
    
    }
}

// Print a group using the designated length
static void print_group(int f, Group *g, int len) {
    fputc(f, BORDER_CHAR);
    for (int i = 0; i < 9; i++) {
        fputc(f, g->square.value);
        if ((i + 1) % len) {
            fputc(f, SPACE_CHAR);
        } else {
            fputc(f, BORDER_CHAR);
            fputc(f, '\n');
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
            b->row[i]->square[j] = &(board->square[l * GROUP_LEN + m]);
            // setup the columns
            l = j;
            m = i;
            b->col[i]->square[j] = &(board->square[l * GROUP_LEN + m]);
            // setup the boxes
            l = (i / 3) * 3 + (j / 3);
            m = (i % 3) * 3 + (j % 3);
            b->box[i]->square[j] = &(board->square[l * GROUP_LEN + m]);
        }
    }
}

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

// TODO: make one generic print option which takes a filler char, an
// array of 9 characters to print, and a start/stop char
static void print_header_row(int f) {
    for (int i = 0; i < 3; i++) {
        fputc(f, HEADER_CHAR);
        fputc(f, HEADER_BORDER_CHAR);
        for (int j = 0; j < 2; j++) {
            fputc(f, HEADER_BORDER_CHAR);
            fputc(f, HEADER_BORDER_CHAR);
        }
    }
    fputc(f, HEADER_CHAR);
    fputc(f, '\n');
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
    print_header_row(f);
    for (int i = 0; i < 3; i++) {
        fprint_row(f, b, i);
        print_header_row(f);
    }
    return 0;
}

static void fprint_row(f, Board *b, int row) {
    print_group(f, b->row[row], 9);
}

// Print out a row
void print_row(Board *b, int row) {
    print_group(stdout, b->row[row], 9);
}

// Print out a column
void print_col(int f, Board *b, int col) {
    print_group(stdout, b->col[col], 1);
}

// Print out a box
void print_box(int f, Board *b, int box) {
    print_group(stdout, b->box[box], 3);
}