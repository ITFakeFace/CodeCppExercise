#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>
#include <string>

void printSolidTriangle(int N) {
    std::cout << std::endl << "Solid Triangle:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

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

void printReversedSolidTriangle(int N) {
    std::cout << std::endl << "Reversed Solid Triangle:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= N-i-1 || j == N-1 || i == N-1) {
                std::cout << "* ";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

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