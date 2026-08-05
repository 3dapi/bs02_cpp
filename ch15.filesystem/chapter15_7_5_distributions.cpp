#include <iostream>
#include <random>

int main()
{
    std::mt19937 engine{1234};
    std::bernoulli_distribution criticalHit{0.2};
    std::normal_distribution<double> height{170.0, 8.0};

    std::cout << std::boolalpha << criticalHit(engine) << '\n';
    std::cout << height(engine) << '\n';
}
