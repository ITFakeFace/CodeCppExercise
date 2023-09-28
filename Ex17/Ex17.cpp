//Ex 17 (30 score):
// Create program which can execute following feature:
// 1. Enter N (rows) & M (columns), automatically create randomizing matrix (2D array) of N elements
// 2. Output matrix
// 3. Output sum of all elements of matrix
// 4. Output sum of all elements of matrix which is in edge of 
// 5. Find columns which has largest value of sum of its elements
// 6. Find rows which has largest value of sum of its elements
// 7. Exit Program

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

/**
 * @name: generateRandomArray
 * @param: N: Number of rows of matrix to generate,
 *         M: Number of columns of matrix to generate,
 *		   min_number: smallest value of each elements,
 *		   max_number: largest value of each elements.
 * @briefly: Generate array with randomized value.
 * @return: Generated Array with values.
 */
std::vector<std::vector<int>> generateRandomArray(int N, int M, int min_number, int max_number) {
	//arr: necessary matrix (2D) to return value
	//tempArr: necessary array (1D) to contains temporary value to add into matrix
	std::vector<std::vector<int>> arr;
	std::vector<int> tempArr;
	//generate seed
	srand((int)time(0));
	//setting range of randomize
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//Recipe: rand() % (max_number + 1 - minimum_number) + minimum_number
			tempArr.push_back(rand() % (max_number + 1 - min_number) + min_number);
			//print recent value
		}
		arr.push_back(tempArr);
		tempArr.clear();
	}
	std::cout << "#Status: Done !!";
	std::cout << std::endl;
	return arr;
}

/**
 * @name: printVector
 * @param: arr: matrix to print
 * @briefly: Print inputed vector.
 * @return: (none).
 */
void printMatrix(std::vector<std::vector<int>> arr) {
	std::cout << "Matrix: " << std::endl;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			std::cout << std::setw(4) << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * @name: findSumOfAllEle
 * @param: arr: matrix to calculate.
 * @briefly: Calculate sum of all elements of matrix and Print result.
 * @return: (none).
 */
void findSumOfAllEle(std::vector<std::vector<int>> arr) {
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.at(i).size(); j++) {
			sum += arr[i][j];
		}
	}
	std::cout << "Sum of All Matrix's Elements is " << sum << std::endl;
}

/**
 * @name: findSumOfAllEle
 * @param: arr: matrix to calculate.
 * @briefly: Calculate sum of all elements that is on the border of matrix and Print result.
 * @return: (none).
 */
void findSumOfAllBorderEle(std::vector<std::vector<int>> arr) {
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i][0] + arr[i][arr[i].size() - 1];
	}
	for (int j = 0; j < arr.at(1).size(); j++) {
		sum += arr[0][j] + arr[arr.size() - 1][j];
	}
	sum -= arr[0][0] + arr[0][arr.at(arr.size() - 1).size() - 1] + arr[arr.size() - 1][0] + arr[arr.size() - 1][arr.at(arr.size() - 1).size() - 1];
	std::cout << "Sum of All Matrix's Border Elements is " << sum << std::endl;
}

/**
 * @name: findMaxColumn
 * @param: arr: matrix to calculate.
 * @briefly: Find a column that has sum all of its elements is the largest and Print result.
 * @return: (none).
 */
void findMaxColumn(std::vector<std::vector<int>> arr) {
	//max: largest value at recent
	//maxLoc: max Location
	//sum: sum of recent column
	int max = -1, maxLoc = -1, sum = 0;
	for (int j = 0; j < arr.at(0).size(); j++) {
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i][j];
		}
		if (max == -1 || max < sum) {
			max = sum;
			maxLoc = j + 1;
		}
		sum = 0;
	}
	std::cout << "Column with largest sum is " << maxLoc << " with the value is " << max << std::endl;
}

/**
 * @name: findMaxRow
 * @param: arr: matrix to calculate.
 * @briefly: Find a row that has sum all of its elements is the largest and Print result.
 * @return: (none).
 */
void findMaxRow(std::vector<std::vector<int>> arr) {
	//max: largest value at recent
	//maxLoc: max Location
	//sum: sum of recent row
	int max = -1, maxLoc = -1, sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.at(i).size(); j++) {
			sum += arr[i][j];
		}
		if (max == -1 || max < sum) {
			max = sum;
			maxLoc = i + 1;
		}
		sum = 0;
	}
	std::cout << "Row with largest sum is " << maxLoc << " with the value is " << max << std::endl;;
}

/**
 * @name: callMenu
 * @param: N: Number of rows of matrix,
 *         M: Number of columns of matrix,
 *		   arr: arrays of elements
 * @briefly: Call menu that is able for user to choose selection of following menu commands.
 * @return: (none).
 */
void callMenu(int& N, int& M, std::vector<std::vector<int>>& arr) {
	//choice: choice of user to terminate
	int choice;
	do {
		std::cout << "---Menu------------------------------------" << std::endl;
		std::cout << "| 1. Enter N, M and Automatically Generate Arr[N][M]" << std::endl;
		std::cout << "| 2. Print Matrix" << std::endl;
		std::cout << "| 3. Find Sum of all Matrix's elements" << std::endl;
		std::cout << "| 4. Find Sum of all Matrix's border elements" << std::endl;
		std::cout << "| 5. Find Max Sum of Columns" << std::endl;
		std::cout << "| 6. Find Max Sum of Rows" << std::endl;
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
				std::cout << "Enter Number of Row(s): ";
				std::cin >> N;
				//check invalid input
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					std::cout << "#Warn: Invalid input !! Please Re-enter: ";
					std::cin >> N;
				}

				std::cout << "Enter Number of Column(s): ";
				std::cin >> M;
				//check invalid input
				while (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore();
					std::cout << "#Warn: Invalid input !! Please Re-enter: ";
					std::cin >> M;
				}

				arr = generateRandomArray(N, M, 0, 100);
				break;
			case 2:
				printMatrix(arr);
				break;
			case 3:
				findSumOfAllEle(arr);
				break;
			case 4:
				findSumOfAllBorderEle(arr);
				break;
			case 5:
				findMaxColumn(arr);
				break;
			case 6:
				findMaxRow(arr);
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
	// N: rows, M: columns
	int N = 0, M = 0;
	std::vector<std::vector<int>> arr;

	callMenu(N, M, arr);
}