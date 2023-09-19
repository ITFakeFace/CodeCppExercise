#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

int getDayOfMonth(int month, int year) {
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        //Gregordian Dates
        return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
        break;
    default:
        std::cout << "Invalid month !!";
        return 0;
        break;
    }
}

int getDayOfWeek(int day, int month, int year) {
    //Recipe: (day + 2*month + (3*(month + 1)) div 5 + year + (year div 4)) mod 7
    if (month < 3) {
        month += 12;
        year--;
    }
    return div(day + 2 * month + div(3 * (month + 1), 5).quot + year + div(year, 4).quot, 7).rem;
}

void printCalendar(int month, int year) {
    int dow = getDayOfWeek(1, month, year), lastDay=getDayOfMonth(month,year), count = 1;
    std::cout << " Sun Mon Tue Wed Thu Fri Sat" << std::endl;
    for (int i = 0; i <= lastDay+dow; i++) {
        if (i >= dow && i < lastDay+dow) {
            std::cout << " " << std::setw(3) << i-dow+1;
        }
        else {
            std::cout << "    ";
            
        }
        count++;
        if (count > 7) {
            std::cout << std::endl;
            count = 1;
        }
    }
}

int main()
{
    int month, year;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cout << "Enter year: ";
    std::cin >> year;

    printCalendar(month, year);
}