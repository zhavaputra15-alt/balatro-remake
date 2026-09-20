#ifndef MODIFIED_REWARD_RULE_HPP
#define MODIFIED_REWARD_RULE_HPP

#include "IRewardRule.hpp"

class ModifiedRewardRule : public IRewardRule {
public:
    int computeReward(int baseScore) override {
        return baseScore + 2;
    }
};

#endif