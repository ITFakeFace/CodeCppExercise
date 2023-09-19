#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

int main()
{
    int before = 0, recent = 1, after = before+recent;
    int N;
    std::cout << "Enter Number to generate: ";
    std::cin >> N;
    //check invalid input
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "#Warn: Invalid input !! Please Re-enter: ";
        std::cin >> N;
    }

    std::cout << "Fibonacci:";
    for (int i = 0; i < N; i++) {
        std::cout << " " << recent;
        before = recent;
        recent = after;
        after = before + recent;
    }
}