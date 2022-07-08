#include "Task.h"
#include "Date.h"
#include "FileOperations.h"
#include "Sort.h"



int main()
{
    //load data from file
    loadData();
    
    int choice;
    char taskName[50];
    char taskCategory[50];
    date taskDueDate;
    char taskStatus[50];

    while (1)
    {
        printf("\n\n");
        printf("1. Add Task\n");
        printf("2. View All Tasks\n");
        printf("3. Sort By Date\n");
        printf("4. Update Task\n");
        printf("5. Delete Task\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Task Name: ");
                scanf("%s", taskName);
                printf("Enter Task Category: ");
                scanf("%s", taskCategory);
                printf("Enter Task Due Date: ");
                set_date(&taskDueDate);
                printf("Enter Task Status: ");
                scanf("%s", taskStatus);
                addTask(taskName, taskCategory, &taskDueDate, taskStatus);
                break;
            case 2:
                viewAllTasks();
                break;
            case 3:
                sort_by_date();
                break;
            case 4:
                printf("Enter Task Name to update: ");
                scanf("%s", taskName);
                updateTask(taskName);
                break;
            case 5:
                printf("Enter Task Name to delete: ");
                scanf("%s", taskName);
                deleteTask(taskName);
                break;
            case 6:
                saveData();
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}