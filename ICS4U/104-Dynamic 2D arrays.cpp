#include <iostream>

// Q1a
// Create a void function q1a() that enters a 2 - dimensional array from the keyboard and prints its values row by row. (See note for answer)[1]

void q1a(int size_row, int size_col) {
	int** array_2d = new int* [size_row];

	for (int i = 0; i < size_row; i++) {
		int* array_1d = new int[size_col];
		for (int j = 0; j < size_col; j++) {
			std::cin >> array_1d[j];
		}
		array_2d[i] = array_1d;
	}

	for (int i = 0; i < size_row; i++)
		for (int j = 0; j < size_col; j++)
			std::cout << array_2d[i][j] << "\t";

	for (int i = 0; i < size_row; i++) delete[] array_2d[i];

	delete[] array_2d;
}

//Q1b
// Create a void function q1b() that initializes a 2 - dimensional array using random numbers from 1 – 1000 and finds the average of all the values.
// Make sure to properly deallocate memory afterwards.[2]

void q1b(int size_row, int size_col) {
	int** array_2d = new int* [size_row];

	for (int i = 0; i < size_row; i++) {
		int* array_1d = new int[size_col];
		for (int j = 0; j < size_col; j++) {
			array_1d[j] = (rand() % 1000 + 1);
		}
		array_2d[i] = array_1d;
	}

	int avg = 0;

	for (int i = 0; i < size_row; i++)
		for (int j = 0; j < size_col; j++)
			avg += array_2d[i][j];

	std::cout << (avg / (size_row * size_col));

	for (int i = 0; i < size_row; i++)
		delete[] array_2d[i];

	delete[] array_2d;
}

//Q1c
// Create a void function q1c() that initializes an N×N (square) 2 - dimensional array and prints the elements on its main diagonal.
// Make sure to properly deallocate memory afterwards.[2]

void q1b(int size) {
	int** array_2d = new int* [size];

	for (int i = 0; i < size; i++) {
		int* array_1d = new int[size];
		for (int j = 0; j < size; j++) {
			std::cin >> array_1d[j];
		}
		array_2d[i] = array_1d;
	}

	for (int i = 0; i < size; i++) {
		std::cout << array_2d[i][i] << " ";
	}

	for (int i = 0; i < size; i++) delete[] array_2d[i];

	delete[] array_2d;
}

//Q2
// Create a void function q2() that declares two dynamically allocated 2 - dimensional arrays of integers
// and appends the second array at the end of the first one to form the third 2 - dim array.
// Print all relevant values to the screen. Make sure to properly deallocate memory afterwards.[3]

void q2(int row_a, int col_a, int row_b, int col_b) {
	int **aArray_2d = new int*[row_a], **bArray_2d = new int*[row_b];

	for (int i = 0; i < row_a; i++) {
		int* array_1d = new int[col_a];
		for (int j = 0; j < col_a; j++) {
			std::cin >> array_1d[j];
		}
		aArray_2d[i] = array_1d;
	}

	for (int i = 0; i < row_b; i++) {
		int* array_1d = new int[col_b];
		for (int j = 0; j < col_b; j++) {
			std::cin >> array_1d[j];
		}
		bArray_2d[i] = array_1d;
	}

	int** cArray_2d = new int*[row_a + row_b];
	for (int i = 0; i < row_a + row_b; i++) {
		if (i < row_a) cArray_2d[i] = aArray_2d[i];
		else cArray_2d[i] = bArray_2d[i - row_a];
	}

	for (int i = 0; i < row_a; i++) {
		for (int j = 0; j < col_a; j++)
			std::cout << aArray_2d[i][j] << " ";
		std::cout << "\n";
	}

	for (int i = 0; i < row_b; i++) {
		for (int j = 0; j < col_b; j++)
			std::cout << bArray_2d[i][j] << " ";
		std::cout << "\n";
	}

	for (int i = 0; i < row_a + row_b; i++) {
		for (int j = 0; j < ((i < row_a) ? col_a : col_b); j++)
			std::cout << cArray_2d[i][j] << " ";
		std::cout << "\n";
	}

	for (int i = 0; i < row_a; i++)
		delete[] aArray_2d[i];
	for (int i = 0; i < row_b; i++)
		delete[] bArray_2d[i];
	for (int i = 0; i < row_a + row_b; i++)
		delete[] cArray_2d[i];

	delete[] aArray_2d; delete[] bArray_2d; delete[] cArray_2d;
}

// Q3
// Declare and initialize an array of length 5.
// Send the array to the function modifyArray that doubles each of the original values of elements of the array.
// Now, print the new values of the array. 
// Also, send a single element of the array to the function modify Element that doubles the element received and prints it out.
// Now, print the value of the element one more time after returning to the main function.[3]

void modifyArray(int[], int);
void modifyElement(int);

int main_204()
{
	int element[5];
	for (int index = 0; index <= 4; index++)
		element[index] = index;
	std::cout << "Effects of passing entire array call by reference\n\n";
	std::cout << "Value of the original array is \n";
	for (int x = 0; x <= 4; x++)
		std::cout << element[x] << " ";
	std::cout << std::endl;
	modifyArray(element, 5);
	std::cout << std::endl << std::endl;
	std::cout << "Effects of passing array element call-by-value\n\n";
	std::cout << "The value of element[3] is " << element[3] << std::endl;
	modifyElement(element[3]);
	std::cout << "The value of element[3] is " << element[3] << std::endl;
	return 0;
}
void modifyArray(int b[], int ArraySize) {
	// add the body of the function
	for (int i = 0; i < ArraySize; i++) b[i] *= 2;
}
void modifyElement(int a)
{
	// add the body of the function
	a *= 2;
}