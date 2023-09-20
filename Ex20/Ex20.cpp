#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>
#include <string>

int main()
{
    int N = 0;
    std::cout << "Enter Number to input: ";
    std::cin >> N;
    //check invalid input
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "#Warn: Invalid input !! Please Re-enter: ";
        std::cin >> N;
    }

    float numerator = 0, denominator = 0;
    for (int i = 1; i <= N; i++) {
        numerator += pow(i, i);
        denominator += pow(i, 1.0/i);
    }

    std::cout << "Result is " << std::fixed << std::setprecision(2) << numerator / denominator;
}