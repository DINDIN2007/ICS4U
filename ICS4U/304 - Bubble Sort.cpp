#include <iostream>

// 1. Show the comparisons and exchanges that would take place in using a bubble sort to put the numbers 3 8 3 2 7 5 in ascending order.
// No programming is required for this question - you can write the code to show the insertion sort or you can simply output the values.
// Make sure to output the final sorted array after all the comparisons.
void bubbleSortQ1() {
    std::cout
        << "(3  8)  3  2  7  5\n" // First Pass
        << "3  (8  3)  2  7  5\n"
        << "3  3  (8  2)  7  5\n"
        << "3  3  2  (8  7)  5\n"
        << "3  3  2  7  (8  5)\n"
        << "(3  3)  2  7  5  8\n" // Second Pass
        << "3  (3  2)  7  5  8\n"
        << "3  2  (3  7)  5  8\n"
        << "3  2  3  (7  5)  8\n"
        << "(3  2)  3  5  7  8\n" // Third Pass
        << "2  (3  3)  5  7  8\n"
        << "2  3  (3  5)  7  8\n"
        << "(2  3)  3  5  7  8\n" // Fourth Pass
        << "2  (3  3)  5  7  8\n"
        << "2  3  3  5  7  8\n";  // Final Result
}

// 2. Answer in comments-- 
// What changes would have to be made to the bubbleSort method in order to make it sort values in descending order ?

// To sort the elements in descending order, simply swap each pair of elements in the opposite way 
// (larger element to the left and the smaller one to the right instead)
// This can be done by simply flipping the comparison sign in the if statement

// 3. A variation of the bubble sort is the cocktail shaker sort in which, on odd - numbered passes, large values are carried to the top of the list.
// On even - numbered passes, small values are carried to the bottom of the list.
// Output the first two passes on the following data, and on the last line the array itself. 2 9 4 6 1 7 4

void printBubbleSort(int a[], int size, int x, int y) {
    for (int i = 0; i < size; i++) {
        std::cout << ((i == x) ? "(" : " ") << a[i] << ((i == y) ? ")" : " ");
    }
    std::cout << "\n";
}

void bubbleSortQ3(int a[], int size) {
    // Normally, a loop would be declared here to run these two types of passes until the array is sorted

    // Odd-numbered passes - Moves to the right (Only the 1rst pass)
    for (int j = 0; j < size - 1; j++) {
        // Print the current array on each step
        printBubbleSort(a, size, j, j + 1);
        // Swaps if the element to its left is less than it is
        if (a[j] > a[j + 1]) {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }

    // Even-numbered passes - Moves to the left (Only the 2nd pass)
    for (int j = size - 2; j >= 1; j--) {
        // Print the current array on each step
        printBubbleSort(a, size, j - 1, j);
        // Swaps if the element to its right is more than it is
        if (a[j] < a[j - 1]) {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
        }
    }

    // Prints array after these two passes
    printBubbleSort(a, size, -2, -1); // Using negative values to remove the brackets (since they are out of range)
    return;
}


// 4. Write a method shakerSort to implement the cocktail shaker sort algorithm to arrange an array of double values in ascending order.
// Use a boolean flag to stop processing once the items have been completely sorted.
// Output the sorted array and the swaps that occur in the shakerSort.

void shakerSort(double* a, int size) {
    bool sorted = false; int count = 0;
    while (!sorted) {
        // If this boolean isn't changed, it means that the array was already sorted before the next pass
        sorted = true;

        // Odd-numbered passes
        for (int j = 0; j < size - 1; j++) {
            // Swaps if the element to its left is less than it is
            if (a[j] > a[j + 1]) {
                sorted = false;
                double temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                count++;
            }
        }

        // Checks and then resets the boolean for the even-numbered pass
        if (sorted) break;
        sorted = true;

        // Even-numbered passes
        for (int j = size - 2; j >= 1; j--) {
            if (a[j] < a[j - 1]) {
                sorted = false;
                double temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                count++;
            }
        }
    }

    // Print sorted array
    for (int i = 0; i < size; i++) std::cout << a[i] << " ";
    std::cout << "\n" << count;
}

int main_304() {
    // Q1
    std::cout << "Q1\n";
    bubbleSortQ1();

    // Q3
    std::cout << "Q3\n";
    int a[] = { 2,9,4,6,1,7,4 };
    bubbleSortQ3(a, 7);

    // Q4
    int N; std::cin >> N;
    double* b = new double[N];
    for (int i = 0; i < N; i++) std::cin >> b[i];
    std::cout << "Q4\n";
    shakerSort(b, N);

    delete[] b;
    return 0;
}