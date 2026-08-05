#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> values{40, 10, 30, 20};

    std::ranges::sort(values);
    auto position = std::ranges::find(values, 30);

    if (position != values.end())
    {
        std::cout << *position << '\n';
    }
}
