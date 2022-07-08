#include<stdio.h>
#include "Date.h"

//========= Date Management ================

//A function to set the date
void set_date(date *d)
{
    printf("Enter the day: ");
    scanf("%d", &d->day);
    printf("Enter the month: ");
    scanf("%d", &d->month);
    printf("Enter the year: ");
    scanf("%d", &d->year);
}

//A function to compare Dates
int compare_date(date *d1, date *d2){
    if(d1->year > d2->year)
        return 1;
    else if(d1->year < d2->year)
        return -1;
    else if(d1->month > d2->month)
        return 1;
    else if(d1->month < d2->month)
        return -1;
    else if(d1->day > d2->day)
        return 1;
    else if(d1->day < d2->day)
        return -1;
    else
        return 0;
}

//A function to print the date
void print_date(date *d)
{
    printf("%d/%d/%d", d->day, d->month, d->year);
}