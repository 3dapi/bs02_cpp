#include <iostream>
#include <memory>
#include <utility>

class Enemy
{
};

int main()
{
    auto first = std::make_unique<Enemy>();
    auto second = std::move(first);

    std::cout << std::boolalpha;
    std::cout << static_cast<bool>(first) << '\n';
    std::cout << static_cast<bool>(second) << '\n';

    first = std::make_unique<Enemy>();

    std::cout << static_cast<bool>(first) << '\n';
}
