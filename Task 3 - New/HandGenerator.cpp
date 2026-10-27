#include <iostream>
#include <cstdlib>   // Untuk rand() dan srand()
#include <ctime>     // Untuk time()
#include "HandGenerator.h"

Hand HandGenerator::generateHand()
{
    std::cout << "Generating random hand...\n";
    
    // Inisialisasi seed random berdasarkan waktu saat ini
    srand(static_cast<unsigned int>(time(0)));

    Hand hand;
    char suits[] = {'H', 'D', 'C', 'S'}; // H: Heart, D: Diamond, C: Club, S: Spade

    // Menghasilkan 5 kartu secara acak
    for (int i = 0; i < 5; i++) {
        int randomRank = (rand() % 13) + 2;        // Rank acak antara 2 sampai 14 (Ace)
        char randomSuit = suits[rand() % 4];       // Pilih suit secara acak dari array

        hand.cards.push_back({randomRank, randomSuit});
    }

    return hand;
}