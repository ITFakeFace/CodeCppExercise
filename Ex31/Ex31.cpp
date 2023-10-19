#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <sstream> //stringstream
#include <tabulate/table.hpp>

//struct Book
typedef struct Book
{
	char code[11];
	char name[101];
	int quantity;
};

//struct Node
typedef struct Node {
	Node* pNext;
	Book Value;
};

typedef struct LinkedList {
	Node* pStart;
};

void initializeLinkedList(LinkedList& list) {
	list.pStart = NULL;
}

Node* createNode(Book book) {
	Node* node = new Node;
	if (node != NULL) {
		node->pNext = NULL;
		node->Value = book;
		return node;
	}
	return NULL;
}

void writeFile(LinkedList bList) {
	std::ofstream outputFile;

	outputFile.open("Ex31_data.dat");
	if (!outputFile.is_open()) {
		std::cout << "#Notification: Failed to open/create file" << std::endl;
		return;
	}

	for (Node* node = bList.pStart; node != NULL; node = node->pNext) {
		outputFile << node->Value.code << "*" << node->Value.name << "*" << node->Value.quantity << std::endl;
	}

	outputFile.close();
	std::cout << "#Status: Success saved !!" << std::endl;
}

Book searchBook(LinkedList& bList, std::string bCode, Node*& preNode, Node*& currentNode) {
	if (strcmp(bCode.c_str(), bList.pStart->Value.code) == 0) {
		preNode = NULL;
		currentNode = bList.pStart;
	}
	else if (bList.pStart->pNext != NULL) {
		for (Node* node = bList.pStart; node->pNext != NULL; node = node->pNext) {
			if (strcmp(bCode.c_str(), node->pNext->Value.code) == 0) {
				preNode = node;
				currentNode = node->pNext;
				break;
			}
		}
	}
	return currentNode->Value;
}

bool deleteNode(LinkedList& bList, std::string delCode)
{
	Node* preNode = NULL;
	Node* currentNode = NULL;

	searchBook(bList, delCode, preNode, currentNode);

	if (preNode == NULL) {
		if (currentNode == bList.pStart && currentNode->pNext != NULL) {
			bList.pStart = currentNode->pNext;
		}
		else {
			bList.pStart = NULL;
		}
	}
	else {
		if (currentNode != NULL) {
			if (currentNode->pNext == NULL) {
				preNode->pNext = NULL;
			}
			else {
				preNode->pNext = currentNode->pNext;
			}
		}
		else {
			std::cout << "#Warn: Cannot find Book with ID '" << delCode << "'" << std::endl;
			return false;
		}
	}

	delete(currentNode);
	return true;
}

