#ifndef IINPUT_GENERATOR_HPP
#define IINPUT_GENERATOR_HPP

class IInputGenerator {
public:
    virtual ~IInputGenerator() = default;
    virtual int generateInput() = 0;
};

// Generator awal dengan nilai tetap
class FixedInputGenerator : public IInputGenerator {
public:
    int generateInput() override {
        return 3;
    }
};

#endif