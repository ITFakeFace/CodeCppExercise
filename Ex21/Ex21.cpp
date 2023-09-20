#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>
#include <string>

void printSolidSquare(int N) {
    std::cout << std::endl << "Solid Square:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

void printEmptySquare(int N) {
    std::cout << std::endl << "Empty Square:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N - 1 || j == 0 | j == N - 1) {
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
    std::cout << "Enter Width to print: ";
    std::cin >> N;
    //check invalid input
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "#Warn: Invalid input !! Please Re-enter: ";
        std::cin >> N;
    }

    printSolidSquare(N);
    printEmptySquare(N);
}