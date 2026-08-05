#include <iostream>

constexpr int Square(int value)
{
    return value * value;
}

int main()
{
    constexpr int size = Square(10);
    static_assert(size == 100);

    std::cout << size << '\n';
}
