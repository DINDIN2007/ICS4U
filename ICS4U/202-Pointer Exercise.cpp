#include <iostream>

int main_202() {
	// Q1
	// Declare a variable number, and a pointer variable* pnumber as a pointer to an integer.

	int number;
	int* pnumber;

	// Initialize number to 123 and *pnumber to address of number.
	number = 123;
	pnumber = &number;

	// Print out the following : value of variable number, address of number, value of pnumber and the value of* pnumber.
	std::cout << number << "\n" << &number << "\n" << pnumber << "\n" << *pnumber << "\n";

	// Q2
	// Declare two integer variables num1 and num2 and initialize them to 50 and 100 respectively.
	int num1 = 50, num2 = 100;

	// Declare and initialize to NULL a pointer variable * pnum.
	// Let pnum point to num1, then increment num1 by 10 by using* pnum.
	// Now, output the value of num1 and pnum.
	int* pnum = NULL;
	pnum = &num1; *pnum += 10;

	// Next, let pnum point to num2, then multiply num2 by 10 by using* pnum and assign its value to num1.
	// Now, output the values of num1, pnum and *pnum.
	pnum = &num2; num1 = *pnum * 10;
	std::cout << num1 << "\n" << pnum << "\n" << *pnum << "\n";

	// Q3
	// For each of the following, write a single statement that performs the indicated task.

	// Assume that variables value1 and value2 of type double have been declared and that value1 has been initialized to 200000.
	double value1 = 200000, value2;

	// a) Declare the variable lPtr to be a pointer to an object of type double.
	double* lPtr;
	
	// b) Assign the address of variable value1 to pointer variable lPtr.
	lPtr = &value1;
	
	// c) Print the value of the object pointed to by lPtr.
	std::cout << *lPtr << "\n";

	// d) Assign the value of the object pointed to by lPtr to variable value2.
	value2 = *lPtr;
	
	// e) Print the value of value2.
	std::cout << value2 << "\n";

	// f) Print the address of value1.
	std::cout << &value1 << "\n";

	// g) Print the address stored in lPtr.Is the value printed the same as the address of value1 ?
	std::cout << lPtr << "\n";	// Yes the value printed is the same as the address of value 1.

	return 0;
}