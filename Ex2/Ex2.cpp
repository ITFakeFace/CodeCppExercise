#include <iostream>
#include <iomanip>

using namespace std;

//Enter integer number until value smaller or equal to 0, print average of summerize of all of inputed values (except last number 0).
int main()
{
    //inp: input: input value
    //n: number of inputed values
    //sum: Sum of all input value
    int inp = 0, n = 0, sum = 0;

    //Processing Input value
    do {
        sum += inp;
        n++;
        cout << "Enter Number: ";
        cin >> inp;
    } while (inp > 0);

    //Output result
    if (n == 0) {
        cout << "There's no valid value";
    }
    else {
        cout << fixed << setprecision(2) << (float)sum / (n - 1);
    }
}


