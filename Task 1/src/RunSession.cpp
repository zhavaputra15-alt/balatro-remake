#include "../include/RunSession.hpp"
#include <iostream>

RunSession::RunSession(IInputGenerator& ig, IScoringRule& sr, IRewardRule& rr)
    : inputGen(ig), scoringRule(sr), rewardRule(rr), money(0) {}

void RunSession::run() {
    std::cout << "=== RUN START ===\n\n";

    for (int round = 1; round <= 3; ++round) {
        std::cout << "Round " << round << "\n";

        // Phase 1: Generate input
        int input = inputGen.generateInput();
        std::cout << "[PLAY] input generated: " << input << "\n";

        // Phase 2: Compute base score
        int baseScore = scoringRule.computeBaseScore(input);
        std::cout << "[SCORE] base score: " << baseScore << "\n";

        // Phase 3: Compute reward
        int reward = rewardRule.computeReward(baseScore);

        // Phase 4: Update money
        money += reward;
        std::cout << "[REWARD] gain: " << reward << " | money: " << money << "\n";

        // Phase 5: Shop phase (nanti dihubungkan oleh Damar)
        std::cout << "[SHOP] skipped\n";

        // Phase 6: Advance round
        std::cout << "\n";
    }

    std::cout << "=== RUN END ===\n";
    std::cout << "Final money: " << money << "\n";
}