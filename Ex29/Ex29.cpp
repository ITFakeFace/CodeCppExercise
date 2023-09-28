//Ex 29 (50 score):
// Write a program to manage Student (Fullname, Age, Average Score)
// Program is albe to execute following command:
// 1. Add new Student to list
// 2. Print list of Students
// 3. Sort student list order by ASC (Ascending) by their Average Score
// 4. Find Students by their fullname
// 5. Exit Program

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

//create struct of Student
typedef struct Student
{
	char fullname[31];
	int age;
	float avgScore;
};

/**
 * @name: createNewStudent
 * @param: (none)
 * @briefly: Allow user to creat and enter new Student's information.
 * @return: Created Student
 */
Student createNewStudent() {
	//std: student
	//isNotValid: valid flag of checking name input
	Student std;
	bool isNotValid = true;

	//clear buffer
	std::cin.ignore();

	std::cout << "--- Creating new student ---" << std::endl;
	//Input & check Fullname valid
	do {
		std::cout << "- Enter Fullname: ";
		std::cin.getline(std.fullname, 30);
		//check length
		if (strlen(std.fullname) <= 0) {
			std::cout << "#Warn: Name cannot be null and must be different from '*'" << std::endl;
			continue;
		}
		else {
			//check blank & character '*'
			for (int i = 0; i < strlen(std.fullname); i++) {
				if (std.fullname[i] != ' ' && std.fullname[i] != '*') {
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
	} while (isNotValid);

	//Input & check Age valid
	do {
		std::cout << "- Enter Age: ";
		std::cin >> std.age;
		//check range
		if (std.age < 0 || std.age >= 150) {
			std::cout << "#Warn: Age must be in range [0,150] !!" << std::endl;
			continue;
		}
		break;
	} while (true);

	//Input & check Average Scor valid
	do {
		std::cout << "- Enter Average Score: ";
		std::cin >> std.avgScore;
		//check range
		if (std.avgScore < 0 || std.avgScore >10) {
			std::cout << "#Warn: Average Score must be in range [0,10] !!" << std::endl;
			continue;
		}
		break;
	} while (true);
	std::cout << "------- End Creating  -------" << std::endl;
	return std;
}

/**
 * @name: printStudentList
 * @param: stdList: arrays of students
 * @briefly: Print Student's information to screen
 * @return: (none).
 */
void printStudentList(std::vector<Student> stdList) {
	std::cout << "---------------------Student List---------------------" << std::endl;
	std::cout << "+ " << std::setw(31) << std::left << "Name" << " + " << std::setw(4) << std::left << "Age" << " + " << std::setw(7) << std::left << "AvgScore" << " +" << std::endl;

	for (int i = 0; i < stdList.size(); i++) {
		std::cout << "| " << std::setw(31) << std::left << stdList[i].fullname << " | " << std::setw(4) << std::left << stdList[i].age << " | " << std::fixed << std::setprecision(2) << std::setw(7) << std::left << stdList[i].avgScore << "  |" << std::endl;
	}
	std::cout << "------------------------------------------------------" << std::endl;
}


/**
 * @name: swap
 * @param: a: element a,
 *		   b: element b.
 * @briefly: swap value of 2 parameters a & b
 * @return: (none).
 */
template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

/**
 * @name: sortListByASC
 * @param: stdList: arrays of students.
 * @briefly: sort students list by order ASC base on student's average score (Ascending)
 * @return: (none).
 */
void sortListByASC(std::vector<Student>& stdList) {
	//interchange sort
	for (int i = 0; i < stdList.size() - 1; i++) {
		for (int j = i; j < stdList.size(); j++) {
			if (stdList[i].avgScore > stdList[j].avgScore) {
				swap(stdList[i], stdList[j]);
			}
		}
	}
}

/**
 * @name: findStdByName
 * @param: stdList: arrays of students.
 * @briefly: find student(s) that their name contains input string, then print these student(s) to screen
 * @return: (none).
 */
void findStdByName(std::vector<Student> stdList) {
	//fname: fullname
	//search: string to search
	std::string fname, search;

	std::cin.ignore();

	std::cout << "- Enter name to search: ";
	std::getline(std::cin, search);

	std::cout << "---------------------Student List---------------------" << std::endl;
	std::cout << "+ " << std::setw(31) << std::left << "Name" << " + " << std::setw(4) << std::left << "Age" << " + " << std::setw(7) << std::left << "AvgScore" << " +" << std::endl;
	for (int i = 0; i < stdList.size(); i++) {
		fname = stdList[i].fullname;
		if (fname.find(search) != -1) {
			std::cout << "| " << std::setw(31) << std::left << stdList[i].fullname << " | " << std::setw(4) << std::left << stdList[i].age << " | " << std::fixed << std::setprecision(2) << std::setw(7) << std::left << stdList[i].avgScore << "  |" << std::endl;
		}
	}
	std::cout << "------------------------------------------------------" << std::endl;
}

/**
 * @name: callMenu
 * @param: stdList: arrays of students
 * @briefly: Call menu that is able for user to choose selection of following menu commands.
 * @return: (none).
 */
void callMenu(std::vector<Student>& stdList) {
	int choice;
	do {
		std::cout << "---Menu-----------------------------------------" << std::endl;
		std::cout << "| 1. Add New Student" << std::endl;
		std::cout << "| 2. Print List of Students" << std::endl;
		std::cout << "| 3. Sort List by Average Score" << std::endl;
		std::cout << "| 4. Find  Students by Fullname" << std::endl;
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
		std::cout << std::endl << "--------------------Result--------------------" << std::endl << std::endl;
		switch (choice) {
			case 1:
				stdList.push_back(createNewStudent());
				break;
			case 2:
				printStudentList(stdList);
				break;
			case 3:
				sortListByASC(stdList);
				std::cout << "#Status: Successfully Sorted !" << std::endl;
				break;
			case 4:
				findStdByName(stdList);
				break;
			case 0:
				std::cout << "You're Out";
				break;
			default:
				std::cout << "#Warn: Invalid Choice !! Please Re-enter !! " << std::endl;
				break;
		}
		std::cin.ignore();
		std::cin.get();
		std::cout << "\033[2J\033[1;1H";
	} while (choice != 0);
}

int main()
{
	std::vector<Student> stdList;

	callMenu(stdList);
}