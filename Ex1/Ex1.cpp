#include <iostream>

using namespace std;

//Enter integer number until value smaller or equal to 0, print summerize of all of inputed values.
int main()
{
    //inp: input: input value
    //sum: Sum of all input value
    int inp=0, sum = 0;
    do {
        sum += inp;
        cout << "Enter Number: ";
        cin >> inp;
    } while (inp > 0);

    cout << "Sum of all input number is " << sum;
}