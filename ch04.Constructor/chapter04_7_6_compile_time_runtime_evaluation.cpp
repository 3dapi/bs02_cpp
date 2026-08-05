#include <iostream>

constexpr int Square(int value)
{
    return value * value;
}

int main()
{
    constexpr int first = Square(10);

    int value = 20;
    int second = Square(value);

    static_assert(Square(5) == 25);

    std::cout << first << '\n';
    std::cout << second << '\n';
}
