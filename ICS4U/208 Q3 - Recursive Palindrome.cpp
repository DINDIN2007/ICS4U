#include <iostream>
#include <string>

// a) Create a function reverse that returns the reverse of a string.
std::string reverse(std::string value) {
	if (value.size() == 1) return value;
	return value[value.size() - 1] + reverse(value.substr(0, value.size() - 1));
}

// b) Create a function isPalindrome that returns whether a string input is a palindrome, ignoring casing and whitespace.
bool isPalindrome(std::string value) {
	int first = 0, last = value.size() - 1;

	if (first != last) {
		while (value[first] == ' ') first++;
		while (value[last] == ' ') last--;

		if (first == last) return true;

		std::string remainder = value.substr(first + 1, last - first - 1);
		return (tolower(value[first]) == tolower(value[last])) && isPalindrome(remainder);
	}

	return true;
}

int main_208Q3() {
	std::string input;
	std::getline(std::cin, input);
	std::cout << reverse(input) << "\n" << (isPalindrome(input) ? "true" : "false");
	return 0;
}