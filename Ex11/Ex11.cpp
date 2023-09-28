//Ex 11 (50 score):
// Enter month & year
// Output calendar of this month.

#include <iostream>
#include <iomanip>

/**
 * @name: getDayOfMonth
 * @param: month: inputed month,
 *		   year: inputed year.
 * @briefly: Calculating what the last day of inputed month is.
 * @return: Last day of month.
 */
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

/**
 * @name: getDayOfWeek
 * @param: day: inputed day,
 *		   month: inputed month,
 *		   year: inputed year.
 * @briefly: Calculate Weekday code by recipe (0 as Sunday, ... 6 as Saturday).
 * @return: Code of Weekday
 */
int getDayOfWeek(int day, int month, int year) {
	//Recipe: (day + 2*month + (3*(month + 1)) div 5 + year + (year div 4)) mod 7
	if (month < 3) {
		month += 12;
		year--;
	}
	return div(day + 2 * month + div(3 * (month + 1), 5).quot + year + div(year, 4).quot, 7).rem;
}

/**
 * @name: printCalendar
 * @param: month: inputed month,
 *		   year: inputed year.
 * @briefly: Calculating day of month and Print data as Calendar.
 * @return: (none).
 */
void printCalendar(int month, int year) {
	int dow = getDayOfWeek(1, month, year), lastDay = getDayOfMonth(month, year), count = 1;
	std::cout << " Sun Mon Tue Wed Thu Fri Sat" << std::endl;
	for (int i = 0; i <= lastDay + dow; i++) {
		if (i >= dow && i < lastDay + dow) {
			std::cout << " " << std::setw(3) << i - dow + 1;
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
	//month: inputed month to print calendar
	//year: inputed year to print calendar
	int month, year;
	std::cout << "Enter month: ";
	std::cin >> month;
	std::cout << "Enter year: ";
	std::cin >> year;

	printCalendar(month, year);
}