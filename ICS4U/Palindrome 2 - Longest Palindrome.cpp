#include <iostream>
#include <string>
#include <vector>

std::string input;

int main() {
	std::getline(std::cin, input);
	
	int maxPalindrome{ 0 };
	int counter = input.size();

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j <= input.size() - counter; j++) {
			std::string sub_str = input.substr(), ;
		}
		counter++;
	}

	return 0;
}