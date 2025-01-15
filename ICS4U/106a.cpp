#include <iostream>

int main_106a() {
	int N; std::cin >> N;

	bool* sieve = new bool[N + 1];

	for (int i = 0; i < N + 1; i++)
		sieve[i] = true;

	for (int i = 2; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			sieve[j] = false;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (sieve[i]) std::cout << i << " ";
	}

	delete[] sieve;

	return 0;
}