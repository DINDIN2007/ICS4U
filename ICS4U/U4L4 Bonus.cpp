#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"

/*
1. Modify main.cpp class so that it deals a five-card poker hand. Then write functions to identify
whether it contains a pair, two pairs, three or four of a kind, flush, straight, full house, etc.
2. Modify the main.cpp class so that it deals two five-card poker hands, and checks to see which
hand is better.
3. Modify the program so that it simulates a game of poker. You can choose which version of poker
you would like to model. The player should be able to see their hand, as well as select which cards
they would like to exchange (if you are modelling a version that involves this). The dealer should be
also programmed to make the choices necessary to play against you. A winner should be
determined when the game ends.
*/

const int cardsPerHand = 5;

Card* dealPokerHand(DeckOfCards &deck) {
	Card* hand = new Card[cardsPerHand];
	for (int i = 0; i < 5; i++) {
		Card newHand = deck.dealCard();
		hand[i] = newHand;
	}
	return hand;
}

Card* dealPokerHandNormal(DeckOfCards& deck) {
	Card* hand = new Card[cardsPerHand];
	for (int i = 0; i < 3; i++) {
		Card newHand = deck.dealCard();
		hand[i] = newHand;
	}
	return hand;
}

void sortHand(Card* hand) {
	for (int i = 1; i < 5; i++) {
		int count = i;
		while (count > 0 && hand[count].face <= hand[count - 1].face) {
			Card temp_card = hand[count - 1];
			hand[count - 1] = hand[count];
			hand[count] = temp_card;
			count--;
		}
	}
}

double checkStraightFlush(Card* hand) {
	bool isStraight = true;
	for (int i = 0; i < 5; i++) {
		if (hand[0].suit != hand[i].suit) {
			isStraight = false;
		}
	}

	// Consider Ace that can either be equal to 1 or 13
	if (hand[0].face == 0) {
		if (hand[1].face == 1) {
			for (int i = 1; i < 5; i++) {
				if (hand[i].face != hand[i - 1].face + 1) {
					if (isStraight) {
						return 6.0 + (hand[4].face * 0.01) + (hand[4].suit * 0.001) + (hand[3].face * 0.00001) + (hand[4].suit * 0.000001) + (hand[3].face * 0.0000001) + (hand[3].suit * 0.000000001) + (hand[2].face * 0.000000001) + (hand[2].suit * 0.000000000001) + (hand[1].face * 0.00000000001) + (hand[1].suit * 0.000000000000001) + (hand[0].face * 0.0000000000001) + (hand[0].suit * 0.000000000000000001);
					}
					return 0;
				}
			}
			return ((isStraight) ? 9.0 : 7.0) + (hand[0].suit * 0.001);
		}
		else if (hand[4].face == 12) {
			for (int i = 2; i < 5; i++) {
				if (hand[i].face != hand[i - 1].face + 1) {
					if (isStraight) {
						return 6.0 + (hand[4].face * 0.01) + (hand[4].suit * 0.001) + (hand[3].face * 0.00001) + (hand[4].suit * 0.000001) + (hand[3].face * 0.0000001) + (hand[3].suit * 0.000000001) + (hand[2].face * 0.000000001) + (hand[2].suit * 0.000000000001) + (hand[1].face * 0.00000000001) + (hand[1].suit * 0.000000000000001) + (hand[0].face * 0.0000000000001) + (hand[0].suit * 0.000000000000000001);
					}
					return 0;
				}
			}
			return ((isStraight) ? 9.12 : 7.12) + (hand[0].suit * 0.001);
		}
	}
	else {
		for (int i = 1; i < 5; i++) {
			if (hand[i].face != hand[i - 1].face + 1) {
				if (isStraight) {
					return 6.0 + (hand[4].face * 0.01) + (hand[4].suit * 0.001) + (hand[3].face * 0.00001) + (hand[4].suit * 0.000001) + (hand[3].face * 0.0000001) + (hand[3].suit * 0.000000001) + (hand[2].face * 0.000000001) + (hand[2].suit * 0.000000000001) + (hand[1].face * 0.00000000001) + (hand[1].suit * 0.000000000000001) + (hand[0].face * 0.0000000000001) + (hand[0].suit * 0.000000000000000001);
				}
				return 0;
			}
		}

		return ((isStraight) ? 9.0 : 7.0) + (hand[4].face * 0.01) + (hand[0].suit * 0.001);
	}
}

