#ifndef DECKOFCARDS_H_
#define DECKOFCARDS_H_

#include "Card.h"

class DeckOfCards {
public:
	// a) An array of Cards named deck to store the Card Objects.
	Card *deck;

	// b) An int currentCard representing the next Card to deal.
	int currentCard = 0;

	// c) An const int SIZE_OF_DECK representing the number of cards in a deck.
	const int SIZE_OF_DECK = 52;

	// d) A default constructor that initializes each of the Cards in the deck.
	DeckOfCards();

	// e) A shuffle() function that shuffles the Cards in the deck.
	void shuffle();

	// f) A dealCard() function that returns the next Card object from the deck.
	Card dealCard();

	// g) A moreCards() function that returns a boolean value indicating whether there are more Cards to deal.
	bool moreCards();
};

#endif