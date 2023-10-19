#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>

//struct Book
typedef struct Book
{
	char code[11];
	char name[101];
	int quantity;
};

/**
 * @name: trim
 * @param: str: string to trim.
 * @briefly: Delete blank space before first word and after last word.
 * @return: String after Trimmed.
 */
std::string trim(std::string& str) {
	while (str[0] == ' ') {
		if (str[0] == ' ') {
			str.erase(str.begin(), str.begin() + 1);
		}
	}
	while (str[str.size() - 1] == ' ') {
		str.erase(str.end() - 1, str.end() + 0);
	}
	return str;
}

/**
 * @name: shortageBlank
 * @param: str: string to shortage.
 * @briefly: Delete unnecessary blank space between words.
 * @return: String after Shortaged.
 */
std::string shortageBlank(std::string& str) {
	str = trim(str);
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == ' ' && str[i + 1] == ' ') {
			str.erase(i, 1);
			i--;
		}
	}
	return str;
}

std::string ToLower(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}

void readFile(std::vector<Book>& bList) {
	std::ifstream inputFile("Ex30_data.dat");

	if (!inputFile.is_open()) {
		std::cout << "#Notification: Failed to open/create file" << std::endl;
		return;
	}

	std::string fileLine;
	std::vector<std::string> splitArray;
	std::string current;


	while (std::getline(inputFile, fileLine)) {

		std::stringstream fileStream(fileLine);

		while (std::getline(fileStream, current, '*')) {
			splitArray.push_back(current);
		}

		Book book;
		if (inputFile.fail()) {
			std::cerr << "#Warn: Failed to read data from the file." << std::endl;
			inputFile.close();
			return;
		}

		if (splitArray.size() == 3) {
			strcpy_s(book.code, splitArray[0].c_str());
			strcpy_s(book.name, splitArray[1].c_str());
			book.quantity = std::stoi(splitArray[2].c_str());
			bList.push_back(book);
		}
		else {
			std::cout << "#Warn: Invalid File's data format" << std::endl;
		}
		splitArray.clear();
	}
	std::cout << "#Notification: Successfully Readed from File !" << std::endl;
	inputFile.close();
}

void writeFile(std::vector<Book> bList) {
	std::ofstream outputFile;

	outputFile.open("Ex30_data.dat");
	if (!outputFile.is_open()) {
		std::cout << "#Notification: Failed to open/create file" << std::endl;
		return;
	}

	for (int i = 0; i < bList.size(); i++) {
		outputFile << bList[i].code << "*" << bList[i].name << "*" << bList[i].quantity << std::endl;
	}

	outputFile.close();
	std::cout << "#Status: Success saved !!" << std::endl;
}

void addBook(std::vector<Book>& bList) {
	Book book;
	bool isNotValid = true;

	std::cin.ignore();
	std::cout << "------------ Creating new Book ------------" << std::endl;

	do {
		std::cout << "Enter Book Code: ";
		std::cin.getline(book.code, 10);
		if (strlen(book.code) <= 0) {
			std::cout << "#Warn: Code cannot be null and must be different from '*'" << std::endl;
			continue;
		}
		else {
			//check blank & character '*'
			if (((std::string)book.code).find(' ') != -1) {
				std::cout << "#Warn: Code cannot contains blank" << std::endl;
				continue;
			}
			for (int i = 0; i < strlen(book.code); i++) {
				if (book.code[i] != '*') {
					isNotValid = false;
					break;
				}
			}
			if (isNotValid) {
				std::cout << "#Warn: Code cannot contain '*'" << std::endl;
				continue;
			}
		}
		for (int i = 0; i < bList.size(); i++) {
			if (strcmp(book.code, bList[i].code) == 0) {
				std::cout << "#Warn: Existed Code !! Please Re-enter !!" << std::endl;
				isNotValid = true;
			}
		}
		if (!isNotValid) {
			break;
		}
	} while (true);

	isNotValid = true;
	while (isNotValid) {
		std::cout << "Enter Book Name: ";
		std::cin.getline(book.name, 100);
		if (strlen(book.name) <= 0) {
			std::cout << "#Warn: Name cannot be null and must be different from '*'" << std::endl;
			continue;
		}
		else {
			//check blank & character '*'
			for (int i = 0; i < strlen(book.name); i++) {
				if (book.name[i] != ' ' && book.name[i] != '*') {
					isNotValid = false;
					break;
				}
			}
			if (isNotValid) {
				std::cout << "#Warn: Name cannot be null and must be different from '*'" << std::endl;
				continue;
			}
		}
		break;
	}

	while (true) {
		std::cout << "Enter Quantity: ";
		std::cin >> book.quantity;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "#Warn: Invalid Quantity !! Quantity must be an integer !! Please Re-enter: ";
			std::cin >> book.quantity;
		}
		if (book.quantity < 0) {
			std::cout << "#Warn: Invalid Quantity !! Quantity must be a positive number !! Please Re-enter !!" << std::endl;
			continue;
		}
		break;
	}

	bList.push_back(book);
	writeFile(bList);
}

