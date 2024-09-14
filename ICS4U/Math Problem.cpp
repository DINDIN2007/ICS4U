#include <iostream>
#include <cmath>

int A, B;

int main() {
	// Get our numbers first
	std::cin >> A >> B;

	// Find the maximum for valid z
	int max_z = (int)(sqrt(B));

	// Check for case A = 0, where it simply becomes y^2 + z^2 = B
	if (A == 0) {
		// If B is also 0, then x, y and z can only be 0
		if (B == 0) {
			std::cout << 0 << " " << 0 << " " << 0;
			return 0;
		}

		// Otherwise, find a pair of y an z that matches y^2 + z^2 = B
		for (int i = 1; i <= max_z; i++) {
			for (int j = i; j <= max_z; j++) {
				if (i * i + j * j == B) {
					std::cout << 0 << " " << i << " " << j;
					return 0;
				}
			}
		}

		// If the loop above yields no result
		std::cout << -1;
		return 0;
	}
	
	// Check for case B = 0, where if A != 0, then there is no solution
	if (B == 0) {
		if (A == 0) std::cout << 0 << " " << 0 << " " << 0;
		else std::cout << -1;
	}

	// Loop to find a possible value for the triple
	for (int i = 1; i <= max_z; i++) {
		for (int j = i; j <= max_z; j++) {
			if (A % (j * i) == 0 && i * i + j * j + (A / (j * i)) * (A / (j * i)) == B) {
				std::cout << i << " " << j << " " << (A / (j * i));
				return 0;
			}
		}
	}

	std::cout << -1;
	return 0;
}