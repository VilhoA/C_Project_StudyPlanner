#include <stdio.h>
#include <string.h>
#include "utils.h"

int remove_linefeed(char *string) {
    int length = strlen(string);

    if (length > 0 && string[length - 1] == '\n') {
        string[length - 1] = '\0';
    }

    //if there's overflow this empties it
    else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return 0;
}
