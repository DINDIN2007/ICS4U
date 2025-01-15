#include <iostream>

// Q1a
// Create a void function q1a() that dynamically allocates an array, enters its content from the keyboard and prints its content.
void t_q1a(int size) {
	char* content = new char[size];
	for (int i = 0; i < size; i++) {
		std::cin >> content[i];
	}
	for (int i = 0; i < size; i++) {
		std::cout << content[i] << "\t";
	}
	delete[] content;
}

// Q1b
// Create a void function q1b() that dynamically allocates an array, enters its content from the keyboard and prints its content in reverse order. Make sure to use delete[] when finished.[1]
void t_q1b(int size) {
	char* content = new char[size];
	for (int i = 0; i < size; i++) {
		std::cin >> content[i];
	}
	for (int i = size - 1; i >= 0; i--) {
		std::cout << content[i] << "\t";
	}
	delete[] content;
}

// Q1c
// Create a void function q1c() that dynamically allocates an array, initializes all the locations with random numbers from 1 - 50 and finds the sum of all the elements of the array. Make sure to use delete[] when finished.[2]
void t_q1c(int size) {
	int* numbers = new int[size];
	for (int i = 0; i < size; i++) {
		numbers[i] = (rand() % 50 + 1);
	}

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += numbers[i];
	}

	std::cout << sum << "\t";
	delete[] numbers;
}

// Q1d
// Create a void function q1d() that declares two dynamically allocated arrays of integers and appends the second array at the end of the first one to form the third one.
// Print each array to the screen and make sure to use delete[] when finished.[3]
void t_q1d(int size_a, int size_b) {
	int* array_a = new int[size_a];
	for (int i = 0; i < size_a; i++) {
		std::cin >> array_a[i];
	}

	int* array_b = new int[size_b];
	for (int i = 0; i < size_b; i++) {
		std::cin >> array_b[i];
	}

	int* array_c = new int[size_a + size_b];
	for (int i = 0; i < size_a + size_b; i++) {
		if (i < size_a) array_c[i] = array_a[i];
		else array_c[i] = array_b[i - size_a];
	}

	for (int i = 0; i < size_a; i++) std::cout << array_a[i] << "\t";
	for (int i = 0; i < size_b; i++) std::cout << array_b[i] << "\t";
	for (int i = 0; i < size_a + size_b; i++) std::cout << array_c[i] << "\t";

	delete[] array_a; delete[] array_b; delete[] array_c;
}

int main_204b() {
	int size; std::cin >> size;
	int size_b; std::cin >> size_b;
	t_q1a(size); t_q1b(size); t_q1c(size); t_q1d(size, size_b);
	return 0;
}