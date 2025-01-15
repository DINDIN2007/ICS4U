#include <iostream>

// 1. If a selection sort were to be used to sort the following list, 
// Robert Brian Victor David Scott, in alphabetical order, show the data after each pass of the sort.
// Find the largest first.

void selectionQ1() {
	std::cout
		<< "Robert Brian Victor David Scott\n"
		<< "Robert Brian Scott David Victor\n"	// Victor being the largest item in that list and is swapped with Scott
		<< "Robert Brian David Scott Victor\n"	// Scott is the 2nd largest item in that list and is swapped with David
		<< "David Brian Robert Scott Victor\n"	// Robert is the 3rd largest item in that list and is swapped with David
		<< "Brian David Robert Scott Victor\n";	// David is the 4rth largest item in that list and is swapped with David
	// List is sorted
}

// 2. Answer in comments :
// In the selectSort method, what would happen if the expression arr[j] > arr[max_pos] were to be changed to arr[j] < arr[max_pos] ?

// Ans: In this case, selectSort finds the smallest value in the sublist to be placed at the back of the list instead,
// which will sort the list in descending order instead of ascending order

// 3. Answer in comments : 
// In our version of selection sort, if the largest item is already at location i in the list, 
// then the method still swaps that value with itself, even though it is not necessary.

// (a) How could the method be changed to avoid this unnecessary swapping ?

// Ans: An if statement can be added to check if the index of the largest item matches that location i
// If it doesn't, then a regular swap can occur, while if it does, that process is skipped

// (b) Why might is be better to leave the method as it is ?

// Ans: The swap doesn't really impact the final result of the sort, and leaving as is makes the code cleaner, shorter and easier to read

// 4. On each pass of our version of selection sort, the largest value among the remaining unsorted items was placed in its correct position.
// An alternate form of the algorithm uses each pass to place the smallest value among the remaining unsorted values in its correct position.

// (a) Given the set of data

// 8 9 6 1 2 4

// show the data as they would appear after each pass of a selection sort that moves the smallest data.

void selectionQ4a() {
	std::cout
		<< "8 9 6 1 2 4\n"	// Original List
		<< "1 9 6 8 2 4\n"	// Smallest element is 1 and is swapped to index 0
		<< "1 2 6 8 9 4\n"	// 2nd smallest elemet is 2 and is swapped to index 1
		<< "1 2 4 8 9 6\n"	// 3rd smallest elemet is 4 and is swapped to index 2
		<< "1 2 4 6 9 8\n"	// 4th smallest elemet is 6 and is swapped to index 3
		<< "1 2 4 6 8 9\n";	// 5nd smallest elemet is 8 and is swapped to index 4
	// List is sorted
}

// (b) Write a C++ method that implements this algorithm to sort an array of int values.

void selectionSort(int a[], int size) {
	for (int i = 0; i < size; i++) {
		int pos_min = i; // Assuming the first element in the sublist is the smallest

		// Output current array
		for (int j = 0; j < size; j++) std::cout << a[j] << " ";
		std::cout << "\n";

		// Find the actual smallest element
		for (int j = i; j < size; j++) {
			if (a[pos_min] > a[j]) {
				pos_min = j;
			}
		}

		// Swap that found smallest element to the first index of the sublist
		int temp = a[i];
		a[i] = a[pos_min];
		a[pos_min] = temp;
	}

	// Output sorted array
	for (int i = 0; i < size; i++) std::cout << a[i] << " ";
	std::cout << "\n";
}

// 5. Sometimes we are only interested in knowing the values that would occupy one end of the list if the list were sorted.
// For example, we may want to know the scores of only the top ten competitors in a contest.
// Overload our selection sort method so that it puts the k largest values in order in the last k positions of the array.
// The value of k should be a parameter of the method. 

void selectSort(int* a, int n, int k) {
	for (int i = n - 1; i > (n - 1) - k; i--) {
		int pos_max = 0; // Assuming the first element is the largest

		// Find the actual largest element
		for (int j = 0; j <= i; j++) {
			if (a[pos_max] < a[j]) {
				pos_max = j;
			}
		}

		// Swap that found largest element to the last index of the sublist
		int temp = a[i];
		a[i] = a[pos_max];
		a[pos_max] = temp;
	}
}

int main_303() {
	// Q1
	std::cout << "Q1\n";
	selectionQ1();

	// Q4
	std::cout << "Q4\n";
	selectionQ4a();

	// Or alternatvely
	// int a[] = { 8,9,6,1,2,4 };
	// selectionSort(a, 6);

	// Q5
	std::cout << "Q5\n";
	int N; std::cin >> N;
	int K; std::cin >> K;
	int* b = new int[N];
	for (int i = 0; i < N; i++) std::cin >> b[i];
	selectSort(b, N, K);

	// Output sorted array
	for (int i = 0; i < N; i++) {
		std::cout << b[i] << " ";
	}

	delete[] b;
	return 0;
}