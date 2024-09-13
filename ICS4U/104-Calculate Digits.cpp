#include <iostream>
#include <cmath>

int input{ -1 }, sum{ 0 };

int main_104() {
	while (input < 0) {
		std::cin >> input;
	}

	std::cout << "The digits of " << input << " are ";

	bool hasReachedFirstDigit = false;

	for (int i = 10; i >= 0; i--) {
		int digit = input / (int)(pow(10, i));

		if (hasReachedFirstDigit) {
			std::cout << digit << (i <= 1 ? (i == 1 ? ", and " : ".\n") : ", ");
			sum += digit; input -= digit * (int)(pow(10, i));
		}

		else if (digit != 0) {
			std::cout << digit << (i <= 1 ? (i == 1 ? " and " : ".\n") : ", ");
			sum += digit; input -= digit * (int)(pow(10, i));
			hasReachedFirstDigit = true;
		}
	}

	std::cout << "The sum is " << sum;
	return 0;
}