//Ex 3 (20 score):
// Enter integer number until value smaller or equal to 0
// Print list of odd numbers
//       list of even numbers
//       list of prime numbers

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

/**
 * checkPrimeNumber
 * @param x: number to check
 * Check parameter number is an prime number or not.
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
	//inp: input value
	//oddVec: vector of odd number of input value
	//evenVec: vector of even number of input value
	//eleVec: vector of prime number of input value
	int inp = 0;
	vector<int> oddVec, evenVec, eleVec;

	//Processing input values
	do {
		if (inp != 0) {
			if (inp % 2 == 0) {
				evenVec.push_back(inp);
			}
			else {
				oddVec.push_back(inp);
			}
		}
		if (checkPrimeNumber(inp)) {
			eleVec.push_back(inp);
		}
		cout << "Enter Number: ";
		cin >> inp;
	} while (inp > 0);

	//Output Result
	// Odd Array
	cout << "In all of inputed value, there are: " << endl;
	cout << " - " << oddVec.size() << " Odd Number(s): ";
	for (int i = 0; i < oddVec.size(); i++) {
		cout << oddVec[i] << " ";
	}
	// Even Array
	cout << endl;
	cout << " - " << evenVec.size() << " Even Number(s): ";
	for (int i = 0; i < evenVec.size(); i++) {
		cout << evenVec[i] << " ";
	}
	//
	cout << endl;
	cout << " - " << eleVec.size() << " Prime Number(s): ";
	for (int i = 0; i < eleVec.size(); i++) {
		cout << eleVec[i] << " ";
	}
}
