#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

double billTotal, customerTender;

int main_105() {
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	std::cin >> billTotal >> customerTender;

	std::cout << "Bill Total: $" << billTotal << "\n";
	std::cout << "Customer Tender: $" << customerTender << "\n";
	std::cout << "Change is: \n";

	if (billTotal > customerTender) {
		std::cout << "insufficient tender";
		return 0;
	}

	if (billTotal == customerTender) {
		std::cout << "no change";
		return 0;
	}

	double remainder{ customerTender - billTotal };

	int dollars{ (int)(remainder) }; remainder -= dollars;
	if (dollars != 0) std::cout << dollars << ((dollars > 1) ? " dollars\n" : " dollar\n");

	int quarters{ (int)(round(remainder * 100) / 25) }; remainder -= quarters * 0.25;
	if (quarters != 0) std::cout << quarters << ((quarters > 1) ? " quarters \n" : " quarter \n");

	int dimes{ (int)(round(remainder * 100) / 10) }; remainder -= dimes * 0.1;
	if (dimes != 0) std::cout << dimes << ((dimes > 1) ? " dimes\n" : " dime\n");

	int nickels{ (int)(round(remainder * 100) / 5) };
	if (nickels != 0) std::cout << nickels << ((nickels > 1) ? " nickels\n" : " nickel\n");

	return 0;
}