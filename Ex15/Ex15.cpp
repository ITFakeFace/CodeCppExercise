//Ex 15 (10 score):
// Enter number of randomizing elements, automatically create randomizing array, 
// Output all of Odd elements, Even elements.

#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

/**
 * @name: generateRandomArray
 * @param: arr: array of integers,
 *		   N: Number of necessary elements to generate,
 *		   min_number: smallest value of each elements,
 *		   max_number: largest value of each elements.
 * @briefly: Generate array with randomized value.
 * @return: (none).
 */
void generateRandomArray(std::vector<int>& arr, int N, int min_number, int max_number) {
	//generate seed
	srand((int)time(0));

	//clear vector to re-create new value
	arr.clear();

	std::cout << "Random Array: ";
	//setting range of randomize
	for (int i = 0; i < N; i++) {
		//Recipe: rand() % (max_number + 1 - minimum_number) + minimum_number
		arr.push_back(rand() % (max_number + 1 - min_number) + min_number);
		//print recent value
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

/**
 * @name: printOdd
 * @param: arr: array of integers.
 * @briefly: Check Odd elements of arrays and Output.
 * @return: (none).
 */
void printOdd(std::vector<int> arr) {
	std::cout << "Odd elements of the array: ";
	for (int i = 0; i < arr.size(); i++) {
		//check Odd
		if (arr[i] % 2 == 1 || arr[i] * (-1) % 2 == 1) {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << std::endl;
}

/**
 * @name: printEven
 * @param: arr: array of integers.
 * @briefly: Check Even elements of arrays and Output.
 * @return: (none).
 */
void printEven(std::vector<int> arr) {
	std::cout << "Even elements of the array: ";
	for (int i = 0; i < arr.size(); i++) {
		//check Even
		if (arr[i] % 2 == 0 || arr[i] * (-1) % 2 == 0) {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << std::endl;
}

int main()
{
	//N: Number of elements to generate.
	//arr: Array to store generated elements.
	int N = 0;
	std::vector<int> arr;
	std::cout << "Enter Number to generate: ";
	std::cin >> N;
	//check invalid input
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "#Warn: Invalid input !! Please Re-enter: ";
		std::cin >> N;
	}

	generateRandomArray(arr, N, -20, 20);
	printOdd(arr);
	printEven(arr);
}