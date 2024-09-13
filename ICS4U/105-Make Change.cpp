#include <iostream>
#include <string>

double billTotal, customerTender;

int main_105() {
	std::cout << "Bill Total: $ ";
	std::cin >> billTotal;
	std::cout << "Customer Tender: $ ";
	std::cin >> customerTender;
	std::cout << "Change is: ";

	if (billTotal > customerTender) {
		std::cout << "\ninsufficient tender";
		return 0;
	}

	if (billTotal == customerTender) {
		std::cout << "\nno change";
		return 0;
	}

	double remainder{ customerTender - billTotal };

	int dollars{ (int)(remainder) }; remainder -= dollars;
	if (dollars != 0) std::cout << "\n" << dollars << ((dollars > 1) ? " dollars" : " dollar");

	int quarters{ (int)(remainder / 0.25) }; remainder -= quarters * 0.25;
	if (quarters != 0) std::cout << "\n" << quarters << ((quarters > 1) ? " quarters" : " quarter");

	int dimes{ (int)(remainder / 0.1) }; remainder -= dimes * 0.1;
	if (dimes != 0) std::cout << "\n" << dimes << ((dimes > 1) ? " dimes" : " dime");

	int nickels{ (int)(remainder / 0.05) };
	if (nickels != 0) std::cout << "\n" << nickels << ((nickels > 1) ? " nickels" : " nickel");

	std::cout << "\n";

	return 0;
}