void printList(std::vector<Book> bList) {
	std::cout << "------------------------------ List of Books ------------------------------" << std::endl;

	std::cout << "+ -No- + --Code---- + -----Name----------------------------------------- + Quantity +" << std::endl;
	for (int i = 0; i < bList.size(); i++) {
		std::cout << "+ " << std::setw(4) << std::right << (i + 1) << " + " << std::setw(10) << std::right << bList[i].code << " + " << std::setw(50) << std::left << bList[i].name << " + " << std::setw(8) << std::right << bList[i].quantity << " +" << std::endl;
	}
	std::cout << "+ ---- + ---------- + -------------------------------------------------- + -------- +" << std::endl;
}

void findByName(std::vector<Book> bList) {
	//search: string to search
	std::string search;

	std::cin.ignore();

	std::cout << "- Enter name to search: ";
	std::getline(std::cin, search);
	std::cout << "+ ---Code--- + -----Name----------------------------------------- + Quantity +" << std::endl;
	for (int i = 0; i < bList.size(); i++) {
		if (((std::string)bList[i].name).find(search) != -1) {
			std::cout << "+ " << std::setw(10) << std::right << bList[i].code << " + " << std::setw(50) << std::left << bList[i].name << " + " << std::setw(8) << std::right << bList[i].quantity << " +" << std::endl;
		}
	}
	std::cout << "+ ---------- + -------------------------------------------------- + -------- +" << std::endl;
}

void deleteBook(std::vector<Book>& bList) {
	//delCode: string to delete
	char delCode[10];

	std::vector<Book>::iterator i;
	std::cin.ignore();

	std::cout << "- Enter Code to delete: ";
	std::cin.getline(delCode, 10);

	for (i = bList.begin(); i != bList.end(); i++) {
		if (strcmp((*i).code, delCode) == 0) {
			bList.erase(i);
			std::cout << "#Notification: Deleted 1 Book !!" << std::endl;
			return;
		}
	}
	std::cout << "#Notification: Cannot find Book with ID " << delCode << " !!" << std::endl;
	writeFile(bList);
}

