#ifndef FRACTION_H_
#define FRACTION_H_

// This is the header file where the Fraction class is declared along with its member variables and functions

class Fraction {
private:
	// Variables
	int Numerator, Denominator;
public:
	// Default Constructor
	Fraction();
	// Parameterized Constructor
	Fraction(int, int);

	// Get/Set Functions
	int getNumerator(), getDenominator();
	void setNumerator(int), setDenominator(int);

	// Function to output the Fraction
	std::string toString();
};

#endif