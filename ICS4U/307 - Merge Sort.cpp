#include <iostream>
#include <string>

// Write the program to implement merge sort. Given an array of N strings.
int N, numOfMerges = 0;

void merge(std::string* arr, int start, int mid, int end) {
	// Create a temporary array to store the sorted values of this merge
	std::string* temp_arr = new std::string[N];
	// Creates position 1 and 2 to slowly compare elements from each array
	int pos_1 = start, pos_2 = mid + 1;
	// Keeps the current position of the temporary element
	int current_pos = start;

	// Runs this loop until all item from each array have been checked
	while (!(pos_1 > mid && pos_2 > end)) {
		bool itemOnLeftAreChecked = pos_1 > mid;
		bool itemOnRightAreChecked = pos_2 > end;

		// Cases for putting element on array on the right
		if (itemOnLeftAreChecked || (!itemOnRightAreChecked && (arr[pos_2] < arr[pos_1]))) {
			temp_arr[current_pos] = arr[pos_2];
			pos_2++;
		}
		// Cases for putting element on array on the left
		else {
			temp_arr[current_pos] = arr[pos_1];
			pos_1++;
		}
		// Continues along the temporary array
		current_pos++;
	}

	// Copy the elements back into the original array in the sorted manner
	for (int i = start; i <= end; i++) {
		arr[i] = temp_arr[i];
	}

	delete[] temp_arr;
}

void mergeSort(std::string* arr, int start, int end) {
	// Prevents trying to sort a subarray of 1 element (since it doesn't really need to be sorted)
	if (start < end) {
		// Finds the middle element in the array
		int mid = (start + end) / 2;
		// Sorts the element on the left
		mergeSort(arr, start, mid);
		// Sorts the element on the right
		mergeSort(arr, mid + 1, end);
		// Merge the two subarrays above
		merge(arr, start, mid, end);
	}
	numOfMerges++;
}

int main_307() {
	std::cin >> N;
	std::string* arr = new std::string[N];
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	mergeSort(arr, 0, N - 1);
	std::cout << numOfMerges << "\n";
	for (int i = 0; i < N; i++) {
		std::cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}