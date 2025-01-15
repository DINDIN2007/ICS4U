#include <iostream>

/* Write a recursive function gcd that returns the greatest common divisor of x and y.
int gcd(int x, int y) {
	// If y is equal to 0, then gcd(x, y) is x;
	if (y == 0) return x;

	// otherwise gcd(x, y) is gcd(y, x% y), where% is the modulus operator.
	return gcd(y, x % y);
}

int main_207Q2() {
	int x, y;
	std::cin >> x >> y;
	std::cout << gcd(x, y);
	return 0;
}
*/