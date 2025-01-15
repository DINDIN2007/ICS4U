#include <iostream>

// e) Write a function largest that finds the largest element in the array.
int largestElement(int a[], int a_size) {
	int max_a = a[0];
	for (int i = 1; i < a_size; i++) {
		max_a = std::max(max_a, a[i]);
	}
	return max_a;
}

// f) Write a function recursive_largest that finds the largest element in the array recursively
int largestElementRecursively(int a[], int a_size) {
	if (a_size == 0) return a[0];
	return std::max(a[a_size], largestElementRecursively(a, a_size - 1));
}

int main_107g() {
	int N; std::cin >> N;

	int* a = new int[N];

	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}

	std::cout << largestElementRecursively(a, N - 1);
	return 0;
}