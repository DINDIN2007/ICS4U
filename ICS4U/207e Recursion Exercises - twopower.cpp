#include <iostream>
#include <cmath>

// b) Write a recursive function that initializes elements of the array called twopower to 1, 2, 4, 8, and so on.
int* init_twopower_array(int range, int n = 0) {
	if (n == range - 1) {
		int* a = new int[n + 1]; a[n] = (int)(pow(2, n));
		return a;
	}
	
	int* a = init_twopower_array(range, n + 1); a[n] = (int)(pow(2, n));
	return a;
}

int main_207e() {
	int range; std::cin >> range;
	int* pointer_array = init_twopower_array(range);
	for (int i = 0; i < range; i++) {
		std::cout << pointer_array[i] << " ";
	}
	delete[] pointer_array;
	return 0;
}