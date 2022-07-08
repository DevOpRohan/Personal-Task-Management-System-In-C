//Array structure to display the tasks in sorted order
#include "Task.h"
#include "Date.h"
#ifndef SORT_H
#define SORT_H
typedef struct task_array
{
    char taskName[50];
    char taskCategory[50];
    date taskDate;
    char taskStatus[50];
} task_array;

//compare function to sort the tasks in ascending order
int compare_task_ASC(const void *a, const void *b);
int compare_task_DESC(const void *a, const void *b);
void sort_by_date();

#endif