#include <iostream>
#include <string>

// Q1. An insertion sort is to be used to put the values[6, 2, 8, 3, 1, 7, 4]
// in ascending order(lowest to highest).Show the values as they would appear after each pass of the sort.
// No programming is required for this questions
// you can write the code to show the insertion sort or you can simply output the values;

void insertionQ1() {
	std::cout
		<< "6 2 8 3 1 7 4\n" // Initial Array
		<< "2 6 8 3 1 7 4\n" // Checked 2nd element and swapped until it was sorted with element on the left
		<< "2 6 8 3 1 7 4\n" // Checked 3rd element which doesn't need to be rearranged
		<< "2 3 6 8 1 7 4\n" // Checked 4th element and swapped until it was sorted with element on the left
		<< "1 2 3 6 8 7 4\n" // Checked 5th element and swapped until it was sorted with element on the left
		<< "1 2 3 6 7 8 4\n" // Checked 6th element and swapped until it was sorted with element on the left
		<< "1 2 3 4 6 7 8\n";// Checked 7th element and swapped until it was sorted with element on the left
}

// Q2. Answer in comments - 
// What changes would have to be made to the insertion_sort method in order to sort the values in descending order ?

	// 6 2 8 3 1 7 4
	// 8 6 2 3 1 7 4
	// 8 6 3 2 1 7 4
	// 8 7 6 3 2 1 4
	// 8 7 6 4 3 2 1

// Tldr instead of swapping the values when the current number being compared is smaller than the previous one, do it when the current number is larger than the previous one

// Q3. Write a program that initializes an array with the names of the planets 
// in their typical order(from closest to furthest from the Sun) and 
// prints them in that order on one line.The program should then use an insertion sort algorithm
// to arrange the names alphabetically.To trace the progress of the sort, have it print the list
// after each pass.

void insertionQ3() {
	// Inititalized the array containing the names of the planets
	std::string planets[8] = { "mercury", "venus", "earth", "mars", "jupiter", "saturn", "uranus", "neptune" };
	for (std::string planet : planets) std::cout << planet << " ";
	std::cout << "\n";

	int count;
	std::string temp;

	for (int i = 1; i < 8; i++) {
		count = i;
		// Check if the current element needs to be resorted with the left side
		while (count > 0 && planets[count] < planets[count - 1]) {
			// Swap this element with the previous
			temp = planets[count - 1];
			planets[count - 1] = planets[count];
			planets[count] = temp;
			// Continue swapping until the element before is smaller than this one
			count--;
		}

		for (std::string planet : planets) std::cout << planet << " ";
		std::cout << "\n";
	}
}

// Q4. The median of an ordered list of numerical values is defined in the following way :
// If the number of values is odd, the median is the middle value. If the number of values is even, 
// the median is the average of the two middle values.
// Write a program that prompts the user for the number of items to be processed,
// reads that many real values, and then finds their median.

double insertionQ4(double* a, int size) {
	double temp; int count;
	for (int i = 1; i < size; i++) {
		count = i;
		// Check if the current element needs to be resorted with the left side
		while (count > 0 && a[count] < a[count - 1]) {
			// Swap this element with the previous
			temp = a[count - 1];
			a[count - 1] = a[count];
			a[count] = temp;
			// Continue swapping until the element before is smaller than this one
			count--;
		}
	}

	if (size % 2 == 1) {
		return a[size / 2];
	}
	return (a[size / 2] + a[size / 2 - 1]) / 2.0;
}

// Q5. Answer in comments- 
// A sort is said to be stable if it always leaves values that are considered to be equal 
// in the same order after the sort. Is the insertion sort stable ? Justify your answer.

// Insertion sort remains stable because when it encounters equal elements, it maintains their original relative order by sliding elements over to their correct position on the sorted list rather than arbitrarily swapping them.

int main_302() {
	int n; std::cin >> n;
	double* a = new double[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::cout << "Q1\n"; insertionQ1();
	std::cout << "Q3\n"; insertionQ3();
	std::cout << "Q4\n"; std::cout << insertionQ4(a, n);
	return 0;
}