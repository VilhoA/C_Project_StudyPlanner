#ifndef UTILS_H
#define UTILS_H
#include "schedule.h"

int remove_linefeed(char *string);
int find_classes_by_day(ClassSession all_classes[], int total_count, const char *target_day, ClassSession found_classes[]);
void sort_classes_by_time(ClassSession classes[], int count);
void format_input(char *str);

#endif