#include <iostream>
#include <random>

int main()
{
    std::mt19937 engine{1234};
    std::uniform_int_distribution<int> dice{1, 6};

    for (int i = 0; i < 10; ++i)
    {
        std::cout << dice(engine) << ' ';
    }

    std::cout << '\n';
}
