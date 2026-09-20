#ifndef IREWARD_RULE_HPP
#define IREWARD_RULE_HPP

class IRewardRule {
public:
    virtual ~IRewardRule() = default;
    virtual int computeReward(int baseScore) = 0;
};

class DefaultRewardRule : public IRewardRule {
public:
    int computeReward(int baseScore) override {
        return baseScore;
    }
};

#endif