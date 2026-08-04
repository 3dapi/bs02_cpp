#include <concepts>
#include <iostream>

template <std::integral T>
void DescribeNumber(T value)
{
    std::cout << "integral: " << value << '\n';
}

template <std::signed_integral T>
void DescribeNumber(T value)
{
    std::cout << "signed integral: " << value << '\n';
}

template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

template <Number T>
void PrintNumber(T value)
{
    if constexpr (std::integral<T>)
    {
        std::cout << "integer: " << value << '\n';
    }
    else
    {
        std::cout << "real: " << value << '\n';
    }
}

int main()
{
    DescribeNumber(10);
    DescribeNumber(10u);

    PrintNumber(20);
    PrintNumber(3.5);
}
