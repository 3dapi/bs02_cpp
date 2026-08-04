#include <iostream>
#include <random>

class DamageCalculator
{
public:
    explicit DamageCalculator(std::mt19937& engine)
        : engine(engine)
    {
    }

    int Calculate()
    {
        std::uniform_int_distribution<int> damage{10, 20};
        return damage(engine);
    }

private:
    std::mt19937& engine;
};

int main()
{
    std::mt19937 engine{1234};
    DamageCalculator calculator{engine};

    std::cout << calculator.Calculate() << '\n';
    std::cout << calculator.Calculate() << '\n';
}
