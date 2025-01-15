#include <iostream>

// 1. Given the following data, show how they would appear after they have been 5 - sorted. 26 37 21 41 63 19 61 72 55 29 47 18 26 22

// 26 37 21 41 63 19 61 72 55 29 47 18 26 22

void shellSortQ1() {
	// 26             19             47				-->		19             26             47
	//    37             61             18			-->		   18             37             61
	//       21             72             26		-->		      21             26             72
	//          41             55             22	-->		         22             41             55
	//             63             29				-->		            29             63
	// Sorted List : 19 18 21 22 29 26 37 26 41 63 47 61 72 55

	int arr[] = { 26,37,21,41,63,19,61,72,55,29,47,18,26,22 };
	int length = 14, k = 5;

	// 1. Determine the starting k-value for each sublist
	for (int start = 0; start <= k - 1; start++) {
		// 2. Figure out the next "top" element that is k away from the current one
		for (int top = start + k; top < length; top = top + k) {
			// 3. Insert element found at top into its correct position
			int item = arr[top]; //temporary store for current item
			int i = top;
			// Insertion sort
			while (i > start && item < arr[i - k])
			{
				arr[i] = arr[i - k];	// shift larger items to the right by k
				i = i - k;				// prepare to check the next item, k spaces left
			}
			arr[i] = item; // put sorted item in open and correct location
		}
	}
	
	// Print 5-sorted array
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

// 2. Starting with the same set of data from question 1, show how they would appear 4 - sorted after it is 5 - sorted.

void shellSortQ2() {
	// 19		   29			 41			  72		-->		19		   29			 41			  72		
	//    18		  26		    63			 55		-->		   18		  26		    55			 63		
	//       21			  37		   47				-->		      21		 37		       47				
	//          22			  26		  61			-->		         22		    26		      61			
	// Sorted List : 19 18 21 22 29 26 37 26 41 55 47 61 72 63

	// arr in this case contains the values found in the 5-sorted list of question 1
	int arr[] = { 19,18,21,22,29,26,37,26,41,63,47,61,72,55 };
	int length = 14, k = 4;

	// 1. Determine the starting k-value for each sublist
	for (int start = 0; start <= k - 1; start++) {
		// 2. Figure out the next "top" element that is k away from the current one
		for (int top = start + k; top < length; top = top + k) {
			// 3. Insert element found at top into its correct position
			int item = arr[top]; //temporary store for current item
			int i = top;
			// Insertion sort
			while (i > start && item < arr[i - k])
			{
				arr[i] = arr[i - k];	// shift larger items to the right by k
				i = i - k;				// prepare to check the next item, k spaces left
			}
			arr[i] = item; // put sorted item in open and correct location
		}
	}

	// Print 4-sorted array
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

// 3. Answer in comments.
// How would you answer the following argument against using Shell Sort ? 
// "The last step of Shell Sort, using k = 1, is simply a normal insertion sort. 
// Since Shell Sort performs many preliminary steps before this final one, it must be slower than a single insertion sort."

// The argument misses the point that Shell Sort's preliminary steps help move elements closer to their final positions (often over large distances), 
// making the final insertion sort step faster and overall more efficient than just using a single insertion sort.

// 4. Suppose you were going to write a version of Shell Sort using the sequence of k - sorts suggested previously.
// For a list containing n elements, the first value of k that should be used is the largest value in the sequence 
// that is less than or equal to n / 3 (n divided by 3).

// Each term in the sequence is defined as the value three times the previous term, plus one.
// The last term is the largest term that is equal or less than ⌈N/3⌉.

// For example, in a list of 150 elements, the largest k value would be 40, so the first pass should be 40 - sorted.

// (a) Write a sequence of statements that will initialize k correctly for a given value of n.

int shellSortQ3a(int n) {
	int k = 1;
	// Find the next term (by multiplying by 3 and adding 1) until it is larger than n/3
	while (k * 3 + 1 < n / 3) {
		k = k * 3 + 1;
	}
	return k;
}

// (b) Write a statement that will, for any value of k in the sequence, produce the next smaller value of k.

int shellSortQ3b(int k) {
	int nextK = (k - 1) / 3;
	return nextK;
}

// 4. Shell Sort Algorithm

// (a) Write a method shellSort to sort an array of int values in ascending order. In performing the k - sorts, 
// use the sequence of values of k suggested in the text(1, 4, 13, 40, ...).
// Be sure to use insertion sort at each stage of the sort.

void kSortSublist(int* arr, int k, int start, int length) {
	for (int top = start + k; top < length; top = top + k) {
		int item = arr[top]; //temporary store for current item
		int i = top;
		while (i > start && item < arr[i - k])
		{
			// shift larger items to the right by k
			arr[i] = arr[i - k];
			// prepare to check the next item, k spaces left
			i = i - k;
		}
		arr[i] = item; // put sorted item in open location
	}
}

// (b)Test your method by writing a complete program that first reads in an array of random int values in the range[0, 999], 
// sorts the array using your shellSort method, and then prints the resulting array(ten values per line).

void shellSort(int* arr, int length) {
	int k = shellSortQ3a(length);
	
	while (k > 0) {
		std::cout << k << "k sort list:\n";
		for (int start = 0; start <= k - 1; start++) {
			kSortSublist(arr, k, start, length);
		}
		for (int i = 0; i < length; i++) {
			std::cout << arr[i] << " ";
			if ((i + 1) % 10 == 0) std::cout << "\n";
		}
		std::cout << "\n\n";

		k = shellSortQ3b(k);
	}
}

// Experiment with using Shell Sort with sequences where k is other than the suggested values, 
// testing your sequences on large arrays of integers and noting the time required by the sort in each case.
// To measure the time taken by a sort, you can use the method ftime() from the <sys / timeb.h> header.
// The.time and .millitm properties of the timeb struct both return a value, representing the time in seconds since midnight, January 1, 1970.

void shellSortQ6();

// Log your experimentation in comments. Do your timed searches show the k value refered to in the notes as the ideal ?

/* For a random array of 150 elements
Time measured for k = 2: 676500 ms
Time measured for k = 3: 455200 ms
Time measured for k = 4: 458200 ms
Time measured for k = 5: 321700 ms
Time measured for k = 6: 304200 ms
Time measured for k = 7: 288900 ms
Time measured for k = 8: 248500 ms
Time measured for k = 9: 267300 ms
Time measured for k = 10: 222400 ms
Time measured for k = 11: 220700 ms
Time measured for k = 12: 258500 ms
*/

// For a random array of 1500 elements, the datapoints of (k value, time it took to sort) form this graph : 
// https://www.desmos.com/calculator/2fjdgpei9w	// The ideal k value for 1500 elements (121) is marked by the purple line

// Overall, from these two experiment, k is clearly not the most ideal value as there were many other k values that needed less to sort the array
// However, it is important to note that k is consistently an somewhat average case (not the worse nor the best)
// and that each k value trials didn't have the same random arrays (some being more sorted intitially than others).

int main_305() {
	// Q1
	std::cout << "Q1\n";
	shellSortQ1();

	// Q2
	std::cout << "Q2\n";
	shellSortQ2();

	// Q5
	std::cout << "Q5\n";
	int n; std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	shellSort(arr, n);

	// Q6
	// shellSortQ6();

	delete[] arr;
	return 0;
}

// Used <chrono> library instead since it gave more precise numbers

#include <chrono>       // For high precision timing (chrono)
#include <algorithm>    // For std::copy
#include <cstdlib>      // For rand()
#include <ctime>        // For seeding random number generator

unsigned long long GetTimeMs64() {
	auto start = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::nanoseconds>(start.time_since_epoch()).count();
}

// Shell Sort Function made to try different k values
void shellSortQ6() {
	// Randomly generated 150 elements array
	int staticArr[1000];
	int length = 1000;

	// Seed random number generator for unique results each time
	std::srand(std::time(0));

	// Fill the array with random integers between 0 and 999
	for (int i = 0; i < length; i++) {
		staticArr[i] = std::rand() % 1000;  // Random number between 0 and 999
	}

	// Allocate memory for a pointer array (to match the ShellSort Parameters)
	int* arr = new int[length];

	// Find the ideal k value from the proposed sequence
	int idealValue = shellSortQ3a(length);

	std::cout << idealValue << "\n\n";

	// Loop over k values from a range from the previous ideal term in the sequence to the next one
	for (int k = (idealValue - 1) / 3 + 1; k <= idealValue * 3; k++) {
		// Copy the static array into arr for each k
		std::copy(std::begin(staticArr), std::end(staticArr), arr);

		unsigned long long startTime = GetTimeMs64();

		// Perform the k-sorting for the current k value
		for (int start = 0; start < k; start++) {
			kSortSublist(arr, k, start, length);
		}
		kSortSublist(arr, 1, 0, length);  // Perform the final insertion sort with k = 1

		// Get time it took to do that sorting
		unsigned long long duration = GetTimeMs64() - startTime;
		std::cout << "(" << k << ", " << duration << "), ";
	}

	delete[] arr; // Free the allocated memory
}