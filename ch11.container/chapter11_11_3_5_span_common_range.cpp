#include <array>
#include <iostream>
#include <span>
#include <vector>

int Sum(std::span<const int> values)
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
    int rawValues[]{1, 2, 3};
    std::array<int, 3> fixedValues{4, 5, 6};
    std::vector<int> dynamicValues{7, 8, 9};

    std::cout << Sum(rawValues) << ' '
              << Sum(fixedValues) << ' '
              << Sum(dynamicValues) << '\n';
}
