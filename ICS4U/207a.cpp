#include <iostream>

int base, exponent;

int power(int multiplicant, int exponentLeft) {
	if (exponentLeft == 0) return 1;
	multiplicant *= power(multiplicant, exponentLeft - 1);
	return multiplicant;
}

int main_207a() {
	std::cin >> base >> exponent;
	std::cout << power(base, exponent);
	return 0;
}