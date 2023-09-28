//Ex 10 (10 score):
// Enter month & year
// Output total days of this month.

#include <iostream>

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

int main()
{
	//month: inputed month to check
	//year: inputed year to check
	int month, year;
	std::cout << "Enter month: ";
	std::cin >> month;
	std::cout << "Enter year: ";
	std::cin >> year;

	std::cout << "There is " << getDayOfMonth(month, year) << " days in " << month << "/" << year;
}