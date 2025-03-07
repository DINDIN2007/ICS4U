#include <iostream>
#include <iomanip>
#include "DeckOfCards.cpp"
#include "Card.cpp"

int main() {
	std::cout << std::boolalpha;

	// Test the parameter constructor
	Card card1(4, 6);
	std::cout << Card::faces[card1.face] << "of" << Card::suits[card1.suit] << "\n";

	// Test the copy constructor
	Card card2(card1);
	std::cout << card2 << "\n";

	// Test the overloaded assignment operator and stream insertion
	Card card3 = card1;
	std::cout << card3 << "\n";

	// Test the default constructor for DeckOfCards
	DeckOfCards deck1;
	for (int i = 0; i < deck1.SIZE_OF_DECK; i++) {
		std::cout << deck1.deck[i] << " ";
	}
	std::cout << "\n\n";

	// Test the shuffle method
	std::cout << "Shuffled Deck";
	deck1.shuffle();
	for (int i = 0; i < deck1.SIZE_OF_DECK; i++) {
		std::cout << deck1.deck[i] << " ";
	}
	std::cout << "\n\n";

	// Test the moreCards method
	std::cout << deck1.moreCards() << "\n\n";

	// Test the dealCards method
	for (int i = 0; i < deck1.SIZE_OF_DECK; i++) {
		std::cout << deck1.dealCard() << " ";
	}
	std::cout << "\n\n";

	// Test the moreCards method
	std::cout << deck1.moreCards() << "\n\n";

	return 0;
}