//Ex 12 (10 score):
// Enter N
// Output Fibonacci from 1st elements to Nth element.

#include <iostream>

int main()
{
	//before: a(n-1)th number of fibonacci
	//recent: a(n)th number of fibonacci
	//after: a(n+1)th number of fibonacci
	int before = 0, recent = 1, after = before + recent;
	int N;
	std::cout << "Enter Number to generate: ";
	std::cin >> N;
	//check invalid input
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "#Warn: Invalid input !! Please Re-enter: ";
		std::cin >> N;
	}

	//Processing and Print a(n)th fibonacci
	std::cout << "Fibonacci:";
	for (int i = 0; i < N; i++) {
		std::cout << " " << recent;
		before = recent;
		recent = after;
		after = before + recent;
	}
}