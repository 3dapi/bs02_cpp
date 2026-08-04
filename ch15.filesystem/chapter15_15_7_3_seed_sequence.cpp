#include <iostream>
#include <random>

int main()
{
    std::seed_seq seed{10u, 20u, 30u, 40u};
    std::mt19937 engine{seed};

    std::cout << engine() << '\n';
}
