//Ex 5 (10 score):
// Enter number of elements
// Generate randomize array of N elements (value in range [0,50]) and calculate sum of it.
// Ouput array & sum

#include <iostream>
#include <limits>
#include <random>
#include <time.h>

int main()
{
	//N: Number of array of random value from 0 to 50
	//recent: Random number in recent.
	//sum: Summerize of all randomized number.
	int N = 0, recent = 0, sum = 0;
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
	int min_number = 0, max_number = 50;
	for (int i = 0; i < N; i++) {
		//Recipe: rand() % (max_number + 1 - minimum_number) + minimum_number
		recent = rand() % (max_number + 1 - min_number) + min_number;
		//print recent value
		std::cout << recent << " ";
		sum += recent;
	}
	//print sum of all values
	std::cout << " = " << sum;
}