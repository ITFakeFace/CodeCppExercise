#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>

#define YELLOW  "\x1b[33m" //color code of yellow
#define RESET   "\x1b[0m" //color code of reset color

typedef struct Word {
	char en[46]; //key
	char vn[51];
};

typedef struct Node {
	Word word;
	Node* pLeft;
	Node* pRight;
};

typedef struct BinarySearchTree {
	Node* pRoot;
};

void initializeTree(BinarySearchTree& list) {
	list.pRoot = NULL;
}

bool isEmpty(BinarySearchTree& list) {
	if (list.pRoot == NULL) {
		return true;
	}
	return false;
}

Node* searchNode(Node* node, std::string en) {
	if (node == NULL) {
		return NULL;
	}
	else if (strcmp(en.c_str(), node->word.en) == 0) {
		return node;
	}
	else if (strcmp(node->word.en, en.c_str()) > 0) {
		return searchNode(node->pLeft, en);
	}
	else if (strcmp(node->word.en, en.c_str()) < 0) {
		return searchNode(node->pRight, en);
	}
}

Word createWord() {
	Word word;
	std::cin.ignore();
	bool isNotValid = true;
	while (isNotValid) {
		std::cout << "Enter English Word: ";
		std::cin.getline(word.en, 45);
		if (strlen(word.en) <= 0) {
			std::cout << "#Warn: English word cannot be null and must be different from '*' !!" << std::endl;
			continue;
		}
		else {
			//check blank & character '*'
			for (int i = 0; i < strlen(word.en); i++) {
				if (word.en[i] != ' ' && word.en[i] != '*') {
					isNotValid = false;
					break;
				}
			}
			if (isNotValid) {
				std::cout << "#Warn: English word cannot be null and must be different from '*' !!" << std::endl;
				continue;
			}
		}
		break;
	}

	isNotValid = true;
	while (isNotValid) {
		std::cout << "Enter Vietnamese Word: ";
		std::cin.getline(word.vn, 50);
		if (strlen(word.vn) <= 0) {
			std::cout << "#Warn: Vietnamese word cannot be null and must be different from '*' !!" << std::endl;
			continue;
		}
		else {
			//check blank & character '*'
			for (int i = 0; i < strlen(word.vn); i++) {
				if (word.vn[i] != ' ' && word.vn[i] != '*') {
					isNotValid = false;
					break;
				}
			}
			if (isNotValid) {
				std::cout << "#Warn: Vietnamese word cannot be null and must be different from '*' !!" << std::endl;
				continue;
			}
		}
		break;
	}
	return word;
}

Node* initializeNode(Word word) {
	Node* node = new Node;
	if (node != NULL) {
		node->pLeft = NULL;
		node->pRight = NULL;
		node->word = word;
	}
	return node;
}

int insertNode(Node*& node, Word word) {
	if (node != NULL) { // find location
		if (strcmp(node->word.en, word.en) == 0) {
			return 0; // failure: exist
		}
		else if (strcmp(node->word.en, word.en) > 0) {
			return insertNode(node->pLeft, word);
		}
		else if (strcmp(node->word.en, word.en) < 0) {
			return insertNode(node->pRight, word);
		}
	}
	else { // add new node
		node = initializeNode(word);
		if (node == NULL) {
			return -1; // failure: lack of memory
		}
		else {
			return 1; // successful
		}
	}
}

void addWord(Node*& root) {
	Word word;
	while (true) {
		word = createWord();
		if (searchNode(root, word.en) == NULL) {
			break;
		}
		else {
			std::cout << "#Warn: Existed word !! Please re-enter !!" << std::endl;
			continue;
		}
		std::cout << "#Warn: Invalid word !! Please re-enter !!" << std::endl;
	}
	int result = insertNode(root, word);
	if (result == 1) {
		std::cout << "#Notification: Successfully Added 1 word !!" << std::endl;
	}
	else if (result == 0) {
		std::cout << "#Notification: Failed to Add word (existed word) !!" << std::endl;
	}
	else {
		std::cout << "#Notification: Failed to Add word (lacking of memory) !!" << std::endl;
	}
}

