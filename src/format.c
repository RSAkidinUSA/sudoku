#include "format.h"

// returns 0 if no errors, else 1
int read_file(Board *b, FILE *f) {
    int c;
    int count = 0;
    // TODO: psuedocode

    // read the first char of each line to determine if it's a header or data
    do {
    	c = fgetc(f);
    	switch (c) {
    		case HEADER_CHAR:
    			do {
    				c = fgetc(f); // read in the rest of the line
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
                if (count < 9 * 9) {
        			b->square[count++].value = c - '0';
                    break;
                } else {
                    fprintf(stderr, "Error: Tried to read in "\
                            "too many values...\n");
                    return 1;
                }
            // valid values we should just skip
            case BORDER_CHAR:
            case ' ':
    		case EOF:
                break;
            // if we get a newline where we expect it, all good
            case '\n':
                if (! (count % 9)) {
                    break;
                }
            // otherwise fall through into errors
            // Errors
            default:
                fprintf(stderr, "Error: Read char %c (0x%02x) after %d values."\
                        "\nI don't know what to do...\n", (char) c, c, count);
                return 1;
    	}
    } while (c != EOF);
    // check we didn't run into any errors, check we had enough values
    return 0;
}

