#ifndef RUN_SESSION_HPP
#define RUN_SESSION_HPP

#include "IInputGenerator.hpp"
#include "IScoringRule.hpp"
#include "IRewardRule.hpp"

class RunSession {
private:
    IInputGenerator& inputGen;
    IScoringRule& scoringRule;
    IRewardRule& rewardRule;
    int money;

public:
    RunSession(IInputGenerator& ig, IScoringRule& sr, IRewardRule& rr);
    void run();
};

#endif