#include "Sort.h"
//compare function to sort the tasks in ascending order
int compare_task_ASC(const void *a, const void *b)
{
    task_array *task1 = (task_array *)a;
    task_array *task2 = (task_array *)b;
    return compare_date(&task1->taskDate, &task2->taskDate);
}

int compare_task_DESC(const void *a, const void *b)
{
    task_array *task1 = (task_array *)a;
    task_array *task2 = (task_array *)b;
    return compare_date(&task2->taskDate, &task1->taskDate);
}

//========= Sort Operations ================
void sort_by_date()
{
    
    int option;
    printf("Enter 1 to sort in ascending order or 2 to sort in descending order: ");
    scanf("%d", &option);

    task_array *task_array_list = (task_array *)malloc(sizeof(task_array) * count);
    int i = 0;
    task *temp = head;
    while (temp != NULL)
    {
        strcpy(task_array_list[i].taskName, temp->taskName);
        strcpy(task_array_list[i].taskCategory, temp->taskCategory);
        task_array_list[i].taskDate = temp->taskDate;
        strcpy(task_array_list[i].taskStatus, temp->taskStatus);
        temp = temp->next;
        i++;
    }
    if (option == 1)
    {
        qsort(task_array_list, count, sizeof(task_array), compare_task_ASC);
    }
    else
    {
        qsort(task_array_list, count, sizeof(task_array), compare_task_DESC);
    }
    printf("\n\n");
    printf("Task Name\tTask Category\tTask Due Date\tTask Status\n");
    for (i = 0; i < count; i++)
    {
        printf("%s\t\t%s\t\t", task_array_list[i].taskName, task_array_list[i].taskCategory);
        print_date(&(task_array_list[i].taskDate));
        printf("\t%s\n", task_array_list[i].taskStatus);
    }
    free(task_array_list);
}