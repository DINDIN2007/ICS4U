#include <iostream>
#include <cmath>

// a) Write an iterative function that solves the problem
double birthdayParadox(int n) {
	if (n == 1) return 0;
	if (n > 75) return 1;

	double probability = 1;

	for (int i = 0; i < 365 - n + 1; i++) {
		probability *= (365.0 - i / 365.0);
	}

	return 1 - probability;
}

// b) Write a recursive function that solves the problem
double findFactorial(int start, int end) {
	if (start == end) return end;
	return start * findFactorial(start - 1, end);
}

double birthdayParadoxRecursive(int n) {
	if (n <= 1) return 0;
	if (n > 75) return 1;
	return 1 - (findFactorial(365, 365 - n + 1) / pow(365, n));
}

int main_207h() {
	int N; std::cin >> N;
	std::cout << birthdayParadoxRecursive(N);
	return 0;
}