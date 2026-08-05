#include <concepts>
#include <iostream>

template <typename T>
requires std::integral<T>
T AbsValue(T value)
{
    return value < 0 ? -value : value;
}

template <std::signed_integral T>
T Negative(T value)
{
    return -value;
}

auto Increment(std::integral auto value)
{
    return value + 1;
}

auto AddNumbers(std::integral auto left,
                std::integral auto right)
{
    return left + right;
}

template <std::integral T, std::integral U>
requires std::same_as<T, U>
auto AddSameType(T left, U right)
{
    return left + right;
}

int main()
{
    std::cout << AbsValue(-10) << '\n';
    std::cout << Negative(10) << '\n';
    std::cout << Increment(10) << '\n';
    std::cout << AddNumbers(10, 20u) << '\n';
    std::cout << AddSameType(10, 20) << '\n';
}
