#include <iostream>
#include <algorithm>

// Create function createRndArray to generate and sort an array with size elements that contains random values between the provided range low to high.
// (Note: for the tester you will read in the randomly created array; you will need to sort the array)
int* createRndArray(int size, int low, int high) {
	std::srand(std::time(0));
	int* rndArray = new int[size];
	for (int i = 0; i < size; i++) {
		rndArray[i] = low + (rand() % (high - low));
	}
	return rndArray;
}

// Create a linear search function to find a value in an array. Return -1 if not found.
void outputSteps(int low, int high, int* a);

int linearSearch(int size, int* a, int target) {
	for (int i = 0; i < size; i++) {
		outputSteps(i, size - 1, a);
		if (a[i] == target) return i;
	}
	return -1;
}

// Create a function to output certain elements of the array(i.e.top half of array).
void outputSteps(int low, int high, int* a) {
	for (int i = low; i <= high; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}

// Create a binary search function to find a value in an array. Return -1 if not found.
int binarySearch(int size, int* a, int target) {
	int low = 0, high = size - 1, mid;

	while (low <= high) {
		outputSteps(low, high, a);
		mid = (low + high + 1) / 2;
		
		if (a[mid] == target) {
			return mid;
		}

		if (a[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return -1;
}

// Use your functions to create a program that will output something similar to the following :
int main() {
	int N, X; std::cin >> N >> X;
	int* a = new int[N];

	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}

	std::sort(a, a + N);

	std::cout << "Linear Search\n";
	int found = linearSearch(N, a, X);
	if (found == -1) std::cout << "not found\n\n";
	else std::cout << "found at index " << found << "\n\n";

	std::cout << "Binary Search\n";
	found = binarySearch(N, a, X);
	if(found == -1) std::cout << "not found\n\n";
	else std::cout << "found at index " << found << "\n\n";

	delete[] a;
	return 0;
}