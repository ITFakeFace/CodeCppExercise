//Ex 26 (20 score):
// Enter height of shape
// Draw shape:
// Example: N=7
//     * * * * * * *
//       *       *
//         *   *
//           *
//         *   *
//       *       *
//     * * * * * * * 

#include <iostream>
#include <math.h>

/**
 * @name: printImage
 * @param: N: length of edge.
 * @briefly: print specify shape.
 * @return: (none).
 */
void printImage(int N) {
	std::cout << std::endl << "Image:" << std::endl;
	int height = N * 2 - 1;
	int middle = div(N, 2).quot + 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == 1 || i == N || j == i || j == N - i + 1) {
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
	//N: Size of shape
	int N = 0;
	std::cout << "Enter Size to print: ";
	std::cin >> N;
	//check invalid input
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "#Warn: Invalid input !! Please Re-enter: ";
		std::cin >> N;
	}

	printImage(N);
}