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
    std::string fname;
    std::cout << "Enter full name: ";
    std::getline(std::cin,fname);
    std::vector<std::string> arrSplit;

    while (fname.find(" ") != -1) {
        arrSplit.push_back(fname.substr(0, fname.find(" ")));
        fname.erase(0, fname.find(" ") + 1);
    }
    for (int i = 0; i < arrSplit.size(); i++) {
        for (int j = 0; j < arrSplit[i].length(); j++) {
            arrSplit[i][j] = tolower(arrSplit[i][j]);
        }
    }
    for (int i = 0; i < fname.length(); i++) {
        fname[i] = tolower(fname[i]);
    }
    std::string email;
    email.append(fname);
    email.append(".");
    for (int i = 0; i < arrSplit.size(); i++) {
        email.append(arrSplit[i]);
    }
    email.append("@hoasen.edu.vn");
    std::cout << "Email: " << email;
}