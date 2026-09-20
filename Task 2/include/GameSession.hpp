#ifndef GAME_SESSION_HPP
#define GAME_SESSION_HPP

#include "RaceState.hpp"
#include <iostream>

class GameSession {
private:
    RaceState state;

public:
    GameSession(int maxRounds = 3) : state(maxRounds) {}

    void PlayerAction() {
        std::cout << "\n--- Round " << state.currentRound << " ---\n";
        std::cout << "[Step 1] Player selects horse speed modifier and places bet.\n";
    }

    void ResolveSystem() {
        std::cout << "[Step 2] System calculates horse movement and track positions.\n";
    }

    void UpdateState() {
        std::cout << "[Step 3] Reward processed, round updated.\n";
        state.currentRound++;
        if (state.currentRound > state.maxRounds) {
            state.isGameOver = true;
        }
    }

    bool IsGameOver() const {
        return state.isGameOver;
    }

    void StartGame() {
        std::cout << "=== STARTING HORSE RACING GAME LOOP ===\n";
        while (!IsGameOver()) {
            PlayerAction();
            ResolveSystem();
            UpdateState();
        }
        std::cout << "\n=== GAME OVER: Race Finished ===\n";
    }
};

#endif