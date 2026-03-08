#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "schedule.h"

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

//Finds all classes for a day and puts them to a new array. Returns class amount
int find_classes_by_day(ClassSession all_classes[], int total_count, const char *target_day, ClassSession found_classes[]) {
    int found_count = 0;

    for (int i = 0; i < total_count; i++) {

        if (strcmp(all_classes[i].day, target_day) == 0) {
            found_classes[found_count] = all_classes[i];
            found_count ++;
        }

    }
    return found_count;
}
// Sorts the given array to ascending by the hour
void sort_classes_by_time(ClassSession classes[], int count) {

    for (int i = 0; i < count - 1; i++) {
        // Compares current and next value
        for (int j = 0; j < count - i - 1; j++) { //-1 for optimization
            if (classes[j].time_in_minutes > classes[j + 1].time_in_minutes) {
                ClassSession temp = classes[j];

                classes[j] = classes[j + 1];
                classes[j + 1] = temp;
            }
        }
    }
}
