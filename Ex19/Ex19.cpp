#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <random>
#include <time.h>
#include <math.h>
#include <string>

int main()
{
    std::string fname,studentId;
    std::cout << "Enter full name: ";
    std::getline(std::cin, fname);
    std::cout << "Enter student ID: ";
    std::getline(std::cin, studentId);

    std::vector<std::string> arrSplit;
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