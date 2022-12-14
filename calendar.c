#include <stdio.h>

 

int isLeapYear(int year);

int totalDaysYearMonth(int year, int month);

// year : 년도month : 월을입력하면그년도그월의총일수가

// 반환된다.

int totalDaysYear(int year);

int firstDayOfYear(int year);

 

int DayOfWeekYearMonth(int year, int month);

// year : 년도month : 월을입력하면그년도그월의요일이

// 반환된다.

 

int main( )

{

    int year;

    int month;

    int i;

    int totalDay = 0;

    printf("연,월을입력하시오:");

    scanf("%d,%d", &year, &month);

 

    printf("%d\n", DayOfWeekYearMonth(year, month));

 

    return 0;

}

 

int DayOfWeekYearMonth(int year, int month)

{

    int i;

    int totalDay = 0;

 

    totalDay = firstDayOfYear(year);

    for( i = 1 ; i < month ; i++)

    {

        totalDay += totalDaysYearMonth(year, i);

    }

    return totalDay % 7;

}

 

int firstDayOfYear(int year)

{

    int i;

    int totalDay = 0;

    for ( i = 1980 ; i < year ; i++ )

    {

        totalDay += totalDaysYear(i);

    }

    return totalDay % 7;

}

int totalDaysYear(int year)

{

    if( isLeapYear(year) )

    {

        return 366;

    }

    else

    {

        return 365;

    }

}

int totalDaysYearMonth(int year, int month)

{

 

    if( month == 1 || month == 3 ||

        month == 5 || month == 7 ||

        month == 8 || month == 10 ||

        month == 12 )

    {

        return 31;

    }

    else

    {

        if( month == 2 )

        {

            if( isLeapYear(year) )

            {

                return 29;

            }

            else

            {

                return 28;

            }

        }

        else

        {

            return 30;

        }

    }

}

int isLeapYear(int year)

{

    if( ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0) )

    {

        return 1;

    }

    else

    {

        return 0;

    }


}
