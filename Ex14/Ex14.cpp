//Ex 14 (10 score):
// Enter number of elements, then enter each value
// Output array.

#include <iostream>
#include <vector>
#include <limits>

int main()
{
	//N: Number of array's elements.
	//arr: Array to store inputed elements.
	int N = 0;
	std::vector<int> arr;
	std::cout << "Enter Number to input: ";
	std::cin >> N;
	//check invalid input
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "#Warn: Invalid input !! Please Re-enter: ";
		std::cin >> N;
	}

	//temp: a temporary variable to check input before add to array
	int temp;
	for (int i = 0; i < N; i++) {
		std::cout << "Enter arr[" << i << "]: ";
		std::cin >> temp;
		//check invalid input
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "#Warn: Invalid input !! Please Re-enter: ";
			std::cin >> temp;
		}
		arr.push_back(temp);
	}

	//Calculate and Output sum
	int sum = 0;
	std::cout << "Elements of Array: ";
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
		sum += arr[i];
	}
	std::cout << std::endl << "Sum of an array is " << sum;
}