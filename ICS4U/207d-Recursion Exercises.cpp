#include <iostream>

// a) Write a function init_array that initializes an array of length 10 to random numbers between 1 and 50.
int* init_array(int n = 0) {
	if (n == 9) {
		return new int[10] {0, 0, 0, 0, 0, 0, 0, 0, 0, rand() % 50};
	}

	int* a = init_array(n + 1); a[n] = rand() % 50;
	return a;
}

int main_207d() {
	int* pointer_array = init_array();
	for (int i = 0; i < 10; i++) {
		std::cout << pointer_array[i] << " ";
	}
	delete[] pointer_array;
	return 0;
}