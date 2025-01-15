#include <iostream>

void printArrayRecursive(int count, int* a) {
	if (count == -1) return;
	printArrayRecursive(count - 1, a);
	std::cout << a[count] << " ";
}

int main_107c() {
	int N; std::cin >> N;
	
	int* a = new int[N];

	for (int i = 0; i < N; i++)
		std::cin >> a[i];

	printArrayRecursive(N - 1, a);
	
	delete[] a;
	return 0;
}