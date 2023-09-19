#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>

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
    
    int temp;
    for (int i = 0; i < N; i++) {
        std::cout << "Enter arr[" << i << "]: ";
        std::cin >> temp;
        //check invalid input
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "#Warn: Invalid input !! Please Re-enter: ";
            std::cin >> temp;
        }
        arr.push_back(temp);
    }

    int sum = 0;
    std::cout << "Elements of Array: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
        sum += arr[i];
    }
    std::cout << std::endl << "Sum of an array is " << sum;
}