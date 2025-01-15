#include <iostream>
#include <iomanip>
#include <math.h>
#include <assert.h>

// Q1
// Create a void function cubeByPointer() that will find the cube of a number using pointer as an argument of a function.[3]
void cubeByPointer(int* pointer) {
	*pointer = (int)(pow(*pointer, 3));
}

// Q2
// Create a void function reduceTwoInt() that will have 2 pointers as arguments, a numerator and denominator and will reduce the two integers.[3]
void reduceTwoInt(int* numerator, int* denominator) {
    for (int i = std::min(std::abs(*numerator), std::abs(*denominator)); i >= 1; i--) {
        if (*numerator % i == 0 && *denominator % i == 0) {
            *numerator /= i; *denominator /= i;
        }
    }
}

// Q3
// Create a void function circle() that will have a radius and 2 pointers as arguments, and will calculate the area and circumference of a circle.[3]
void circle(double radius, double* area, double* circumference) {
	double PI = 3.14159265358979323846;
	*area = pow(radius, 2) * PI;
	*circumference = 2 * radius * PI;
}

// Q4
// Create a boolean function quadEquation() that calculates the solutions to quadratic equations.[5]
bool quadEquation(int a, int b, int c, double* solution1, double* solution2) {
    double discriminent = pow(b, 2) - 4 * a * c; if (discriminent < 0) return false;
	*solution1 = (-b - sqrt(discriminent)) / (2.0 * a);
	*solution2 = (-b + sqrt(discriminent)) / (2.0 * a);
	return true;
}

// Q5
// The version of swap() listed below can be compiled without producing any error messages.
// However, the function will not swap the values x and y when swap(&x, &y) is called. 
// What is wrong ? (answer in comments) Create a function that will correctly swap the values.[4]
void swap(float* p1, float* p2) {
	float* temp;
	temp = p1;		// Refered to the point p1
	p1 = p2;		// Set p1 to the same pointer as p2, which sets temp to the same pointer as p1
	p2 = temp;		// Set p2 to the same pointer as temp, which was set to p2 in the first place, so p2 doesn't change at all
}

void swap_correct(float* p1, float* p2) {
	float temp; temp = *p1;
	*p1 = *p2; *p2 = temp;
}

// Q6
// Given that if a and b are the real and imaginary parts of a complex number a + bi,
// then that number squared has the real and imaginary parts a2−b2 and 2ab, respectively.
// Explain your changes in comments.[4]
// Find and fix the bug in the following code :

void SquareComplex(double& a, double& b) {
	// Squares a complex number a + bi
	a = a * a - b * b;	// Changes the value of a
	b = 2 * a * b;		// Value of a is changed and therefore affects b in a wrong way
}

void SquareComplex_correct(double& a, double& b) {
	// Store a into a temporary variable first
	double temp = a;
	a = a * a - b * b;
	b = 2 * temp * b;
}

int main_203() {
    // Q1 Testing code (Expected value should be 8)
    int num = 2;
    std::cout << "Cube of " << num << " is ";
    cubeByPointer(&num);
    std::cout << num << std::endl;

    // Q2 Testing code (Expected value should be 6/15  = 2/5)
    int numB = 15; int numA = 6;
    reduceTwoInt(&numA, &numB);
    std::cout << "The reduced values are: " << (numA) << "/" << (numB) << std::endl;

    // Q3 Testing code (Expected value should be 9 * pi and 6 * pi for area and circumference)
    double areaStored, circStored;
    double radius = 3;
    circle(radius, &areaStored, &circStored);
    std::cout << std::setprecision(6) << "\nArea: " << areaStored << std::endl;
    std::cout << std::setprecision(6) << "Circumference: " << circStored << std::endl << std::endl;

    // Q4 Testing code (use asserts to test validity of function return values)
    double sol1, sol2;
    if (quadEquation(2, -8, -10, &sol1, &sol2)) {// Expected solutions are -1 and 5
        // Output solutions
        // setprecision(6) limits output to 6 significant units

        std::cout << "Solution 1: " << std::setprecision(6) << sol1 << std::endl;
        std::cout << "Solution 2: " << std::setprecision(6) << sol2 << std::endl;
    }
    else {
        std::cout << "No Solution" << std::endl;
    }

    if (quadEquation(1, 0, 0, &sol1, &sol2)) { // Expected solution is 0
        // Output solutions
        // setprecision(6) limits output to 6 significant units

        std::cout << "Solution 1: " << std::setprecision(6) << sol1 << std::endl;
        std::cout << "Solution 2: " << std::setprecision(6) << sol2 << std::endl;
    }
    else {
        std::cout << "No Solution" << std::endl;
    }

    if (quadEquation(6, 6, 3, &sol1, &sol2)) { // Expected output is no real solutions
        // Output solutions
        // setprecision(6) limits output to 6 significant units

        std::cout << "Solution 1: " << std::setprecision(6) << sol1 << std::endl;
        std::cout << "Solution 2: " << std::setprecision(6) << sol2 << std::endl;
    }
    else {
        std::cout << "No Solution" << std::endl;
    }

    // Q5 Testing code
    float val1 = 0, val2 = 1;
    swap_correct(&val1, &val2);
    assert(val1 == 1);
    assert(val2 == 0);
    std::cout << "Swapped: " << val1 << " " << val2 << std::endl << std::endl; // Expected value should be 1 0

    // Q6 Testing code 
    double a = 5, b = 2;
    SquareComplex_correct(a, b); // Expected output should be 21 + 20i (21 and 20)

    std::cout << std::setprecision(6) << "Squared real: " << a << std::endl;
    std::cout << std::setprecision(6) << "Squared imaginary: " << b << std::endl;
    std::cout << std::setprecision(6) << a << " + " << b << "i" << std::endl;

    return 0;
}
