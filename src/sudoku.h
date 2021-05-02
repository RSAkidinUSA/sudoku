#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include <stdbool.h>

#define GROUP_SIZE 9
#define NUM_GROUPS 9
#define NUM_SQUARES GROUP_SIZE * GROUP_SIZE

// Square object - the most basic block of the board

typedef struct {
    int value;
    bool possible[9];
} Square;

// Functions for the squares

void reset_square(Square *s);
bool is_set(Square *s);

// Group object - there are 3 main types of group:
// Row, column, and box. They all have the same rules
typedef struct {
	Square *square[GROUP_SIZE];
} Group;

// Board object - The overall board

typedef struct {
    Square square[NUM_SQUARES];
    Group row[GROUP_SIZE];
    Group col[GROUP_SIZE];
    Group box[GROUP_SIZE];
} Board;

// Functions for the board
void init_board(Board *b);
void reset_board(Board *b);
int load_board(Board *b, char *filename);
int print_board(Board *b, char *filename);
void print_row(Board *b, int row);
void print_col(Board *b, int col);
void print_box(Board *b, int box);


#endif
