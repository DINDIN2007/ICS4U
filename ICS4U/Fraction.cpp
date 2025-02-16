#include <iostream>
#include <string>
#include "Fraction.h"

// This is the class file for the Fraction class, and is primarily used in this case to create the member functions

// Static member variables
int Fraction::numOfFractions = 0;

// Default Constructor (just sets the fraction to 1/1)
Fraction::Fraction() {
	this->numerator = 0; 
	this->denominator = 1;
	numOfFractions++;
}

// Parametered Constructor
Fraction::Fraction(int num, int den) {
	this->numerator = num;
	this->denominator = (den == 0) ? 1 : den;
	numOfFractions++;
	simplify();
}

Fraction::Fraction(Fraction& f) {
	this->numerator = f.numerator; 
	this->denominator = f.denominator;
	numOfFractions++;
	simplify();
}

int _gcd(int x, int y) {
	// If y is equal to 0, then gcd(x, y) is x;
	if (y == 0) return x;

	// otherwise gcd(x, y) is gcd(y, x% y), where% is the modulus operator.
	return _gcd(y, x % y);
}

int _lcm(int a, int b) {
	return (a * b) / _gcd(a, b);
}

void Fraction::simplify() {
	int gcd = _gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
}

// Getters
int Fraction::getNumerator() {
	return numerator;
}

int Fraction::getDenominator() {
	return denominator;
}

// Setters
void Fraction::setNumerator(int n) {
	numerator = n;
}

void Fraction::setDenominator(int n) {
	denominator = n;
}

// Prints out fraction in string form
std::string Fraction::toString() {
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

// Non-static arithmetic functions

void Fraction::add(Fraction &f) {
	int lcm = _lcm(this->denominator, f.denominator);
	int num1 = this->numerator * (lcm / this->denominator);
	int num2 = f.numerator * (lcm / f.denominator);

	this->numerator = num1 + num2;
	this->denominator = lcm;
	this->simplify();
}

void Fraction::substract(Fraction& f) {
	int lcm = _lcm(this->denominator, f.denominator);
	int num1 = this->numerator * (lcm / this->denominator);
	int num2 = f.numerator * (lcm / f.denominator);

	this->numerator = num1 - num2;
	this->denominator = lcm;
	this->simplify();
}

void Fraction::multiply(Fraction& f) {
	this->numerator *= f.numerator;
	this->denominator *= f.denominator;
	this->simplify();
}

void Fraction::divide(Fraction& f) {
	this->numerator *= f.denominator;
	this->denominator *= f.numerator;
	this->simplify();
}

// Static Arithemtic Functions

Fraction Fraction::add(Fraction &f, Fraction &g) {
	int lcm = _lcm(f.denominator, g.denominator);
	int num1 = f.numerator * (lcm / f.denominator);
	int num2 = g.numerator * (lcm / g.denominator);
	Fraction ans(num1 + num2, lcm);
	ans.simplify();
	return ans;
}

Fraction Fraction::substract(Fraction& f, Fraction& g) {
	int lcm = _lcm(f.denominator, g.denominator);
	int num1 = f.numerator * (lcm / f.denominator);
	int num2 = g.numerator * (lcm / g.denominator);
	Fraction ans(num1 - num2, lcm);
	ans.simplify();
	return ans;
}

Fraction Fraction::multiply(Fraction &f, Fraction &g) {
	int num = f.numerator * g.numerator;
	int den = f.denominator * g.denominator;
	Fraction ans(num, den);
	ans.simplify();
	return ans;
}

Fraction Fraction::divide(Fraction& f, Fraction& g) {
	int num = f.numerator * g.denominator;
	int den = f.denominator * g.numerator;
	Fraction ans(num, den);
	ans.simplify();
	return ans;
}