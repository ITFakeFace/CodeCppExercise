#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <cstdlib>
#include <string>
#include <iomanip>

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

	int num;
	while (inputFile >> num) {
		if (checkElementalNumber(num)) {
			outputFile << num << " ";
		}
	}

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