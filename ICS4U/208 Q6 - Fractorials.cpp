#include <iostream>

/*
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

long long factorials(long long n, long long result = 1) {
	if (n == 1) return 1;
	long long a = (n / gcd(n, result)); result *= a;
	return a * factorials(n - 1, result);
}

int main_208Q6() {
	long long n; std::cin >> n;
	std::cout << factorials(n);
	return 0;
}
*/