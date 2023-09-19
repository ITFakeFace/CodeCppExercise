#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

std::vector<int> generateRandomArray(int N, int min_number, int max_number) {
    std::vector<int> arr;
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
    return arr;
}

void printVector(std::vector<int> arr) {
    std::cout << "Elements of array: ";
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

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

void printEle(std::vector<int> arr) {
    std::cout << "Elemental elements of array: ";
    for (int i = 0; i < arr.size(); i++) {
        if (checkElementalNumber(arr[i])) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

/**
 * @name: checkSquareNumber
 * @param x: number to check
 * @briefly: Check parameter number is an square number or not.
 * @return true if parameter is square number
 *         false if parameter is not square number
 */
bool checkSquareNumber(int x) {
    if ((float)sqrt(x) - (int)sqrt(x) == 0) {
        return true;
    }
    return false;
}

void printSqr(std::vector<int> arr) {
    std::cout << "Square elements of array: ";
    for (int i = 0; i < arr.size(); i++) {
        if (checkSquareNumber(arr[i])) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortVector(std::vector<int> arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    printVector(arr);
}

void callMenu(int &N, std::vector<int> &arr) {
    int choice;
    do {
        std::cout << "---Menu------------------------------------" << std::endl;
        std::cout << "| 1. Enter N and Automatically Generate Arr[N]" << std::endl;
        std::cout << "| 2. Print all elements of Arr" << std::endl;
        std::cout << "| 3. Print all Elemental elements of Arr" << std::endl;
        std::cout << "| 4. Print all Square elements of Arr" << std::endl;
        std::cout << "| 5. Sort Arr by ASC" << std::endl;
        std::cout << "| 0. Exit Program" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        //check invalid input
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "#Warn: Invalid input !! Please Re-enter: ";
            std::cin >> choice;
        }
        switch (choice) {
            case 1:
                std::cout << "Enter Number to generate: ";
                std::cin >> N;
                //check invalid input
                while (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "#Warn: Invalid input !! Please Re-enter: ";
                    std::cin >> N;
                }
                arr = generateRandomArray(N, 1, 100);
                break;
            case 2:
                printVector(arr);
                break;
            case 3:
                printEle(arr);
                break;
            case 4:
                printSqr(arr);
                break;
            case 5:
                sortVector(arr);
                break;
            case 0:
                std::cout << "You're Out";
                break;
            default:
                std::cout << "#Warn: Invalid Choice !! Please Re-enter !! " << std::endl;
                break;
        }
    } while (choice != 0);
}
int main()
{
    int N = 0;
    std::vector<int> arr;
    
    callMenu(N, arr);
}