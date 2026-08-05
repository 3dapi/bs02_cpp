#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3, 4};

    auto squares = values | std::views::transform([](int value)
    {
        return value * value;
    });

    for (int value : squares)
    {
        std::cout << value << ' ';
    }
}
