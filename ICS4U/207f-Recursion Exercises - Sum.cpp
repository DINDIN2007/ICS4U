#include <iostream>

// c) Write a function sum that finds the sum of the elements of the array.
int findSum(int a[], int a_size) {
	int sum = 0;
	for (int i = 0; i < a_size; i++) {
		sum += a[i];
	}
	return sum;
}

// d) Write a function recursive_sum that finds the sum of the elements of the array.
int findSumRecursively(int a[], int count) {
	if (count == 0) return a[0];
	int sum = findSumRecursively(a, count - 1) + a[count];
	return sum;
}

int main_207f() {
	int N; std::cin >> N;

	int* a = new int[N];

	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}

	std::cout << findSumRecursively(a, N - 1);

	return 0;
}