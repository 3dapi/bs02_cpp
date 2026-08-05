#include <array>
#include <iostream>
#include <span>
#include <vector>

void DoubleValues(std::span<int> values)
{
    for (int& value : values)
    {
        value *= 2;
    }
}

void PrintValues(std::span<const int> values)
{
    for (int value : values)
    {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

int main()
{
    int first[]{10, 20, 30};
    std::array<int, 3> second{40, 50, 60};
    std::vector<int> third{70, 80, 90};

    DoubleValues(first);
    DoubleValues(second);
    DoubleValues(third);

    PrintValues(first);
    PrintValues(second);
    PrintValues(third);
}
