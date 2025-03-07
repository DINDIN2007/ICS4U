#ifndef CARD_H_
#define CARD_H_
#include <iostream>

class Card {
public:
	// a) Instance variables face and suit of type int.
	// Face (0 = Ace, 1-9 = 2-10, 10 = Jack, 11 = Queen, 12 = King)
	int face;
	// Suit (1 = Diamonds, 2 = Clubs, 3 = Hearts, 4 = Spades)
	int suit;

	// b) A default Constructor
	Card();

	// c) A parameterized constructor that receives two int values representing the face and suit of a card and uses them to initialize the data members.
	Card(int face, int suit);

	// d) A copy constructor to allow for the creation of new Cards from existing Cards.
	Card(const Card &card);

	// e) Overload the assignment operator for the same purpose as d).
	Card& operator = (Card& card);

	// f) Two static arrays of strings representing the faces and suits.
	static std::string faces[13];
	static std::string suits[4];
};

#endif 