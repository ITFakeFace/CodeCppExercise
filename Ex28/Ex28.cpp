//Ex 28 (30 score):
// Read integers from 1 file
// Write all prime numbers of input file's numbers to output file (another file)

#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <cstdlib>
#include <string>
#include <iomanip>

/**
 * @name: checkPrimeNumber
 * @param x: number to check
 * @briefly: Check parameter number is an prime number or not.
 * @return true if parameter is prime number
 *         false if parameter is not prime number
 */
bool checkPrimeNumber(int x) {
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
	//create link to file
	// *** Important: before run this program,
	//  please create a file name as "Ex28_Inp.txt" and input necessary data (integers)
	//  please create a file name as "Ex28_Out.txt"
	std::ifstream inputFile("Ex28_Inp.txt");
	std::ofstream outputFile("Ex28_Out.txt");

	//check File Existed
	if (!inputFile.is_open()) {
		std::cout << "#Error: Cannot open File 'output.txt' !!" << std::endl;
		return -1;
	}
	if (!outputFile.is_open()) {
		std::cout << "#Error: Cannot open File 'output.txt' !!" << std::endl;
		return -1;
	}

	//num: temporary number reads from file
	int num;
	//read number from file until end of file (over of numbers)
	while (inputFile >> num) {
		if (checkPrimeNumber(num)) {
			outputFile << num << " ";
		}
	}

	//close file()
	inputFile.close();
	outputFile.close();

	//Open Input File Command
	std::string begin = "notepad.exe Ex28_Inp.txt";
	if (system(begin.c_str()) == 0) {
		std::cout << "Successfully Open Input File." << std::endl;
	}
	else {
		std::cout << "#Error: Cannot Open File by Nodepad.exe." << std::endl;
	}

	//Open Output File Command
	std::string result = "notepad \Ex28_Out\"";
	if (system(result.c_str()) == 0) {
		std::cout << "Successfully Open Output File." << std::endl;
	}
	else {
		std::cout << "#Error: Cannot Open File by Nodepad.exe." << std::endl;
	}
}