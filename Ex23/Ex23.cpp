//Ex 23 (20 score):
// Enter height of triangle
// Draw triangle:
// Example: N=5
//           *                     *
//         * * *                 *   *
//       * * * * *      &      *       *
//     * * * * * * *         *           *
//   * * * * * * * * *     * * * * * * * * *

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>
#include <string>

/**
 * @name: printSolidIsoscelesTriangle
 * @param: N: length of edge.
 * @briefly: print a solid isosceles triangle.
 * @return: (none).
 */
void printSolidIsoscelesTriangle(int N) {
	std::cout << std::endl << "Solid Isosceles Triangle:" << std::endl;
	int width = N * 2 - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < width; j++) {
			if ((j >= N - i - 1 && j <= N + i - 1) || i == N - 1) {
				std::cout << "* ";
			}
			else {
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

/**
 * @name: printEmptyIsoscelesTriangle
 * @param: N: length of edge.
 * @briefly: print a empty isosceles triangle.
 * @return: (none).
 */
void printEmptyIsoscelesTriangle(int N) {
	std::cout << std::endl << "Empty Isosceles Triangle:" << std::endl;
	int width = N * 2 - 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < width; j++) {
			if (j == N - i - 1 || j == N + i - 1 || i == N - 1) {
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
	//N: height of triangle
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

	printSolidIsoscelesTriangle(N);
	printEmptyIsoscelesTriangle(N);
}