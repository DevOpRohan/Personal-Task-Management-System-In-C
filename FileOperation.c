
#include "FileOperations.h"
#include "Date.h"
#include "Task.h"

//========= File Operations ================
//load data from file
void loadData()
{
    fp = fopen("task.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
    }
    else
    {
        char taskName[50];
        char taskCategory[50];
        char taskStatus[50];
        int day, month, year;
        while (fscanf(fp, "%s\t", taskName) != EOF)
        {
            fscanf(fp, "%s\t", taskCategory);
            fscanf(fp, "%d/%d/%d\t", &day, &month, &year);
            fscanf(fp, "%s\t", taskStatus);
            addTask(taskName, taskCategory, &(date){day, month, year}, taskStatus);
        }
        fclose(fp);
    }
}

void saveData()
{
    fp = fopen("task.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            fprintf(fp, "%s\t", current->taskName);
            fprintf(fp, "%s\t", current->taskCategory);
            fprintf(fp, "%d/%d/%d\t", current->taskDate.day, current->taskDate.month, current->taskDate.year);
            fprintf(fp, "%s\t", current->taskStatus);
            current = current->next;
        }
        fclose(fp);
    }
}