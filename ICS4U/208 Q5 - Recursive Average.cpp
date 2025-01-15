#include <iostream>

double find_average(int* a, int n, int max) {
	if (n == 0) return a[0];
	return (find_average(a, n - 1, max) * n + a[n]) / (n + 1);
}

int main_208Q5() {
	int N; std::cin >> N;
	int* average = new int[N];
	
	for (int i = 0; i < N; i++) {
		std::cin >> average[i];
	}
	
	std::cout << round(find_average(average, N - 1, N - 1) * 10) / 10.0;

	delete[] average;
	return 0;
}