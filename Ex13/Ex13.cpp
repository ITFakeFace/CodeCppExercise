//Ex 13 (10 score):
// Enter N
// Output Prime Number from 1st element to Nth element.

#include <iostream>
#include <limits>

/**
 * @name: checkPrimeNumber
 * @param x: number to check
 * @briefly: Check parameter number is an prime number or not.
 * @return true if parameter is prime number
 *         false if parameter is not prime number
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

int main()
{
	//N: Number of Prime Numbers to generate
	int N = 0;
	std::cout << "Enter Number to generate: ";
	std::cin >> N;
	//check invalid input
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "#Warn: Invalid input !! Please Re-enter: ";
		std::cin >> N;
	}

	//Check Prime number and Output
	std::cout << "Prime Number: ";
	for (int i = 2;; i++) {
		if (N > 0) {
			if (checkPrimeNumber(i)) {
				std::cout << " " << i;
				N--;
			}
		}
		else {
			break;
		}
	}
}