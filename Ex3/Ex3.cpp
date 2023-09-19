#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;

/**
 * checkElementalNumber
 * @param x: number to check
 * Check parameter number is an elemental number or not.
 * @return true if parameter is elemental number
 *         false if parameter is not elemental number
 */
bool checkElementalNumber(int x) {
    if (x > 2) {
        for (int i = 2; i <= sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    else {
        if (x == 2) {
            return true;
        }
    }
    return false;
}

int main()
{
    //inp: input value
    //oddVec: vector of odd number of input value
    //evenVec: vector of even number of input value
    //eleVec: vector of elemental number of input value
    int inp = 0;
    vector<int> oddVec, evenVec, eleVec;

    //Processing input values
    do {
        if (inp != 0) {
            if (inp % 2 == 0) {
                evenVec.push_back(inp);
            }
            else {
                oddVec.push_back(inp);
            }
        }
        if (checkElementalNumber(inp)) {
            eleVec.push_back(inp);
        }
        cout << "Enter Number: ";
        cin >> inp;
    } while (inp > 0);

    //Output Result
    cout << "In all of inputed value, there are: " << endl;
    cout << " - " << oddVec.size() << " Odd Number(s): ";
    for (int i = 0; i < oddVec.size(); i++) {
        cout << oddVec[i]<<" ";
    }
    cout << endl;
    cout << " - " << evenVec.size() << " Even Number(s): ";
    for (int i = 0; i < evenVec.size(); i++) {
        cout << evenVec[i] << " ";
    }
    cout << endl;
    cout << " - " << eleVec.size() << " Elemental Number(s): ";
    for (int i = 0; i < eleVec.size(); i++) {
        cout << eleVec[i] << " ";
    }
}
