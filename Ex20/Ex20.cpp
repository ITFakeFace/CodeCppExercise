//Ex 20 (10 score):
// Enter N
// Calculate Z, Output Z
//                1 +   2^2   +   3^3   + ... +   N^N
//     With Z =  ---------------------------------------
//                1 + 2^(1/2) + 3^(1/3) + ... + N^(1/N) 

#include <iostream>
#include <iomanip>
#include <limits>
#include <math.h>

int main()
{
	//N: set limit of level of fraction elements.
	int N = 0;
	std::cout << "Enter Number to input: ";
	std::cin >> N;
	//check invalid input
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "#Warn: Invalid input !! Please Re-enter: ";
		std::cin >> N;
	}

	//numerator: numerator (above of fraction)
	//denominator: denominator (below of fraction)
	//fraction = numerator / denominator
	float numerator = 0, denominator = 0;
	for (int i = 1; i <= N; i++) {
		numerator += pow(i, i);
		denominator += pow(i, 1.0 / i);
	}

	std::cout << "Result is " << std::fixed << std::setprecision(2) << numerator / denominator;
}