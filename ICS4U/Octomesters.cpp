#include <iostream>
#include <algorithm>
#include <vector>

long long N, K;

int main_octomester() {
	std::cin >> N >> K;
	std::vector<long long> testDays;

	for (int i = 0; i < N; i++) {
		long long value; std::cin >> value;
		testDays.push_back(value);
	}

	sort(testDays.begin(), testDays.end());

	long long excess{ 0 }, totalDaysNeeded{ K };

	for (int i = 1; i < N; i++) {
		// Calculate how much days are needed in advance for this particular test
		long long daysNeeded{ K - (testDays[i] - (testDays[i - 1] + excess)) };

		// Adds more days if there needs to be any before the first test
		if (daysNeeded > 0) {
			totalDaysNeeded += daysNeeded;
			excess = 0;
		}

		// If not, add more to "excess" for other tests
		else excess = daysNeeded;
	}

	std::cout << totalDaysNeeded;

	return 0;
}