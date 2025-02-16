#include <iostream>
#include "Fraction.h"

// Code to test out Fraction class

int main() {
	// Test Default Fraction
	Fraction f1;
	std::cout << "The fraction f1 is set to default : " << f1.toString() << ".\n";

	// Test Getters and Setters
	std::cout << "It's numerator is " << f1.getNumerator() << " and will be changed to 10.\n";
	f1.setNumerator(10);
	std::cout << "It's denominator is " << f1.getDenominator() << " and will be changed to 12.\n";
	f1.setDenominator(12);
	std::cout << "The fraction f1 is now " << f1.toString() << ".\n";
	f1.simplify();
	std::cout << "The simplified fraction f1 is " << f1.toString() << ".\n\n";

	// Test Parameterized Fraction
	Fraction f2(2, 3);
	std::cout << "The fraction f2 is set to " << f2.toString() << ".\n\n";

	// Test Non-Static Functions
	f1.add(f2);
	std::cout << "The fraction f1 is set to it's sum with f2 : " << f1.toString() << ".\n";
	f1.substract(f2);
	std::cout << "This new fraction f1 is set to it's difference with f2 : " << f1.toString() << ".\n";
	f1.multiply(f2);
	std::cout << "This new fraction f1 is set to it's product with f2 : " << f1.toString() << ".\n";
	f1.divide(f2);
	std::cout << "This new fraction f1 is set to it's quotient with f2 : " << f1.toString() << ".\n\n";

	// Test Copy Constructor
	Fraction f3(f1), f4(f2);
	std::cout << "Set fraction f3 to be the same as f1 : " << f3.toString() << ".\n";
	std::cout << "Set fraction f4 to be the same as f2 : " << f4.toString() << ".\n\n";

	// Test Static Functions
	std::cout << "Add f3 and f4 : " << Fraction::add(f3, f4).toString() << ".\n";
	std::cout << "Substract f3 and f4 : " << Fraction::substract(f3, f4).toString() << ".\n";
	std::cout << "Multiply f3 and f4 : " << Fraction::multiply(f3, f4).toString() << ".\n";
	std::cout << "Divide f3 and f4 : " << Fraction::divide(f3, f4).toString() << ".\n";

	return 0;
}