Book createBook(LinkedList bList) {
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
		for (Node* node = bList.pStart; node != NULL; node = node->pNext) {
			if (strcmp(book.code, node->Value.code) == 0) {
				std::cout << "#Warn: Existed Code !! Please Re-enter !!" << std::endl;
				isNotValid = true;
				break;
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
	return book;
}

bool addBook(LinkedList& bList) {
	Book book = createBook(bList);
	Node* node = createNode(book);

	if (node == NULL) {
		return false;
	}
	if (bList.pStart == NULL) {
		bList.pStart = node;
	}
	else {
		node->pNext = bList.pStart;
		bList.pStart = node;
	}
	writeFile(bList);
	return true;
}

bool addBookFromFile(LinkedList& bList, Book book) {
	Node* node = createNode(book);

	if (node == NULL) {
		return false;
	}
	if (bList.pStart == NULL) {
		bList.pStart = node;
	}
	else {
		node->pNext = bList.pStart;
		bList.pStart = node;
	}
	return true;
}

void printBook(Book book) {
	std::cout << "+ " << std::setw(10) << std::right << book.code << " + " << std::setw(50) << std::left << book.name << " + " << std::setw(8) << std::right << book.quantity << " +" << std::endl;
}

void printList(LinkedList bList) {
	std::cout << "------------------------------ List of Books ------------------------------" << std::endl;

	std::cout << "+ ---Code--- + -----Name----------------------------------------- + Quantity +" << std::endl;
	for (Node* node = bList.pStart; node != NULL; node = node->pNext) {
		printBook(node->Value);
	}
	std::cout << "+ ---------- + -------------------------------------------------- + -------- +" << std::endl;
}

void findBook(LinkedList bList) {
	//search: string to search
	std::string search;

	std::cin.ignore();

	std::cout << "- Enter name to search: ";
	std::getline(std::cin, search);
	std::cout << "+ ---Code--- + -----Name----------------------------------------- + Quantity +" << std::endl;
	for (Node* node = bList.pStart; node != NULL; node = node->pNext) {
		if (((std::string)node->Value.name).find(search) != -1) {
			printBook(node->Value);
		}
	}
	std::cout << "+ ---------- + -------------------------------------------------- + -------- +" << std::endl;
}

void deleteBook(LinkedList& bList) {
	printList(bList);
	//delCode: string to delete
	std::string delCode;
	std::cin.ignore();

	std::cout << "- Enter Code to delete: ";
	std::getline(std::cin, delCode);
	if (deleteNode(bList, delCode)) {
		std::cout << "#Status: Successfully delete 1 Book !!" << std::endl;
	}
	else {
		std::cout << "#Status: failed to delete Book !!" << std::endl;
	}
	writeFile(bList);
}

void updateBook(LinkedList& bList) {
	Node* preNode = NULL;
	Node* currentNode = NULL;

	printList(bList);
	//updateCode: string to update
	std::string updateCode;
	std::cin.ignore();

	std::cout << "- Enter Code to update: ";
	std::getline(std::cin, updateCode);

	Book oldBook = searchBook(bList, updateCode, preNode, currentNode);
	Book bookTemp;
	bool isNotValid = true;

	do {
		std::cout << "Enter Book Code (Old value = " << oldBook.code << "): ";
		std::cin.getline(bookTemp.code, 10);
		if (strlen(bookTemp.code) <= 0) {
			strcpy_s(bookTemp.code, oldBook.code);
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
		for (Node* node = bList.pStart; node != NULL; node = node->pNext) {
			if (strcmp(bookTemp.code, node->Value.code) == 0) {
				std::cout << "#Warn: Existed Code !! Please Re-enter !!" << std::endl;
				isNotValid = true;
				break;
			}
		}
		if (!isNotValid) {
			break;
		}
	} while (true);

	isNotValid = true;
	while (isNotValid) {
		std::cout << "Enter Book Name (Old value = " << oldBook.name << "): ";
		std::cin.getline(bookTemp.name, 100);
		if (strlen(bookTemp.name) <= 0) {
			strcpy_s(bookTemp.name, oldBook.name);
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
			std::cout << "Enter Quantity (Old value = " << oldBook.quantity << "): ";
			std::cin >> temp;
			if (temp.length() <= 0) {
				bookTemp.quantity = oldBook.quantity;
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

	currentNode->Value = bookTemp;
	std::cout << "#Notification: Successfully updated Book !!" << std::endl;
	writeFile(bList);
}

void readFile(LinkedList& bList) {
	std::ifstream inputFile("Ex31_data.dat");

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
			addBookFromFile(bList, book);
		}
		else {
			std::cout << "#Warn: Invalid File's data format" << std::endl;
		}
		splitArray.clear();
	}
	std::cout << "#Notification: Successfully Readed from File !" << std::endl;
	inputFile.close();
}

void callMenu(LinkedList& bList) {
	int choice;
	std::string result = "notepad.exe Ex31_data.dat";
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
				std::cin.get();
				break;
			case 3:
				findBook(bList);
				break;
			case 4:
				deleteBook(bList);
				break;
			case 5:
				updateBook(bList);
				break;
			case 6:
				//open file by notepad to "Ex31_data.dat"

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
	LinkedList bList;
	initializeLinkedList(bList);

	readFile(bList);

	callMenu(bList);
}