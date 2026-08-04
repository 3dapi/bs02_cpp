#include <cstdlib>
#include <iostream>
#include <random>

int main()
{
    std::srand(1234);
    int oldDice = std::rand() % 6 + 1;

    std::mt19937 engine{1234};
    std::uniform_int_distribution<int> dice{1, 6};
    int newDice = dice(engine);

    std::cout << oldDice << ' ' << newDice << '\n';
}
