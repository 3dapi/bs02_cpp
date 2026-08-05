#include <cstdlib>
#include <iostream>
#include <random>
#include <ctime>

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int oldDice = std::rand() % 6 + 1;

    std::mt19937 engine{std::random_device{}()};
    std::uniform_int_distribution<int> dice{1, 6};
    int newDice = dice(engine);

    std::cout << oldDice << ' ' << newDice << '\n';
}
