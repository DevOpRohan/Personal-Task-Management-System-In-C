#include"Task.h"
//========= LinkedList Operations ================
void addTask(char taskName[], char taskCategory[], date *taskDueDate, char taskStatus[])
{
    task *newTask = (task *)malloc(sizeof(task));
    strcpy(newTask->taskName, taskName);
    strcpy(newTask->taskCategory, taskCategory);
    newTask->taskDate = *taskDueDate;
    strcpy(newTask->taskStatus, taskStatus);
    newTask->next = NULL;

    if (head == NULL)
    {
        head = newTask;
    }
    else
    {
        last->next = newTask;
    }
    last = newTask;
    count++;
}

void viewAllTasks()
{
    if (head == NULL)
    {
        printf("No tasks to view\n");
    }
   
    else
    {
        current = head;
       printf("Task Name\tTask Category\tTask Due Date\tTask Status\n");
        while (current != NULL)
        {
            printf("%s\t\t%s\t\t", current->taskName, current->taskCategory);
            print_date(&current->taskDate);
            printf("\t%s\n", current->taskStatus);
            current = current->next;
        }
    }
}

void updateTask(char taskName[])
{
    if (head == NULL)
    {
        printf("No tasks to update\n");
    }
    else
    {
        current = head;
        int flag = 0;
        while (current != NULL)
        {
            if (strcmp(current->taskName, taskName) == 0)
            {
                printf("Enter task name: ");
                scanf("%s", current->taskName);
                printf("Enter task category: ");
                scanf("%s", current->taskCategory);
                printf("Enter task due date: ");
                set_date(&(current->taskDate));
                printf("Enter task status: ");
                scanf("%s", current->taskStatus);

                flag = 1;
                break;
            }
            current = current->next;
        }

        if (flag == 0)
        {
            printf("Task not found\n");
        }
    }
}

void deleteTask(char taskName[])
{
    if (head == NULL)
    {
        printf("No tasks to delete\n");
    }
    else
    {
       //Search for the task to be deleted
        current = head;
        task *prev = NULL;

        int flag = 0;

        while (current != NULL)
        {
            if (strcmp(current->taskName, taskName) == 0)
            {
                if (prev == NULL)
                {
                    head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                free(current);
                count--;
                flag = 1;
                break;
            }
            prev = current;
            current = current->next;
        }
        if (flag == 0)
        {
            printf("Task not found\n");
        }
    }
}