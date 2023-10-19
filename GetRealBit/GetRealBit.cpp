#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
int main()
{
	int choice;
	std::vector<int> bit;
	int N = 0;
	float recent = 0;
	do {
		std::cout << "Enter N: ";
		std::cin >> N;
		std::cout << "Enter recent: ";
		std::cin >> recent;
		int pow = 0;
		float recent2 = recent;
		while (recent2 - floor(recent2) != 0) {
			recent2 *= 10;
			pow++;
		}
		std::cout << "pow" << pow << std::endl;
		for (int i = 0; i < N; i++) {
			recent = recent * 2;
			std::cout << std::fixed << std::setprecision(pow + 1) << recent << std::endl;
			if (recent > 1) {
				recent = recent - 1;
				bit.push_back(1);
			}
			else if (recent < 1) {
				bit.push_back(0);
			}

			else {
				bit.push_back(1);
				break;
			}
		}
		std::cout << std::endl;
		for (int i = 0; i < bit.size(); i++) {
			std::cout << bit[i];
		}
		std::cout << std::endl << "Enter choice: ";
		std::cin >> choice;
	} while (choice != 0);

}