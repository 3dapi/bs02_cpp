#include <iostream>
#include <random>

int RollDiceCopy(std::mt19937 engine)
{
    std::uniform_int_distribution<int> dice{1, 6};
    return dice(engine);
}

int RollDice(std::mt19937& engine)
{
    std::uniform_int_distribution<int> dice{1, 6};
    return dice(engine);
}

int main()
{
    std::mt19937 engine{1234};

    std::cout << RollDiceCopy(engine) << ' '
              << RollDiceCopy(engine) << '\n';

    std::cout << RollDice(engine) << ' '
              << RollDice(engine) << '\n';
}
