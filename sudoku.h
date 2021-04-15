#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#define GROUP_SIZE 9
#define NUM_GROUPS 9
#define NUM_SQUARES GROUP_SIZE * GROUP_SIZE

// Square object - the most basic block of the board

typedef struct Square {
    int value;
    bool possible[9];
}

// Functions for the squares

void reset_square(Square *s);
bool is_set(Square *s);

// Group object - there are 3 main types of group:
// Row, column, and box. They all have the same rules

// Board object - The overall board

typedef struct Board {
    Square square[NUM_SQUARES];
    Group row[GROUP_SIZE];
    Group column[GROUP_SIZE];
    Group box[GROUP_SIZE];
};

// Functions for the board

void reset_board(Board *b);
int load_board(Board *b, char *filename);
int print_board(Board *b, char *filename);


#endif
