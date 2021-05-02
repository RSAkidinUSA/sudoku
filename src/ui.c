#include "ui.h"

#define BUF_INC 32

static int save(Board *b) {
    printf("Enter a file to save to:\n");
    char *buf = NULL, *tmp;
    int c, len = 0, buflen = 0;
    c = getchar();
    while (c == '\n') {
        c = getchar();
    }
    while (c != '\n' && c != EOF) {
        if (len == buflen) {
            tmp = realloc(buf, buflen + BUF_INC);
            if (!tmp) {
                break;
            }
            buf = tmp;
            buflen += BUF_INC;
        }
        buf[len++] = c;
        buf[len] = '\0';
        c = getchar();
    }
    if (buf) {
        printf("Saving to %s...\n", buf);
        if (print_board(b, buf)) {
            fprintf(stderr, "Error: Unable to save.\n");
        } else {
            printf("Done.\n");
        }
        free(buf);
    } else {
        printf("Unable to save, no filename given...\n");
    }
    return RET_CONT;
}

static int print(Board *b) {
    print_board(b, NULL); 
    return RET_CONT;
}

// TODO
static int edit(Board *b) {
    printf("Not yet implemented...");
    return RET_CONT;
}

static int finish(Board *b) {
    return RET_DONE;
}

static int quit(Board *b) {
    return RET_QUIT;
}

struct Options options[] = {
    {'s', "Save the board", save},
    {'p', "Print the board", print},
    {'e', "Edit the board", edit},
    {'f', "Finished working with this board", finish},
    {'q', "Quit", quit},
};

int menu(Board *b, char *src) {
    int exit = 0;
    int c = '\n';
    printf("%s loaded. ", src);
    do {
        printf("Please select one of the following:\n");
        for (int i = 0; i < ARR_LEN(options); i++) {
            printf("%c - %s.\n", options[i].shortname, options[i].help);
        }
        c = getchar();
        while (c == '\n') {
           c = getchar();
        }
        for (int i = 0; i <= ARR_LEN(options); i++) {
            if (i == ARR_LEN(options)) {
                printf("Invalid selection. ");
                continue;
            }
            if (options[i].shortname == c) {
                exit = options[i].func(b);
                break;
            }
        }
    } while (!exit);
    return exit ^ RET_DONE;
}

