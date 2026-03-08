#ifndef UTILS_H
#define UTILS_H
#include "schedule.h"

int remove_linefeed(char *string);
int find_classes_by_day(ClassSession all_classes[], int total_count, const char *target_day, ClassSession found_classes[]);

#endif