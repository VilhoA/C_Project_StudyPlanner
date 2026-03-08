#include <stdio.h>
#include "schedule.h"

#include <string.h>

//Opens, reads, parses and closes the csv file. Returns line amount as integer
int read_schedule(const char *filename, ClassSession schedule[]) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Opening file %s failed\n", filename);
        return -1;
    }

    int linecount = 0;
    char line_buffer[MAX_LINE_LEN];

    //Read the "header" out so we can only read actual data needed
    fgets(line_buffer, MAX_LINE_LEN, file);

    while (linecount < MAX_CLASSES && fgets(line_buffer, MAX_LINE_LEN, file)) {

        char *strtok_token = strtok(line_buffer, ",");

        //Day
        if (strtok_token != NULL) {
            strncpy(schedule[linecount].day, strtok_token, MAX_DAY_LEN -1);

            schedule[linecount].day[MAX_DAY_LEN -1] = '\0';
        }

        //Time as string
        strtok_token = strtok(NULL, ",");

        if (strtok_token != NULL) {
            strncpy(schedule[linecount].time_str, strtok_token, MAX_TIME_LEN -1);

            schedule[linecount].time_str[MAX_TIME_LEN -1] = '\0';

            //Convert time str to total minutes int
            int hours = 0;
            int minutes = 0;

            if (sscanf(schedule[linecount].time_str, "%d:%d", &hours, &minutes) == 2) {
                schedule[linecount].time_in_minutes = (hours * 60) + minutes;
            }
            else { //If sscanf fails
                schedule[linecount].time_in_minutes = -1;
            }
        }

        //Course
        strtok_token = strtok(NULL, ",");

        if (strtok_token != NULL) {
            strncpy(schedule[linecount].course, strtok_token, MAX_COURSE_LEN -1);

            schedule[linecount].course[MAX_COURSE_LEN -1] = '\0';
        }

        //Room
        strtok_token = strtok(NULL, ",\n"); //Added \n for final line

        if (strtok_token != NULL) {
            strncpy(schedule[linecount].room, strtok_token, MAX_ROOM_LEN -1);

            schedule[linecount].room[MAX_ROOM_LEN -1] = '\0';
        }

        linecount ++;
    }

    fclose(file);

    return linecount; //Returns total amount of lines read
}

