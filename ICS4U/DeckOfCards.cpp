#include <iostream>
#include "DeckOfCards.h"

// d) A default constructor that initializes each of the Cards in the deck.
DeckOfCards::DeckOfCards() {
	this->deck = new Card[DeckOfCards::SIZE_OF_DECK];
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 4; j++) {
			Card temp_card (i, j);
			deck[i * 4 + j] = temp_card;
		}
	}
}

// e) A shuffle() function that shuffles the Cards in the deck.
// The shuffle algorithm should iterate through the array of Cards.
// For each Card, randomly select another Card in the deck and swap the two Cards.
void DeckOfCards::shuffle() {
	for (int i = 0; i < SIZE_OF_DECK; i++) {
		int swap_place = rand() % SIZE_OF_DECK;
		Card temp_card = deck[swap_place];
		deck[swap_place] = deck[i];
		deck[i] = temp_card;
	}
}

// f) A dealCard() function that returns the next Card object from the deck.
Card DeckOfCards::dealCard() {
	if (moreCards()) {
		Card dealtCard(deck[currentCard++]);
		return dealtCard;
	}
	throw "No more cards left in this deck";
}

// g) A moreCards() function that returns a boolean value indicating whether there are more Cards to deal.
bool DeckOfCards::moreCards() {
	return currentCard < SIZE_OF_DECK;
}