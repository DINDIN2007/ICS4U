#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::string input;

int main_palindrome_2() {
	std::getline(std::cin, input);
	
	int maxPalindrome{ 0 };
	int counter = input.size();

	for (int i = input.size(); i > 0; i--) {
		for (int j = 0; j <= input.size() - counter; j++) {
			std::string sub_str = input.substr(j, counter), rev_str = input.substr(j, counter);
			reverse(rev_str.begin(), rev_str.end());
			if (sub_str == rev_str) {
				maxPalindrome = std::max(counter, maxPalindrome);
				break;
			}
		}
		counter--;
	}

	std::cout << maxPalindrome;

	return 0;
}