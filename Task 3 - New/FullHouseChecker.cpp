#include <iostream>
#include "FullHouseChecker.h"

bool isFullHouse(const Hand& hand) {
    return hand.value == 7; // Dummy: value 7 mensimulasikan Full House
}

HandRank FullHouseChecker::check(const Hand& hand) {
    if (isFullHouse(hand)) {
        std::cout << "Detected FULL HOUSE\n";
        return HandRank::FULL_HOUSE;
    }
    if (nextChecker)
        return nextChecker->check(hand);
    return HandRank::HIGH_CARD;
}