//HEADER FILE FOR DATE MANIPULATION
#ifndef DATE_H
#define DATE_H

typedef struct Date
{
    int day;
    int month;
    int year;
}date;

//functions
void set_date(date *d); //take date from user input
void print_date(date *d); //print date to std output
int compare_date(date *d1, date *d2); //compare two dates

#endif // DATE_H
