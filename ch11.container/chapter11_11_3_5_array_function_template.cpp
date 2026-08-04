#include <array>
#include <cstddef>
#include <iostream>

template <std::size_t N>
int Sum(const std::array<int, N>& values)
{
    int total = 0;

    for (int value : values)
    {
        total += value;
    }

    return total;
}

int main()
{
    std::array<int, 3> first{1, 2, 3};
    std::array<int, 5> second{1, 2, 3, 4, 5};

    std::cout << Sum(first) << ' ' << Sum(second) << '\n';
}
