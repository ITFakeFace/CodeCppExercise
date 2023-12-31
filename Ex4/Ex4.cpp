//Ex 4 (30 score):
// Enter integer number until value smaller or equal to 0
// Print list of prime number
//       list of perfect number
//       list of square number

#include <iostream>
#include <limits>

using namespace std;

/**
 * @name: checkPrimeNumber
 * @param x: number to check
 * @briefly: Check parameter number is an Prime number or not.
 * @return true if parameter is Prime number
 *         false if parameter is not Prime number
 */
bool checkPrimeNumber(int x) {
	if (x > 2) {
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) {
				return false;
			}
		}
		return true;
	}
	else {
		if (x == 2) {
			return true;
		}
	}
	return false;
}

/**
 * @name: checkPerfectNumber
 * @param x: number to check
 * @briefly: Check parameter number is an perfect number or not.
 * @return true if parameter is perfect number
 *         false if parameter is not perfect number
 */
bool checkPerfectNumber(int x) {
	// sumOfDiv: Sum of Divisor: 
	int sumOfDiv = 0;
	for (int i = 1; i < x; i++) {
		if (x % i == 0) {
			sumOfDiv += i;
		}
	}
	if (sumOfDiv == x) {
		return true;
	}
	return false;
}

/**
 * @name: checkSquareNumber
 * @param x: number to check
 * @briefly: Check parameter number is an square number or not.
 * @return true if parameter is square number
 *         false if parameter is not square number
 */
bool checkSquareNumber(int x) {
	if ((float)sqrt(x) - (int)sqrt(x) == 0) {
		return true;
	}
	return false;
}

int main()
{
	//inp: input value
	//eleNum: number of Prime number of input values
	//perfNum: number of perfect number of input values
	//sqrVec: number of square number of input values
	int inp = 0, eleNum = 0, perfNum = 0, sqrNum = 0;

	//Processing Input value
	do {
		if (inp != 0) {
			if (checkPrimeNumber(inp)) {
				eleNum++;
			}
			if (checkPerfectNumber(inp)) {
				perfNum++;
			}
			if (checkSquareNumber(inp)) {
				sqrNum++;
			}
		}
		cout << "Enter Number: ";
		cin >> inp;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "#Warn: Invalid input !! Please Re-enter: ";
			cin >> inp;
		}
	} while (inp > 0);

	//Output result
	cout << "In all of inputed value, there are: " << endl;
	cout << " - " << eleNum << " Prime Number(s)";
	cout << " - " << perfNum << " Perfect Number(s)";
	cout << " - " << sqrNum << " Square Number(s)";
}