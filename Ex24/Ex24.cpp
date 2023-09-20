#include <iostream>

void printImage(int N) {
	std::cout << std::endl << "Image:" << std::endl;
	int width = N * 2 - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= width; j++) {
			if (i == 0 || j == 1 || j == width || j == N - i || j == N + i) {
				std::cout << "* ";
			}
			else {
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

int main()
{
	int N = 0;
	std::cout << "Enter Height to print: ";
	std::cin >> N;
	//check invalid input
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "#Warn: Invalid input !! Please Re-enter: ";
		std::cin >> N;
	}

	printImage(N);
}