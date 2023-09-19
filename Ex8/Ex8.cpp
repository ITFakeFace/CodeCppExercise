#include <iostream>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>

/**
 * @name: calcSumOfGeneratingArray
 * @param: N: Size of array to generate
 * @briefly: Generate an Array and print it into console and return sum of this array
 * @return: Sum of generated array
 */
float calcSumOfGeneratingArray(int N) {
    float sum=0, recent = 0;
    //setting range of randomize
    int min_number = 0, max_number = 100, pointDecimal = 1;
    for (int i = 0; i < N; i++) {
        //Recipe: (rand() % (max_number + 1 - minimum_number) + minimum_number)/10^pointDecimal
        recent = (rand() % (max_number + 1 - min_number) + min_number) / pow(10, pointDecimal);
        //print recent value
        std::cout << recent << " ";
        sum += recent;
    }
    std::cout << " = " << std::fixed << std::setprecision(2) << sum << std::endl;
    return sum;
}

/**
 * @name: calcSumMax
 * @param: N: Size of array to generate, times: number of array(s) to print
 * @briefly: Generate amount of Arrays,print it into console and return largest sum of arrays
 * @return: Largest Sum of generated arrays
 */
float calcSumMax(int N, int times) {
    std::cout << "Times A"<< ": ";
    float sumMax = calcSumOfGeneratingArray(N);
    float recentSum;
    for (int i = 1; i < times; i++) {
        std::cout << "Times " << (char)('A' + i) << ": ";
        recentSum = calcSumOfGeneratingArray(N);
        if (recentSum > sumMax) {
            sumMax = recentSum;
        }
    }
    return sumMax;
}

int main()
{
    //N: Number of array of random value from 0 to 50
    //recent: Random number in recent.
    //sumRecent: Summerize of all randomized number.
    //maxSum
    int N = 0, times = 0;
    float recent = 0, sumRecent = 0, maxSum = 0;;
    std::cout << "Enter Number to generate: ";
    std::cin >> N;
    //check invalid input
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "#Warn: Invalid input !! Please Re-enter: ";
        std::cin >> N;
    }
    
    std::cout << "Enter Times to generate: ";
    std::cin >> times;
    //check invalid input
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "#Warn: Invalid input !! Please Re-enter: ";
        std::cin >> N;
    }

    //generate seed
    srand((int)time(0));
    
    maxSum = calcSumMax(N, times);
    std::cout << "Largest Sum is " << maxSum;
}