void updateBook(std::vector<Book>& bList) {
	//pos: position to update
	int pos;

	std::cin.ignore();

	printList(bList);

	do {
		std::cout << "- Enter Postition (No) to update: ";
		std::cin >> pos;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "#Warn: Invalid Position !! Position must be in range [1," << bList.size() << "] !! Please Re-enter: " << std::endl;
			std::cin >> pos;
		}
		if (pos > bList.size() || pos <= 0) {
			std::cout << "#Warn: Invalid Position !! Position must be in range [1," << bList.size() << "] !! Please Re-enter: " << std::endl;
			continue;
		}
		break;
	} while (true);

	Book bookTemp;
	bool isNotValid = true;

	std::cin.ignore();

	do {
		std::cout << "Enter Book Code (Old value = " << bList[pos - 1].code << "): ";
		std::cin.getline(bookTemp.code, 10);
		if (strlen(bookTemp.code) <= 0) {
			strcpy_s(bookTemp.code, bList[pos - 1].code);
			break;
		}
		else {
			//check blank & character '*'
			if (((std::string)bookTemp.code).find(' ') != -1) {
				std::cout << "#Warn: Code cannot contains blank" << std::endl;
				continue;
			}
			for (int i = 0; i < strlen(bookTemp.code); i++) {
				if (bookTemp.code[i] != '*') {
					isNotValid = false;
					break;
				}
			}
			if (isNotValid) {
				std::cout << "#Warn: Code cannot contain '*'" << std::endl;
				continue;
			}
		}
		for (int i = 0; i < bList.size(); i++) {
			if (strcmp(bookTemp.code, bList[i].code) == 0 && i != pos - 1) {
				std::cout << "#Warn: Existed Code !! Please Re-enter !!" << std::endl;
				isNotValid = true;
			}
		}
		if (!isNotValid) {
			break;
		}
	} while (true);

	isNotValid = true;
	while (isNotValid) {
		std::cout << "Enter Book Name (Old value = " << bList[pos - 1].name << "): ";
		std::cin.getline(bookTemp.name, 100);
		if (strlen(bookTemp.name) <= 0) {
			strcpy_s(bookTemp.name, bList[pos - 1].name);
			break;
		}
		else {
			//check blank & character '*'
			for (int i = 0; i < strlen(bookTemp.name); i++) {
				if (bookTemp.name[i] != ' ' && bookTemp.name[i] != '*') {
					isNotValid = false;
					break;
				}
			}
			if (isNotValid) {
				std::cout << "#Warn: Name cannot be null and must be different from '*'" << std::endl;
				continue;
			}
		}
		break;
	}

	isNotValid = true;
	std::string temp;
	while (isNotValid) {
		try
		{
			std::cout << "Enter Quantity (Old value = " << bList[pos - 1].quantity << "): ";
			std::cin >> temp;
			if (temp.length() <= 0) {
				bookTemp.quantity = bList[pos - 1].quantity;
				isNotValid = false;
				break;
			}
			bookTemp.quantity = std::stoi(temp.c_str());
			if (bookTemp.quantity < 0) {
				std::cout << "#Warn: Invalid Quantity !! Quantity must be a positive number !! Please Re-enter !!" << std::endl;
				continue;
			}
		}
		catch (const std::invalid_argument& excp)
		{
			std::cout << "INVALID INPUT: " << excp.what() << std::endl;
			continue;
		}
		catch (const std::out_of_range& excp)
		{
			std::cout << "INVALID INPUT: " << excp.what() << std::endl;
			continue;
		}
		break;
	}

	bList[pos - 1] = bookTemp;
	std::cout << "#Notification: Successfully updated !!" << std::endl;
	writeFile(bList);
}

void callMenu(std::vector<Book>& bList) {
	int choice;
	std::string result = "notepad.exe Ex30_data.dat";
	do {
		fflush(stdin);

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
				addBook(bList);
				break;
			case 2:
				printList(bList);
				break;
			case 3:
				findByName(bList);
				break;
			case 4:
				deleteBook(bList);
				break;
			case 5:
				updateBook(bList);
				break;
			case 6:
				//open file by notepad to "Ex30_data.dat"

				if (system(result.c_str()) == 0) {
					std::cout << "Successfully Open File." << std::endl;
				}
				else {
					std::cout << "#Error: Cannot Open File by Nodepad.exe." << std::endl;
				}
				break;
			case 0:
				std::cout << "You're Out";
				break;
			default:
				std::cout << "#Warn: Invalid Choice !! Please Re-enter !! " << std::endl;
				break;
		}
		if (choice != 0) {
			std::cout << "#Notification: Press Enter to continue !" << std::endl;
			std::cin.ignore();
			std::cin.get();
			std::cout << "\033[2J\033[1;1H";
		}
	} while (choice != 0);
}

int main()
{
	std::vector<Book> bList;

	readFile(bList);

	callMenu(bList);
}