#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> values{};
    std::array<int, 0> emptyValues{};

    std::cout << values.front() << ' '
              << emptyValues.size() << ' '
              << std::boolalpha
              << (emptyValues.begin() == emptyValues.end())
              << '\n';
}
