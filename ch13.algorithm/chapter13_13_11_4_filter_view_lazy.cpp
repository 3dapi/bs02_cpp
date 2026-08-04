#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3, 4, 5, 6};

    auto evenValues = values | std::views::filter([](int value)
    {
        return value % 2 == 0;
    });

    values[0] = 10;

    for (int value : evenValues)
    {
        std::cout << value << ' ';
    }
}
