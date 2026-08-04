#include <array>
#include <cstddef>
#include <iostream>

void PrintCValues(const int values[], std::size_t size)
{
    for (std::size_t index = 0; index < size; ++index)
    {
        std::cout << values[index] << ' ';
    }

    std::cout << '\n';
}

void PrintValues(const std::array<int, 4>& values)
{
    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main()
{
    int rawValues[]{1, 2, 3, 4};
    std::array<int, 4> first{1, 2, 3, 4};
    std::array<int, 4> second = first;

    PrintCValues(rawValues, 4);
    PrintValues(second);
}
