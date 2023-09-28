//Ex 1 (10 score):
// Enter until value smaller or equal to 0
// Print summerize of all of inputed values.

#include <iostream>

using namespace std;

int main()
{
	//inp: input: input value
	//sum: Sum of all input value
	int inp = 0, sum = 0;
	//calculate sum when inputing
	do {
		sum += inp;
		cout << "Enter Number: ";
		cin >> inp;
	} while (inp > 0);

	cout << "Sum of all input number is " << sum;
}