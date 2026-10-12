#include <iostream>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    std::cout << "Generating cards for player...\n";
    Hand hand;
    hand.value = 6; // Dummy: mensimulasikan kartu Flush
    return hand;
}