#include <stdio.h>
#include "format.h"

// returns 0 if no errors, else 1
int read_file(Board *b, int f) {
    int c;
    int row = 0, col = 0;
    // TODO: psuedocode

    // read the first char of each line to determine if it's a header or data
    do {
    	c = getchar(f);
    	switch (c) {
    		case HEADER_CHAR:
    			do {
    				c = getchar(f); // read in the rest of the line
    			} while (c != '\n' && c != EOF);
    			break;
    		case '0':
    		case '1':
    		case '2':
    		case '3':
    		case '4':
    		case '5':
    		case '6':
    		case '7':
    		case '8':
    		case '9':
    			b->

    		case EOF:
    	}
    } while (c != EOF);

    // data lines should alternate a number between 0 and 9 and a non-number
    // if more than 9 values, or more than 9 lines, there's an issue
}

