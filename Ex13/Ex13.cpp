#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

/**
 * @name: checkElementalNumber
 * @param x: number to check
 * @briefly: Check parameter number is an elemental number or not.
 * @return true if parameter is elemental number
 *         false if parameter is not elemental number
 */
bool checkElementalNumber(int x) {
    if (x > 2) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    else {
        if (x == 2) {
            return true;
        }
    }
    return false;
}
int main()
{
    int N = 0;
    std::cout << "Enter Number to generate: ";
    std::cin >> N;
    //check invalid input
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "#Warn: Invalid input !! Please Re-enter: ";
        std::cin >> N;
    }

    std::cout << "Elemental Number: ";
    for (int i = 2;; i++) {
        if (N > 0) {
            if (checkElementalNumber(i)) {
                std::cout << " " << i;
                N--;
            }
        }
        else {
            break;
        }
    }
}