#ifndef _UI_H_
#define _UI_H_

#include <stdlib.h>
#include <stdio.h>
#include "sudoku.h"

#define HELP_LEN 256
#define RET_CONT 0 // return value for continue
#define RET_DONE 1 // return value to finish this board and go to the next
#define RET_QUIT 2 // return value to quit

#define ARR_LEN(x) (sizeof(x) / sizeof((x)[0]))

struct Options {
    int shortname;
    char help[HELP_LEN];
    int (*func)(Board *b);
};

int menu(Board *b, char *src);

#endif
