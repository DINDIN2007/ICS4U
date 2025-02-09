#include <iostream>
#include "Fraction.h"

// Code to test out Fraction class

int main() {
	Fraction fraction(5, 4);
	std::cout << "The numerator of the fraction is " << fraction.getNumerator() << ".\n";
	fraction.setNumerator(3);
	std::cout << "The new fraction is " << fraction.toString() << ".\n";
	return 0;
}