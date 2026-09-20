#include "../include/RunSession.hpp"
#include "../include/RandomInputGenerator.hpp"
#include "../include/ModifiedRewardRule.hpp"
#include "../include/ShopSystem.hpp"
#include <iostream>

int main() {
    // Menyiapkan generator input acak dan aturan reward modifikasi
    RandomInputGenerator inputGen;
    DefaultScoringRule scoringRule;
    ModifiedRewardRule rewardRule;

    // Menjalankan simulasi 3 round
    RunSession session(inputGen, scoringRule, rewardRule);
    session.run();

    // Menampilkan sistem toko
    ShopSystem shop;
    shop.displayShop();

    return 0;
}