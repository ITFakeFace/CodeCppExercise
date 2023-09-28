//Ex 16 (30 score):
// Create program which can execute following feature:
// 1. Enter N & automatically create randomizing array of N elements
// 2. Output all elements
// 3. Output all prime elements
// 4. Output all square elements
// 5. Sort array by ascending & output to screen
// 6. Exit program

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

/**
 * @name: generateRandomArray
 * @param: N: Number of necessary elements to generate,
 *		   min_number: smallest value of each elements,
 *		   max_number: largest value of each elements.
 * @briefly: Generate array with randomized value.
 * @return: Generated Array with values.
 */
std::vector<int> generateRandomArray(int N, int min_number, int max_number) {
	std::vector<int> arr;
	//generate seed
	srand((int)time(0));

	std::cout << "Random Array: ";
	//setting range of randomize
	for (int i = 0; i < N; i++) {
		//Recipe: rand() % (max_number + 1 - minimum_number) + minimum_number
		arr.push_back(rand() % (max_number + 1 - min_number) + min_number);
		//print recent value
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return arr;
}

/**
 * @name: printVector
 * @param: arr: vector to print
 * @briefly: Print inputed vector.
 * @return: (none).
 */
void printVector(std::vector<int> arr) {
	std::cout << "Primements of array: ";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

/**
 * @name: checkPrimeNumber
 * @param x: number to check
 * @briefly: Check parameter number is a prime number or not.
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

/**
 * @name: printPrime
 * @param x: Arrays of integer to check and print
 * @briefly: Check parameter number is a prime number and print it if true.
 * @return: (none).
 */
void printPrime(std::vector<int> arr) {
	std::cout << "Prime elements of array: ";
	for (int i = 0; i < arr.size(); i++) {
		if (checkPrimeNumber(arr[i])) {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << std::endl;
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

/**
 * @name: printSqr
 * @param x: Arrays of integer to check and print
 * @briefly: Check parameter number is a square number and print it if true.
 * @return: (none).
 */
void printSqr(std::vector<int> arr) {
	std::cout << "Square elements of array: ";
	for (int i = 0; i < arr.size(); i++) {
		if (checkSquareNumber(arr[i])) {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << std::endl;
}

/**
 * @name: swap
 * @param: a: number 1,
 *		   b: number 2.
 * @briefly: swap value of number 1 & number 2 (params a and b).
 * @return: (none).
 */
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

/**
 * @name: sortVector
 * @param: arr: arrays to sort
 * @briefly: Sort arrays by Value order by ASC (Ascending).
 * @return: (none).
 */
void sortVector(std::vector<int> arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
	printVector(arr);
}

/**
 * @name: callMenu
 * @param: N: number of elements
 *		   arr: arrays of elements
 * @briefly: Call menu that is able for user to choose selection of following menu commands.
 * @return: (none).
 */
void callMenu(int& N, std::vector<int>& arr) {
	//choice: choice of user to terminate
	int choice;
	do {
		std::cout << "---Menu------------------------------------" << std::endl;
		std::cout << "| 1. Enter N and Automatically Generate Arr[N]" << std::endl;
		std::cout << "| 2. Print all elements of Arr" << std::endl;
		std::cout << "| 3. Print all Prime elements of Arr" << std::endl;
		std::cout << "| 4. Print all Square elements of Arr" << std::endl;
		std::cout << "| 5. Sort Arr by ASC" << std::endl;
		std::cout << "| 0. Exit Program" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		//check invalid input
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "#Warn: Invalid input !! Please Re-enter: ";
			std::cin >> choice;
		}
		switch (choice) {
			case 1:
				std::cout << "Enter Number to generate: ";
				std::cin >> N;
				//check invalid input
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					std::cout << "#Warn: Invalid input !! Please Re-enter: ";
					std::cin >> N;
				}
				arr = generateRandomArray(N, 1, 100);
				break;
			case 2:
				printVector(arr);
				break;
			case 3:
				printPrime(arr);
				break;
			case 4:
				printSqr(arr);
				break;
			case 5:
				sortVector(arr);
				break;
			case 0:
				std::cout << "You're Out";
				break;
			default:
				std::cout << "#Warn: Invalid Choice !! Please Re-enter !! " << std::endl;
				break;
		}
	} while (choice != 0);
}
int main()
{
	//Create variable to use
	int N = 0;
	std::vector<int> arr;

	callMenu(N, arr);
}