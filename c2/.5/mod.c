#include <stdio.h>

void isLeapYear(int year);

int main()
{
    isLeapYear(20);
    isLeapYear(200);
    isLeapYear(800);
}

void isLeapYear(int year)
{
    if (year % 4 == 0 && year % 400 == 0 || year % 100 != 0)
        printf("The year %d is a leap year!\n", year);
    else
        printf("The year %d is not a leap year.\n", year);
}
