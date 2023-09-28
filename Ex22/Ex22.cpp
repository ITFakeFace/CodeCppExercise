//Ex 22 (20 score):
// Enter height of triangle
// Draw triangle:
// Example: N=5
//        *             *                     *             *
//        * *           * *                 * *           * *
//        * * *      &  *   *      &      *   *  &      * * *
//        * * * *       *     *         *     *       * * * *
//        * * * * *     * * * * *     * * * * *     * * * * *

#include <iostream>
#include <limits>

/**
 * @name: printSolidTriangle
 * @param: N: length of edge.
 * @briefly: print a solid triangle.
 * @return: (none).
 */
void printSolidTriangle(int N) {
	std::cout << std::endl << "Solid Triangle:" << std::endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			std::cout << "* ";
		}
		std::cout << std::endl;
	}
}

/**
 * @name: printEmptyTriangle
 * @param: N: length of edge.
 * @briefly: print a empty triangle.
 * @return: (none).
 */
void printEmptyTriangle(int N) {
	std::cout << std::endl << "Empty Triangle:" << std::endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == 0 || i == N - 1 || j == 0 | j == i) {
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
 * @name: printReversedSolidTriangle
 * @param: N: length of edge.
 * @briefly: print a reversed solid triangle.
 * @return: (none).
 */
void printReversedSolidTriangle(int N) {
	std::cout << std::endl << "Reversed Solid Triangle:" << std::endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j >= N - i - 1 || j == N - 1 || i == N - 1) {
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
 * @name: printReversedEmptyTriangle
 * @param: N: length of edge.
 * @briefly: print a reversed empty triangle.
 * @return: (none).
 */
void printReversedEmptyTriangle(int N) {
	std::cout << std::endl << "Reversed Empty Triangle:" << std::endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == N - i - 1 || j == N - 1 || i == N - 1) {
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
	//N: height of Triangle
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

	printSolidTriangle(N);
	printEmptyTriangle(N);
	printReversedSolidTriangle(N);
	printReversedEmptyTriangle(N);
}