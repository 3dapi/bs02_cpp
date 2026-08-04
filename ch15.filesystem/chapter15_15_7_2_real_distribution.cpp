#include <iostream>
#include <random>

int main()
{
    std::mt19937 engine{1234};
    std::uniform_real_distribution<double> ratio{0.0, 1.0};

    for (int i = 0; i < 3; ++i)
    {
        std::cout << ratio(engine) << '\n';
    }
}
