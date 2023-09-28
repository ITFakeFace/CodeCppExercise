//Ex 27 (20 score):
// Create .txt File that save 100 randomizing numbers, 
//						between 2 numbers has 1 blank space, 
//						10 numbers per row.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <random>
#include <time.h>
#include <fstream>

int main()
{
	//create link to file
	// *** Important: before run this program, please create a file name as "Ex27.txt"
	std::ofstream outputFile("Ex27.txt");

	//check file able to open (non-exist or problem to open)
	if (!outputFile.is_open()) {
		std::cout << "#Error: Cannot open File 'output.txt' !!" << std::endl;
		return -1;
	}

	//set limit of numbers to generate
	int min_number = 0,
		max_number = 100;

	//generate seeds
	srand((int)time(0));

	//generate number and write to file
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			outputFile << std::fixed << std::setw(4) << rand() % (max_number + 1 - min_number) + min_number;
		}
		outputFile << std::endl;
	}

	//close file
	outputFile.close();

	//open file by notepad to
	std::string result = "notepad.exe Ex27.txt";
	if (system(result.c_str()) == 0) {
		std::cout << "Successfully Open File." << std::endl;
	}
	else {
		std::cout << "#Error: Cannot Open File by Nodepad.exe." << std::endl;
	}


}