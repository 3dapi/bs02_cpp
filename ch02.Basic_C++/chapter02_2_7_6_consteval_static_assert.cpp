#include <iostream>

consteval int Cube(int value)
{
    return value * value * value;
}

int main()
{
    constexpr int result = Cube(3);
    static_assert(result == 27);
    std::cout << result << '\n';
}
