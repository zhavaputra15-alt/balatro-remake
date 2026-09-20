#ifndef ISCORING_RULE_HPP
#define ISCORING_RULE_HPP

class IScoringRule {
public:
    virtual ~IScoringRule() = default;
    virtual int computeBaseScore(int input) = 0;
};

class DefaultScoringRule : public IScoringRule {
public:
    int computeBaseScore(int input) override {
        return input * 2;
    }
};

#endif