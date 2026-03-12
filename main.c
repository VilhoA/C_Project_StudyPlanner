#include <stdio.h>
#include <string.h>
#include "schedule.h"
#include "utils.h"

int main(void) {
    ClassSession main_schedule[MAX_CLASSES];
    char filename[MAX_FILE_LEN] = "schedule.csv"; //Change this if you want to change the file
    int class_count = 0;
    char userinput[MAX_USERI_LEN] = "";

    class_count = read_schedule(filename, main_schedule);
    if (class_count < 1) {
        printf("Could not get lines from given file\n");
        return 1;
    }

    //Main loop for asking the day
    while (strcmp(userinput, "Stop") != 0){

        printf("Enter day: ");
        if (fgets(userinput, MAX_USERI_LEN, stdin) != NULL) {
            remove_linefeed(userinput);
            format_input(userinput);
        }

        //If user input not "stop" and actual input was given
        if (strcmp(userinput, "Stop") != 0 && strlen(userinput) > 0) {
            if (is_weekday(userinput)) {                                 //Checks if the input was a weekday
                ClassSession day_classes[MAX_CLASSES];
                int found_amount = find_classes_by_day(main_schedule, class_count, userinput, day_classes);

                if (found_amount > 0) {
                    sort_classes_by_time(day_classes, found_amount);

                    printf("On %s you have:\n", userinput);
                    for (int i = 0; i < found_amount; i++) {
                        printf("%6s|%-20s|%-10s\n", day_classes[i].time_str, day_classes[i].course, day_classes[i].room);
                    }
                }else {
                    printf("No classes today!\n");
                }
            }else {                   //Input was not a weekday or "stop"
                printf("\n*** Please enter a weekday like \"monday\" or \"stop\" to end program ***\n\n");
            }
        }

    }
    return 0;
}