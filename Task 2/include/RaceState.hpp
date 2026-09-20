#ifndef RACE_STATE_HPP
#define RACE_STATE_HPP

struct RaceState
{
    int currentRound;
    int maxRounds;
    bool isGameOver;
    float speedMultiplier;
    int bettingMultiplier;

    RaceState(int totalRounds = 3)
        : currentRound(1), maxRounds(totalRounds), isGameOver(false), speedMultiplier(1.5f), bettingMultiplier(2) {}
};

#endif