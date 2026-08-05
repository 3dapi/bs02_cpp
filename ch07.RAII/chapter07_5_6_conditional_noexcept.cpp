#include <iostream>
#include <string>
#include <utility>

template <typename T>
void SwapValue(T& first, T& second)
    noexcept(noexcept(std::swap(first, second)))
{
    std::swap(first, second);
}

int main()
{
    std::string first = "first";
    std::string second = "second";

    SwapValue(first, second);

    std::cout << first << ' '
              << second << '\n';
}
