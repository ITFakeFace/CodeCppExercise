#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

void generateRandomArray(std::vector<int> &arr, int N, int min_number, int max_number) {
    //generate seed
    srand((int)time(0));

    std::cout << "Random Array: ";
    //setting range of randomize
    for (int i = 0; i < N; i++) {
        //Recipe: rand() % (max_number + 1 - minimum_number) + minimum_number
        arr.push_back(rand() % (max_number + 1 - min_number) + min_number);
        //print recent value
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printOdd(std::vector<int> arr) {
    std::cout << "Odd elements of the array: ";
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 1 || arr[i] * (-1) % 2 == 1) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

void printEven(std::vector<int> arr) {
    std::cout << "Even elements of the array: ";
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0 || arr[i] * (-1) % 2 == 0) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int N = 0;
    std::vector<int> arr;
    std::cout << "Enter Number to input: ";
    std::cin >> N;
    //check invalid input
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "#Warn: Invalid input !! Please Re-enter: ";
        std::cin >> N;
    }

    generateRandomArray(arr, N, -20, 20);
    printOdd(arr);
    printEven(arr);
}