double checkPairs(Card* hand) {
	int face = hand[0].face, count = 1, highest_count = 1, index = 0;
	// For two pair
	int index2 = -1, face2 = -1;

	for (int i = 1; i < 5; i++) {
		if (hand[i - 1].face == hand[i].face) {
			count++;
		}
		else {
			if (count > highest_count) {
				face = hand[i].face;
				index = i;
				highest_count = count;
			}
			else if (count == highest_count && count == 2) {
				face = hand[i].face;
				index2 = i;
			}
			count = 1;
		}
	}

	Card kicker1, kicker2; bool isKicker1Set = false;

	switch (highest_count) {
		// Four of a kind
		case 4:
			for (int i = 0; i < 5; i++) {
				if (hand[i].face != hand[index].face) {
					kicker1 = hand[i];
				}
			}
			return 8.0 + (hand[index].face * 0.01) + (kicker1.face * 0.0001) + (kicker1.suit * 0.00001);
		case 3:
			for (int i = 0; i < 5; i++) {
				if (hand[i].face != hand[index].face) {
					if (!isKicker1Set) kicker1 = hand[i];
					else kicker2 = hand[i];
				}
			}

			// Full House
			if (kicker1.face == kicker2.face) {
				return 7.0 + (hand[index].face * 0.01) + (kicker1.face * 0.0001);
			}
			// Three of a kind
			else {
				return 4.0 + (hand[index].face * 0.01) + (std::max(kicker1.face, kicker2.face) * 0.0001) + (std::min(kicker1.face, kicker2.face) * 0.000001);
			}
		case 2:
			// Two pairs
			if (index2 != -1) {
				return 3.0 + (std::max(hand[index].face, hand[index2].face) * 0.01) + (std::min(hand[index].face, hand[index2].face) * 0.0001);
			}
			// One pair
			int highestKicker = -1;
			for (int i = 0; i < 5; i++) {
				if (hand[i].face != hand[index].face) {
					highestKicker = std::max(highestKicker, hand[i].face);
				}
			}
			return 2.0 + (hand[index].face * 0.01) + (highestKicker * 0.0001); // Assuming we don't check the 2nd and 3rd kicker
	}
	// High Card
	return 1.0 + (hand[4].face * 0.01) + (hand[4].suit * 0.001) + (hand[3].face * 0.00001) + (hand[4].suit * 0.000001) + (hand[3].face * 0.0000001) + (hand[3].suit * 0.000000001) + (hand[2].face * 0.000000001) + (hand[2].suit * 0.000000000001) + (hand[1].face * 0.00000000001) + (hand[1].suit * 0.000000000000001) + (hand[0].face * 0.0000000000001) + (hand[0].suit * 0.000000000000000001);
}

double evaluateHand(Card* hand) {
	// Sort the hand by the value of the face
	sortHand(hand);

	double straightFlush = checkStraightFlush(hand);
	double pairs = checkPairs(hand);

	return std::max(straightFlush, pairs);
}

std::string handValueInWords(double handValue) {
	switch ((int)(handValue)) {
	case 1 :
		return "High Card";
	case 2:
		return "One Pair";
	case 3:
		return "Two Pair";
	case 4:
		return "Three of a kind";
	case 5:
		return "Straight";
	case 6:
		return "Flush";
	case 7:
		return "Full House";
	case 8:
		return "Four of a kind";
	case 9:
		return "Straight Flush";
	}
}

int currentBet, playerBet, dealerBet, playerRaise;
bool playerFolded;

void betting() {
	std::cout << "Actions : Call | Raise | Fold\nType Action : ";
	std::string action;  std::cin >> action;

	switch (action[0]) {
	case 'C': case 'c':
		std::cout << "You matched the dealer's bet\n";
		playerBet = currentBet;
		break;
	case 'R': case 'r':
		std::cout << "By how many times do you want to raise the bet\n";
		std::cin >> playerRaise;
		currentBet *= playerRaise;
		playerBet = currentBet;
		break;
	case 'F': case 'f':
		std::cout << "Fold\n";
		playerFolded = true;
		break;
	default:
		std::cout << "Literacy test, please learn to read.";
		return;
	}

	if (!playerFolded) {
		switch (rand() % 3) {
		case 1:
			std::cout << "The dealer called and matched your bet\n";
			dealerBet = playerBet;
			break;
		case 2:
			std::cout << "The dealer raised and doubled your bet\n";
			dealerBet = playerBet * 2;
			currentBet = dealerBet;
			break;
		default:
			std::cout << "The dealer folded\n";
			dealerBet = -1;
		}
	}

	std::cout << "Current bet : " << currentBet << "\n\n";
}

