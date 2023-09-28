//Ex 19 (20 score):
// Enter fullname, ID Code
// Generate & Output his/her email.
// Example: Input: Tran Ba Dao
//				   123456
//			Output: dao.tb23456@sinhvien.hoasen.edu.vn

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

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

int main()
{
	std::string fname, studentId;
	std::cout << "Enter full name: ";
	std::getline(std::cin, fname);
	do {
		std::cout << "Enter student ID: ";
		std::getline(std::cin, studentId);
		if (studentId.size() < 5) {
			std::cout << "Invalid ID ! ID must be more than 5 numeric characters !" << std::endl;
			continue;
		}
		break;
	} while (true);

	std::vector<std::string> arrSplit;
	fname = shortageBlank(fname);

	while (fname.find(" ") != -1) {
		arrSplit.push_back(fname.substr(0, fname.find(" ")));
		fname.erase(0, fname.find(" ") + 1);
	}
	for (int i = 0; i < arrSplit.size(); i++) {
		arrSplit[i][0] = tolower(arrSplit[i][0]);
	}
	for (int i = 0; i < fname.length(); i++) {
		fname[i] = tolower(fname[i]);
	}

	std::string email;
	email.append(fname);
	email.append(".");
	for (int i = 0; i < arrSplit.size(); i++) {
		email.append(arrSplit[i].substr(0, 1));
	}
	email.append(studentId.substr(studentId.length() - 5, studentId.length() - 1));
	email.append("@sinhvien.hoasen.edu.vn");
	std::cout << "Email: " << email;
}