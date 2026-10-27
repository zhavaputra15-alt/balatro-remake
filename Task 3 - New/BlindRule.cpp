#include "BlindRule.h"
#include <iostream>

BlindRule::BlindRule(int target) {
    targetScore = target;
}

bool BlindRule::checkBlind(int score) {
    std::cout << "Checking blind target score: " << targetScore << "\n";
    std::cout << "Current Player Score: " << score << "\n";

    // Logika pengecekan: Jika skor pemain >= target, maka menang (true)
    if (score >= targetScore) {
        std::cout << "Status: WIN! Target tercapai.\n";
        return true;
    } else {
        std::cout << "Status: LOSE! Skor kurang dari target.\n";
        return false;
    }
}