int main() {
	DeckOfCards deck;
	deck.shuffle();

	/* Testing code
	Card* hand1 = dealPokerHand(deck);
	double hand1Value = evaluateHand(hand1);
	std::cout << "Hand : \n";
	for (int i = 0; i < 5; i++) {
		std::cout << hand1[i] << " | ";
	}
	std::cout << "\nHand Value : " << hand1Value << ".\n";
	std::cout << "\nHand Value : " << handValueInWords(hand1Value) << ".\n\n";

	Card* hand2 = dealPokerHand(deck);
	double hand2Value = evaluateHand(hand2);
	std::cout << "Hand : \n";
	for (int i = 0; i < 5; i++) {
		std::cout << hand2[i] << " | ";
	}
	std::cout << "\nHand Value : " << hand2Value << ".\n";
	std::cout << "\nHand Value : " << handValueInWords(hand2Value) << ".\n\n";

	std::cout << "The " << ((hand1Value > hand2Value) ? "first" : "second") << " hand wins !";
	*/

	// Introduction
	std::cout << "Welcome to the CB Gambling Den\n";
	std::cout << "Today's game is all about poker, where you will be going against this dealer bot\n\n";
	
	int money = 5000;
	
	while (money > 0) {
		std::cout << "Your current funds are " << money << " .\n";
		std::cout << "Do you want to proceed gambling ? [Yes/No] \n";

		std::string ans; std::cin >> ans;
		switch (ans[0]) {
		case 'Y': case 'y':
			std::cout << "ALRIGHT LET'S GAMBLE !!!\n\n";
			break;
		case 'N': case 'n':
			std::cout << "You can always win more if you just kept going T-T.";
			std::cout << "Your remaining funds is " << money << ".";
			return 0;
		default:
			std::cout << "Literacy test, please learn to read.";
			return 0;
		}

		currentBet = 0, playerBet = 0, dealerBet = 0, playerRaise = 0;
		playerFolded = false;

		// 1. Pre-flop
		Card turn1 = deck.dealCard(), turn2 = deck.dealCard();

		// 2. Flop
		Card* playerHand = dealPokerHandNormal(deck);
		Card* dealerHand = dealPokerHandNormal(deck);

		std::cout << "Here is your three cards : \n" <<
			playerHand[0] << " | " <<
			playerHand[1] << " | " <<
			playerHand[2] << "\n\n";

		playerHand[3] = turn1; dealerHand[3] = turn1;
		playerHand[4] = turn2; dealerHand[4] = turn2;

		std::cout << "How much do you want to bet ?\n";
		std::cin >> playerBet;
		currentBet = playerBet;

		switch (rand() % 2) {
		case 1:
			std::cout << "The dealer called and matched your bet\n";
			dealerBet = playerBet;
			break;
		default:
			std::cout << "The dealer raised and doubled your bet\n";
			dealerBet = playerBet * 2;
			currentBet = dealerBet;
			break;
		}
		std::cout << "Current bet : " << currentBet << "\n\n";

		if (!(playerFolded || dealerBet == -1)) {
			betting();
		}

		// 3. Turn
		std::cout << "The first turn is " << turn1 << "\n";

		if (!(playerFolded || dealerBet == -1)) {
			betting();
		}

		// 4. River
		std::cout << "The second turn is " << turn2 << "\n\n";

		if (!(playerFolded || dealerBet == -1)) {
			betting();
		}

		// 5. Showdown
		double playerHandValue = evaluateHand(playerHand);
		std::string playerHandValueName = handValueInWords(playerHandValue);

		double dealerHandValue = evaluateHand(dealerHand);
		std::string dealerHandValueName = handValueInWords(dealerHandValue);

		std::cout << "The dealer's cards were " << dealerHand[0] << " | " << dealerHand[1] << " | " << dealerHand[2] << ".\n";

		std::cout << "You had a " << playerHandValueName << " and the dealer had a " << dealerHandValueName << ".\n\n";

		if (playerHandValue > dealerHandValue) {
			std::cout << "YOU WON\n"; 
			if (playerBet != -1) {
				std::cout << "Winnings : " << currentBet << "!\n\n";
				money += currentBet;
			}
		}
		else {
			std::cout << "YOU LOST\n";
			if (!(playerFolded || dealerBet == -1)) {
				std::cout << "Losings : " << currentBet << "!\n\n";
				money -= currentBet;
			}
			else if (playerFolded) {
				std::cout << "Losings : " << currentBet << "!\n\n";
				money -= playerBet;
			}
		}
	}
	

	return 0;
}