#ifndef SCHEDULE_H
#define SCHEDULE_H

// All nesecary string lenghts
#define MAX_DAY_LEN 20
#define MAX_TIME_LEN 10
#define MAX_COURSE_LEN 50
#define MAX_ROOM_LEN 20

// Struct for one class
typedef struct {
    char day[MAX_DAY_LEN];
    char time_str[MAX_TIME_LEN];
    int time_in_minutes;
    char course[MAX_COURSE_LEN];
    char room[MAX_ROOM_LEN];
} ClassSession;

// Maximum class amount
#define MAX_CLASSES 100

#endif