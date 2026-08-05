#include <iostream>

consteval int Square(int value)
{
    return value * value;
}

int main()
{
    constexpr int first = Square(10);
    int second = Square(20);

    std::cout << first << '\n';
    std::cout << second << '\n';
}
