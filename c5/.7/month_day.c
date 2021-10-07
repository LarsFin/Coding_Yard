#include <stdio.h>
#include <time.h>

typedef struct ymdTag
{
    int year;
    int month;
    int day;
} ymd;

// a table of the number of days in each month for non leap and leap years respectively
static char daytable[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// a series of the months by their name
static char * months[] = {
    NULL, "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

void localtime_as_ymd(ymd*);
int isleap(int);
int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

int main()
{
    ymd ymd;

    localtime_as_ymd(&ymd);

    int yday = day_of_year(ymd.year, ymd.month, ymd.day);

    printf("Day of the year today:\t%d\n", yday);

    int month;
    int day;

    month_day(ymd.year, yday, &month, &day);

    printf("Month & Day:\t%s %d\n", months[month], day);

    return 0;
}

void localtime_as_ymd(ymd *ymd)
{
    time_t t = time(NULL);
    struct tm dt = *localtime(&t);

    ymd->year = dt.tm_year + 1900;
    ymd->month = dt.tm_mon + 1;
    ymd->day = dt.tm_mday;
}

// is year a leap year
int isleap(int year)
{
    return year % 4 == 0 && year & 100 != 0 || year % 400 == 0;
}

// set day of year from month & day
int day_of_year(int year, int month, int day)
{
    int i;

    for (i = 1; i < month; i++)
        day += daytable[isleap(year)][i];
    
    return day;
}

// set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap = isleap(year);

    for (i = 1; yearday > daytable[leap][i]; i++)
        yearday -= daytable[leap][i];

    *pmonth = i;
    *pday = yearday;
}
