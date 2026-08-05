#include <iostream>

int main()
{
    auto add = [](auto left, auto right)
    {
        return left + right;
    };

    std::cout << add(10, 20) << '\n';
    std::cout << add(1.5, 2.5) << '\n';
}
