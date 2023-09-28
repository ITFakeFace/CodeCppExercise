//Ex 18 (10 score):
// Enter fullname
// Generate & Output his/her email.
// Example: Input: Luong Son Bac
//			Output: bac.luongson@hoasen.edu.vn
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
	//fname: fullname
	//arrSplit: array of string contains part of name split from fullname.
	std::string fname;
	std::cout << "Enter full name: ";
	std::getline(std::cin, fname);
	std::vector<std::string> arrSplit;

	//shortage fullname
	fname = shortageBlank(fname);

	//split fullname
	while (fname.find(" ") != -1) {
		arrSplit.push_back(fname.substr(0, fname.find(" ")));
		fname.erase(0, fname.find(" ") + 1);
	}

	//lowercase all characters
	for (int i = 0; i < arrSplit.size(); i++) {
		for (int j = 0; j < arrSplit[i].length(); j++) {
			arrSplit[i][j] = tolower(arrSplit[i][j]);
		}
	}
	for (int i = 0; i < fname.length(); i++) {
		fname[i] = tolower(fname[i]);
	}

	//concatenate strings to email
	std::string email;
	email.append(fname);
	email.append(".");
	for (int i = 0; i < arrSplit.size(); i++) {
		email.append(arrSplit[i]);
	}
	email.append("@hoasen.edu.vn");

	//Output result
	std::cout << "Email: " << email;
}