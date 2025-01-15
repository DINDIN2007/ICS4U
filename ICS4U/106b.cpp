#include <iostream>
#include <vector>
#include <cmath>

int min, max, range, directionCount = 0, width, height;
int directions[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
bool needSpace = false;

int** grid;

void findNextNum(int value, int x, int y) {
	int newX = x + directions[directionCount][0];
	int newY = y + directions[directionCount][1];

	int nextDirection = (directionCount + 1) % 4;
	int checkX = x + directions[nextDirection][0];
	int checkY = y + directions[nextDirection][1];

	// Check if direction change is necessary
	if (grid[checkX][checkY] == -1) {
		directionCount = nextDirection;
		newX = checkX; newY = checkY;
	}

	grid[newX][newY] = value;
	if (value < max) findNextNum(value + 1, newX, newY);
}

int main_206b() {
	std::cin >> min >> max;

	// That one case
	if (min == max) {
		std::cout << min << "\n";
		return 0;
	}
	
	// Find the difference between the two numbers
	range = max - min + 1;

	// Reaarange vector to fit the range of the numbers
	width = (int)(std::round(std::sqrt(range))), height = width + 1;

	grid = new int*[height];

	for (int i = 0; i < height; i++) {
		int* gridRow = new int[width];
		for (int j = 0; j < width; j++) {
			gridRow[j] = -1;
		}
		grid[i] = gridRow;
	}

	// Start the spiral
	// Start the spiral
	grid[width / 2][height / 2 - 1] = min;
	findNextNum(min + 1, width / 2, height / 2 - 1);
	
	// Print Result
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int value = grid[i][j];
			if (value != -1) {
				if (value < 10) std::cout << " ";
				std::cout << value;
			}
			else {
				std::cout << "  ";
			}

			if (j != width - 1) std::cout << " ";
		}
		std::cout << "\n";
	}

	for (int i = 0; i < height; i++)
		delete[] grid[i];

	delete[] grid;

	return 0;
}