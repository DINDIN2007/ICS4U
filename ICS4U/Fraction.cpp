#include <iostream>
#include <string>
#include "Fraction.h"

// This is the class file for the Fraction class, and is primarily used in this case to create the member functions

// Default Constructor (just sets the fraction to 1/1)
Fraction::Fraction() {
	Numerator = 1; Denominator = 1;
}

// Parametered Constructor
Fraction::Fraction(int num, int den) {
	Numerator = num; Denominator = den;
}

// Getters
int Fraction::getNumerator() {
	return Numerator;
}

int Fraction::getDenominator() {
	return Denominator;
}

// Setters
void Fraction::setNumerator(int n) {
	Numerator = n;
}

void Fraction::setDenominator(int n) {
	Denominator = n;
}

// Prints out fraction in string form
std::string Fraction::toString() {
	return std::to_string(Numerator) + "/" + std::to_string(Denominator);
}
