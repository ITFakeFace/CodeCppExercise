//Ex 7 (20 score):
// Enter number of elements
// Generate randomize array of N elements (real number, value in range [-20,20]) 
// And calculate sum of it.
// Ouput array & sum (2 precision)

#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>

int main()
{
	//N: Number of array of random value from 0 to 50
	//recent: Random number in recent.
	//sum: Summerize of all randomized number.
	int N = 0;
	float recent = 0, sum = 0;
	std::cout << "Enter Number to generate: ";
	std::cin >> N;
	//check invalid input
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "#Warn: Invalid input !! Please Re-enter: ";
		std::cin >> N;
	}
	//generate seed
	srand((int)time(0));
	//setting range of randomize
	int min_number = 0, max_number = 100, pointDecimal = 1;
	for (int i = 0; i < N; i++) {
		//Recipe: (rand() % (max_number + 1 - minimum_number) + minimum_number)/10^pointDecimal
		recent = (rand() % (max_number + 1 - min_number) + min_number) / pow(10, pointDecimal);
		//print recent value
		std::cout << recent << " ";
		sum += recent;
	}
	std::cout << " = " << std::fixed << std::setprecision(2) << sum;
}