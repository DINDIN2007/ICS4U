#include <iostream>
#include <string>

std::string decimalToBinary(int X) {
	if (X <= 1) return std::to_string(X);
	return decimalToBinary(X / 2) + std::to_string(X%2);
}

int main_208Q4() {
	int X; std::cin >> X;
	std::cout << decimalToBinary(X);
	return 0;
}