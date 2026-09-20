#ifndef RANDOM_INPUT_GENERATOR_HPP
#define RANDOM_INPUT_GENERATOR_HPP

#include "IInputGenerator.hpp"
#include <cstdlib>

class RandomInputGenerator : public IInputGenerator {
public:
    int generateInput() override {
        return (rand() % 5) + 1;
    }
};

#endif