void printAllNode(Node* node) {
	if (node == NULL) {
		return;
	}
	else {
		printAllNode(node->pLeft);
		std::cout << "+ " << std::setw(45) << std::left << node->word.en << " + " << std::setw(50) << std::left << node->word.vn << " +" << std::endl;
		printAllNode(node->pRight);
	}
}

void printTree(BinarySearchTree wList) {
	if (wList.pRoot == NULL) {
		std::cout << "#Notification: Empty List !!" << std::endl;
		return;
	}

	std::cout << "------------------------ List of Words ------------------------" << std::endl;
	std::cout << "+ --- English Meaning ------------------------- + --- Vietnamese Meaning --------------------------- +" << std::endl;
	printAllNode(wList.pRoot);
	std::cout << "---------------------------------------------------------------" << std::endl;
}

void replaceByLeftestOfRight(Node*& root, Node*& node) {
	if (node->pLeft != NULL) {
		replaceByLeftestOfRight(root, node->pLeft);
	}
	else {
		root->word = node->word;
		root = node;
		node = node->pRight;
	}
}

bool deleteNode(Node*& node, std::string en)
{
	if (node == NULL) {
		return false;
	}

	if (strcmp(node->word.en, en.c_str()) > 0) {
		return deleteNode(node->pLeft, en);
	}
	else if (strcmp(node->word.en, en.c_str()) < 0) {
		return deleteNode(node->pRight, en);
	}
	Node* temp = node;

	//No Child
	if (node->pLeft == NULL && node->pRight == NULL) {
		node = NULL;
	}
	//Only Right Child
	else if (node->pLeft == NULL) {
		node = node->pRight;
	}
	//Only Left Child
	else if (node->pRight == NULL) {
		node = node->pLeft;
	}
	//Both 2 Child
	else {
		replaceByLeftestOfRight(temp, node->pRight);
	}
	delete temp;
	return true;
}

void deleteWord(BinarySearchTree& wList) {
	printTree(wList);
	//delCode: string to delete
	std::string delWord;
	std::cin.ignore();

	std::cout << "- Enter English Word to delete: ";
	std::getline(std::cin, delWord);

	Node* deletingNode = searchNode(wList.pRoot, delWord);
	if (deletingNode == NULL) {
		std::cout << "#Warn: Cannot find English word '" << delWord << "' !!" << std::endl;
		return;
	}
	else {
		if (deleteNode(wList.pRoot, delWord)) {
			std::cout << "#Status: Successfully deleted 1 Word !!" << std::endl;
			return;
		}
		else {
			std::cout << "#Warn: Failed to delete 1 Book !!" << std::endl;
		}
	}
}

void updateWord(BinarySearchTree& wList) {
	printTree(wList);
	//updWord: string to update
	Word word;
	std::cin.ignore();

	std::cout << "- Enter English Word to update: ";
	std::cin.getline(word.en, 45);

	Node* updatingNode = searchNode(wList.pRoot, word.en);
	if (updatingNode == NULL) {
		std::cout << "#Warn: Cannot find English word '" << word.en << "' !!" << std::endl;
		return;
	}
	else {
		bool isNotValid = true;
		while (isNotValid) {
			std::cout << "Enter Vietnamese Word: ";
			std::cin.getline(word.vn, 50);
			if (strlen(word.vn) <= 0) {
				std::cout << "#Warn: Vietnamese word cannot be null and must be different from '*' !!" << std::endl;
				continue;
			}
			else {
				//check blank & character '*'
				for (int i = 0; i < strlen(word.vn); i++) {
					if (word.vn[i] != ' ' && word.vn[i] != '*') {
						isNotValid = false;
						break;
					}
				}
				if (isNotValid) {
					std::cout << "#Warn: Vietnamese word cannot be null and must be different from '*' !!" << std::endl;
					continue;
				}
			}
			break;
		}
		strcpy_s(updatingNode->word.vn, word.vn);
		std::cout << "#Status: Successfully updated 1 Word !!" << std::endl;
		return;
	}
}

void findNode(Node* node, std::string word) {
	if (node == NULL) {
		return;
	}

	findNode(node->pLeft, word);
	if (((std::string)node->word.en).find(word) != -1 || ((std::string)node->word.vn).find(word) != -1) {
		printf(RESET "+ ");
		if (((std::string)node->word.en).find(word) != -1) {
			printf(YELLOW "%-45s" RESET, node->word.en);
		}
		else {
			printf("%-45s", node->word.en);
		}
		printf(" + ");
		if (((std::string)node->word.vn).find(word) != -1) {
			printf(YELLOW "%-50s" RESET, node->word.vn);
		}
		else {
			printf("%-50s", node->word.vn);
		}
		printf(" +\n");
	}
	findNode(node->pRight, word);
}

