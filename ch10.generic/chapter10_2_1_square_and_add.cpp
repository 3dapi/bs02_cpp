#include <iostream>

template <typename T>
T Square(T value)
{
    return value * value;
}

template <typename Left, typename Right>
auto Add(const Left& left, const Right& right)
{
    return left + right;
}

int main()
{
    std::cout << Square(5) << '\n';
    std::cout << Square(2.5) << '\n';
    std::cout << Add(10, 2.5) << '\n';
}
