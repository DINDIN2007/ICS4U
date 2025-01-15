#include <iostream>

// Write the program to implement quick sort. 
// Given an array of N integers, start with the first value as your pivot and use the first values of the subarrays as pivots thereon. 
// (As explained in the note)

void quickSort(int* arr, int low, int high) {
	const bool MOVING_LEFT = true, MOVING_RIGHT = false;

	// If this if-statement doesn't work, it means there is only 1 statement (which doesn't need to be sorted)
	if (low < high) {
		// Setting the left and right as the two ends of the subarray
		int left = low, right = high;
		// Always starts the sort by moving from right to left
		bool current_direction = MOVING_LEFT;
		// Sets the pivot as the first element of the subarray
		int pivot = arr[low];

		// Print pivot and subarray
		std::cout << pivot << " [" << low << " " << high << "]\n";

		// Runs until left and right represent the same element
		while (left < right) {
			if (current_direction == MOVING_LEFT) {
				// Runs until it either gets to where pivot is supposed to be, or until it finds an element smaller than it is
				while (pivot <= arr[right] && left < right) {
					right--;
				}
				// When it finds that element that is smaller than it is, move it to the other side of the pivot
				arr[left] = arr[right];
				// Start moving from left to right
				current_direction = MOVING_RIGHT;
			}

			if (current_direction == MOVING_RIGHT) {
				// Runs until it either gets to where pivot is supposed to be, or until it finds an element larger than it is
				while (pivot >= arr[left] && left < right) {
					left++;
				}
				// When it finds that element that is larger than it is, move it to the other side of the pivot
				arr[right] = arr[left];
				// Start moving from right to left
				current_direction = MOVING_LEFT;
			}
		}

		// Sets the pivot point at its intended position
		arr[left] = pivot;
		// Sorts the element on the left of the pivot in the subarray
		quickSort(arr, low, left - 1);
		// Sorts the element on the right of the pivot in the subarray
		quickSort(arr, left + 1, high);
	}
}

// At every step, output the pivot on a new line and the range of the subarray.
int main_306() {
	int N; std::cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	quickSort(arr, 0, N - 1);
	
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}

// Please ignore this part, it was to figure out how the algorithm worked

// Pivot 61, Sub Array = [0 12]
// |61|46 12 63 52 91 27 55 74 14 71 37|87|
// |61|46 12 63 52 91 27 55 74 14 71|37|87	Moves to the left
// |37|46 12 63 52 91 27 55 74 14 71|37|87	
//  37 46 12|63|52 91 27 55 74 14 71|37|87	Moves to the right
//  37 46 12|63|52 91 27 55 74 14 71|63|87
//  37 46 12|63|52 91 27 55 74|14|71 63 87	Moves to the left
//  37 46 12|14|52 91 27 55 74|14|71 63 87
//  37 46 12 14 52|91|27 55 74|14|71 63 87	Moves to the right
//  37 46 12 14 52|91|27 55 74|91|71 63 87
//  37 46 12 14 52|91|27|55|74 91 71 63 87  Moves to the left
//  37 46 12 14 52|55|27|55|74 91 71 63 87
//  37 46 12 14 52 55 27|55|74 91 71 63 87	Moves to the right
//  37 46 12 14 52 55 27|61|74 91 71 63 87

// Pivot 37, Sub Array = [0 6]
// |37|46 12 14 52 55|27|	Moves to the left
// |27|46 12 14 52 55|27|
//  27|46|12 14 52 55|27|	Moves to the right
//  27|46|12 14 52 55|46|
//  27|46|12|14|52 55 46	Moves to the left
//  27|14|12|14|52 55 46
//  27 14 12|14|52 55 46	Moves to the right
//  27 14 12|37|52 55 46

// Pivot 27, Sub Array = [0 2]
// |27|14|12|	Moves to the left
// |12|14|12|	
//  12 14|12|	Moves to the right
//  12 14|27|

// Pivot 12, Sub Array = [0 1]
// |12|14|	Moves to the left
// |12|14

// Pivot 52, Sub Array = [4 6]
// |52|55|46|	Moves to the left
// |46|55|46|
//  46|55|46|	Moves to the right
//  46|55|55|
//  46|55|55	Moves to the left
//	46|52|55

// Pivot 74, Sub Array = [8 12]
// |74|91 71 63|87|
// |74|91 71|63|87	Moves to the left
// |63|91 71|74|87
//  63|91|71|74|87	Moves to the right
//  63|91|71|91|87
//  63|91|71|91 87	Moves to the left
//  63|71|71|91 87
//  63 71|71|91 87	Moves to the right
//  63 71|74|91 87