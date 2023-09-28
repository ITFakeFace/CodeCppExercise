#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

typedef struct Book
{
	char code[10];
	char name[100];
	int quantity;
};

void callMenu(std::vector<Book>& bookList) {
	int choice;
	do {
		std::cout << "---Menu-----------------------------------------" << std::endl;
		std::cout << "| 1. Add New Book" << std::endl;
		std::cout << "| 2. Print List of Books" << std::endl;
		std::cout << "| 3. Find Books by Name" << std::endl;
		std::cout << "| 4. Delete Book" << std::endl;
		std::cout << "| 5. Update Book's Information" << std::endl;
		std::cout << "| 6. See Output File" << std::endl;
		std::cout << "| 0. Exit Program" << std::endl;
		std::cout << "------------------------------------------------" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		//check invalid input
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "#Warn: Invalid input !! Please Re-enter: ";
			std::cin >> choice;
		}
		switch (choice) {
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

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

}