#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

//Doomsday way (Incoming)
int getLastDayOfMonth(int month, int year) {
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
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
				return 29;
			}
			else {
				return 28;
			}
			break;
	}
	return 0;
}

//Uncommon way 1
//src="https://welearnvn.com/cach-tinh-thu-khi-biet-ngay-thang-nam/"
int getDayOfWeek(int day, int month, int year) {
	//Recipe: (day + 2*month + (3*(month + 1)) div 5 + year + (year div 4)) mod 7
	if (month < 3) {
		month += 12;
		year--;
	}
	return div(day + 2*month + div(3*(month + 1),5).quot + year + div(year,4).quot,7).rem;
}

//Uncommon way 2
//src="https://artofmemory.com/blog/how-to-calculate-the-day-of-the-week/"
int calcYearCode(int year) {
	//Recipe = (YY + (YY div 4)) mod 7
	int YY = div(year, 100).rem;
	return div(YY + div(YY,4).quot, 7).rem;
}

int calcMonthCode(int month) {
	//Recipe:
	//  January = 0
	//  February = 3
	//  March = 3
	//  April = 6
	//  May = 1
	//  June = 4
	//  July = 6
	//  August = 2
	//  September = 5
	//  October = 0
	//  November = 3
	//  December = 5
	switch (month) {
		case 1:
			return 0;
			break;
		case 2:
			return 3;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 6;
			break;
		case 5:
			return 1;
			break;
		case 6:
			return 4;
			break;
		case 7:
			return 6;
			break;
		case 8:
			return 2;
			break;
		case 9:
			return 5;
			break;
		case 10:
			return 0;
			break;
		case 11:
			return 3;
			break;
		case 12:
			return 5;
			break;
		default:
			std::cout << "Invalid month";
			break;
	}
	return -1;
}

int calcCenturyCode(int year) {
	if (year >= 1753 && year <= 2399) {
		//Gregorian Dates
		//Recipe: 
		//  1700s = 4
		//	1800s = 2
		//	1900s = 0
		//	2000s = 6
		//	2100s = 4
		//	2200s = 2
		//	2300s = 0
		switch ((int)(year - year % 100) / 100) {
			case 17:
				return 4;
				break;
			case 18:
				return 2;
				break;
			case 19:
				return 0;
				break;
			case 20:
				return 6;
				break;
			case 21:
				return 4;
				break;
			case 22:
				return 2;
				break;
			case 23:
				return 0;
				break;
		}
	}
	else if (year < 1753) {
		//Julian Dates
		//Recipe: (18 - (YYYY div 100)) mod 7
		return div(18-div(year,100).quot,7).rem;
	}
}

int calcLeapYear(int year) {
	if (year >= 1753 && year <= 2399) 
	{
		//Gregordian Dates
		return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
	}
	else if (year < 1753) 
	{
		//Julian Dates
		return (year % 4 == 0) ? 1 : 0;
	}
}

int getDayOfWeek2(int day, int month, int year) {
	//Recipe = (Year Code + Month Code + Century Code + Date Number - Leap Year Code) mod 7
	int yearCode = calcYearCode(year);
	int monthCode = calcMonthCode(month);
	int centuryCode = calcCenturyCode(year);
	int leapYearCode = calcLeapYear(year);
	return div(yearCode + monthCode + centuryCode + day - leapYearCode, 7).rem;
}

//Uncommon way 3
//src="https://www.hackerearth.com/blog/developers/how-to-find-the-day-of-a-week/"
int getDayOfWeek3(int day, int month, int year) {
	return 0;
}

void printDayOfWeek(int day, int month, int year) {
	std::cout << "Date : " << day << "/" << month << "/" << year << " is ";

	switch (getDayOfWeek(day, month, year)) {
		case 0:
			std::cout << "Sunday";
			break;
		case 1:
			std::cout << "Monday";
			break;
		case 2:
			std::cout << "Tuesday";
			break;
		case 3:
			std::cout << "Wednesday";
			break;
		case 4:
			std::cout << "Thursday";
			break;
		case 5:
			std::cout << "Friday";
			break;
		case 6:
			std::cout << "Saturday";
			break;
	}
}

int main()
{
	int day, month, year;
	std::cout << "Enter day: ";
	std::cin >> day;
	std::cout << "Enter month: ";
	std::cin >> month;
	std::cout << "Enter year: ";
	std::cin >> year;

	printDayOfWeek(day, month, year);
}