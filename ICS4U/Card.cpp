#include "Card.h"

// f) Two static arrays of strings representing the faces and suits.
std::string Card::faces[13] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King" };
std::string Card::suits[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };

// Default Constructor
Card::Card() {
	this->face = 0;
	this->suit = 0;
}

// c) A parameterized constructor that receives two int values representing the face and suit of a card and uses them to initialize the data members.
Card::Card(int face, int suit) {
	bool isFace = face >= 1 && face <= 13, isSuit = suit >= 1 && suit <= 4;
	if (!(isFace && isSuit)) throw "The face or suit of the card is not valid.";
	this->face = face;
	this->suit = suit;
}

// d) A copy constructor to allow for the creation of new Cards from existing Cards.
Card::Card(const Card &card) {
	this->face = card.face;
	this->suit = card.suit;
}

// e) Overload the assignment operator for the same purpose as d).
Card& Card::operator = (Card& card) {
	if (this != &card) {
		this->face = card.face;
		this->suit = card.suit;
	}
	return *this;
}

// g) Overload the stream insertion(<< ) operator to output the Card as “face of suit”.
std::ostream& operator << (std::ostream& output, Card& card) {
	output << Card::faces[card.face] << " of " << Card::suits[card.suit];
	return output;
}
