#include <iostream>
#include <cstdlib>
#include <ctime>
#include "HandGenerator.h"

Hand HandGenerator::generateHand() {
    std::cout << "Generating random cards for player...\n";
    
    // Memastikan seed benar-benar acak
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    
    // Pilihan nilai: 2 (Pair), 6 (Flush), 7 (Full House)
    int randomChoices[] = {2, 6, 7};
    int randomIndex = rand() % 3; 
    
    Hand hand;
    hand.value = randomChoices[randomIndex];
    
    std::cout << "[DEBUG] Nilai kartu random yang dihasilkan: " << hand.value << "\n";
    
    return hand;
}