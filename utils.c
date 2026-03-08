#include <stdio.h>
#include <string.h>
#include "utils.h"

//Change \n to \0. If \n was not found then empty input buffer
int remove_linefeed(char *string) {
    int length = strlen(string);

    if (length > 0 && string[length - 1] == '\n') {
        string[length - 1] = '\0';
    }

    else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return 0;
}
