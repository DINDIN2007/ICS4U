#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>

// This is the header file where the Fraction class is declared along with its member variables and functions

class Fraction {
private:
	// Variables
	int numerator, denominator;
	static int numOfFractions;
public:
	// Default Constructor
	Fraction();
	// Parameterized Constructor
	Fraction(int num, int den);
	// Copy Constructor
	Fraction(Fraction &f);

	// Get/Set Functions
	int getNumerator(), getDenominator();
	void setNumerator(int n), setDenominator(int d);

	// Other Functions
	void simplify();

	void add(Fraction &f);
	void substract(Fraction &f);
	void multiply(Fraction &f);
	void divide(Fraction &f);

	static Fraction add(Fraction &f, Fraction &g);
	static Fraction substract(Fraction &f, Fraction &g);
	static Fraction multiply(Fraction &f, Fraction &g);
	static Fraction divide(Fraction &f, Fraction &g);

	// Function to output the Fraction
	std::string toString();
};

#endif