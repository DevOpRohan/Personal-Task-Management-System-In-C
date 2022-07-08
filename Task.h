#include <stdio.h>
#include "Date.h"
#include "stdlib.h"

#ifndef TASK_H
#define TASK_H
// DataStructure ==> use of Singley Linked List
typedef struct task
{
    char taskName[50];
    char taskCategory[50];
    date taskDate;
    char taskStatus[50];
    struct task *next;
} task;

task *head = NULL; //head pointer
task *current = NULL; //used to traverse the list
task *last = NULL;  //to keep track of last node
int count = 0;  /// to keep track of number of tasks

//functions prototypes
void addTask(char taskName[], char taskCategory[], date *taskDueDate, char taskStatus[]);
void viewAllTasks();
void updateTask(char taskName[]);
void deleteTask(char taskName[]);
#endif // TASK_H