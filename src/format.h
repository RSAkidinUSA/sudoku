#ifndef _FORMAT_H_
#define _FORMAT_H_

#include <stdio.h>
#include "sudoku.h"

#define HEADER_CHAR '+'
#define SPACE_CHAR ' '
#define HEADER_BORDER_CHAR '-'
#define BORDER_CHAR '|'

int read_file(Board *b, FILE *f);

#endif
