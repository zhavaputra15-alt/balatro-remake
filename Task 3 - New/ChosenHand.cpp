#include "ChosenHand.h"
#include <iostream>

void ChosenHand::playHand(Hand& hand) {
    std::cout << "Player plays selected hand containing cards:\n";
    for (const auto& card : hand.cards) {
        std::cout << "Card - Rank: " << card.rank << ", Suit: " << card.suit << "\n";
    }
}