void findWord(BinarySearchTree& wList) {
	if (wList.pRoot == NULL) {
		std::cout << "#Notification: Empty List !!" << std::endl;
		return;
	}

	//srcWord: word to search
	std::string srcWord;
	std::cin.ignore();

	std::cout << "- Enter English Word to search: ";
	std::getline(std::cin, srcWord);

	std::cout << "------------------------ List of Words ------------------------" << std::endl;
	std::cout << "+ --- English Meaning ------------------------- + --- Vietnamese Meaning --------------------------- +" << std::endl;
	findNode(wList.pRoot, srcWord);
	std::cout << "---------------------------------------------------------------" << std::endl;
}

void writeLineToFile(std::string& writingString, Node* node) {
	if (node == NULL) {
		return;
	}
	else {
		writingString += node->word.en + (std::string)"*" + node->word.vn + "\n";
		writeLineToFile(writingString, node->pLeft);
		writeLineToFile(writingString, node->pRight);
	}
}

void writeFile(BinarySearchTree& wList) {
	std::ofstream outputFile;
	std::string writingString = "";
	outputFile.open("Ex32_data.dat");
	if (!outputFile.is_open()) {
		std::cout << "#Notification: Failed to open/create file" << std::endl;
		return;
	}

	writeLineToFile(writingString, wList.pRoot);

	outputFile << writingString;
	outputFile.close();
	std::cout << "#Status: Success saved !!" << std::endl;
}

void readLineFromFile(Node*& root, Word word) {
	int result = insertNode(root, word);
	if (result == 1) {
		std::cout << "#Notification: Successfully Added 1 word !!" << std::endl;
	}
	else if (result == 0) {
		std::cout << "#Notification: Failed to Add word (existed word) !!" << std::endl;
	}
	else {
		std::cout << "#Notification: Failed to Add word (lacking of memory) !!" << std::endl;
	}
}

void readFile(BinarySearchTree& wList) {
	std::ifstream inputFile("Ex32_data.dat");

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

		Word word;
		if (inputFile.fail()) {
			std::cerr << "#Warn: Failed to read data from the file." << std::endl;
			inputFile.close();
			return;
		}

		if (splitArray.size() == 2) {
			strcpy_s(word.en, splitArray[0].c_str());
			strcpy_s(word.vn, splitArray[1].c_str());
			readLineFromFile(wList.pRoot, word);
		}
		else {
			std::cout << "#Warn: Invalid File's data format" << std::endl;
		}
		splitArray.clear();
	}
	std::cout << "#Notification: Successfully Readed from File !" << std::endl;
	inputFile.close();
}

void callMenu(BinarySearchTree& wList) {
	int choice;
	std::string result = "notepad.exe Ex32_data.dat";
	do {
		fflush(stdin);

		std::cout << "---Menu-----------------------------------------" << std::endl;
		std::cout << "| 1. Add New Word" << std::endl;
		std::cout << "| 2. Delete Word" << std::endl;
		std::cout << "| 3. Update Word" << std::endl;
		std::cout << "| 4. Find Word(s)" << std::endl;
		std::cout << "| 5. Print all Words" << std::endl;
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
				addWord(wList.pRoot);
				writeFile(wList);
				break;
			case 2:
				deleteWord(wList);
				writeFile(wList);
				break;
			case 3:
				updateWord(wList);
				writeFile(wList);
				break;
			case 4:
				findWord(wList);
				break;
			case 5:
				printTree(wList);
				break;
			case 6:
				//open file by notepad to "Ex32_data.dat"

				if (system(result.c_str()) == 0) {
					std::cout << "Successfully Open File." << std::endl;
				}
				else {
					std::cout << "#Error: Cannot Open File by Nodepad.exe." << std::endl;
				}
				break;
			case 7:

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
	BinarySearchTree wList;
	initializeTree(wList);
	readFile(wList);
	callMenu(wList);
}