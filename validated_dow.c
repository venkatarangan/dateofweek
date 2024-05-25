/*
 * Validated Implementation of Tomohiko Sakamoto's Algorithm
 * 
 * Author: Venkatarangan Thirumalai
 * Blog: https://venkatarangan.com
 * Date Originally Written: Early 1990s
 * Date Published on GitHub: 2019
 * Updated: 25 May 2024
 *
 * Description:
 * This is a revised implementation of Tomohiko Sakamoto's Algorithm for finding
 * the day of the week using the C language. This version includes input validation
 * to ensure that the date, month, and year are within valid ranges.
 *
 * License: MIT License
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get the number of days in a month
int getDaysInMonth(int month, int year) {
    if (month < 1 || month > 12) {
        return 0;
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // February has 29 days in a leap year
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return daysInMonth[month - 1];
}

// Validate the date
bool isValidDate(int day, int month, int year) {
    if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth = getDaysInMonth(month, year);
    return day <= daysInMonth;
}

// Prompt a string and accept an integer from console
int GetInteger(char *DisplayName) {
    int TempValue;
    while (true) {
        printf("%s", DisplayName);
        if (scanf("%d", &TempValue) == 1) {
            // Ensure value is within the range of an integer
            if (TempValue >= INT_MIN && TempValue <= INT_MAX) {
                break;
            } else {
                printf("Value out of range. ");
            }
        } else {
            printf("Invalid input. ");
            while (getchar() != '\n'); // clear invalid input from buffer
        }
    }
    return TempValue;
}

// Quick n Dirty implementation of Tomohiko Sakamoto's Algorithm for finding day of the week using C language
int dow(int y, int m, int d) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

int main() {
    const char *DayNames[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
    };

    int day, month, year;
    while (true) {
        day = GetInteger("Enter a Date: ");
        month = GetInteger("Enter a Month: ");
        year = GetInteger("Enter a Year: ");

        if (isValidDate(day, month, year)) {
            break;
        } else {
            printf("Invalid date entered. Please try again.\n");
        }
    }

    int myDoW = dow(year, month, day);
    char str[10];

    printf("Date in YYYY-MM-DD is: %i-%i-%i \n", year, month, day);
    printf("Day of the week in number: %i \n", myDoW);
    printf("Day of the week in words: %s \n", DayNames[myDoW]);
    printf("Type any character & <ENTER> to quit: ");
    scanf("%s", str);

    return 0;
}
