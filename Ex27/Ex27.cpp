#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
#include <cstdlib>
#include <string>
#include <iomanip>

int main()
{
	std::ofstream outputFile("Ex27.txt");

	if (!outputFile.is_open()) {
		std::cout << "#Error: Cannot open File 'output.txt' !!" << std::endl;
		return -1;
	}

	int min_number = 0,
		max_number = 100;

	srand((int)time(0));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			outputFile << std::fixed << std::setw(4) << rand() % (max_number + 1 - min_number) + min_number;
		}
		outputFile << std::endl;
	}

	outputFile.close();

	std::string result = "notepad.exe Ex27.txt";
	if (system(result.c_str()) == 0) {
		std::cout << "Successfully Open File." << std::endl;
	}
	else {
		std::cout << "#Error: Cannot Open File by Nodepad.exe." << std::endl;
	}


}