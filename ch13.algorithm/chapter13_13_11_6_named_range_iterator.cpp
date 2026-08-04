#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> values{1, 2, 3};
    auto position = std::ranges::find(values, 2);

    if (position != values.end())
    {
        std::cout << *position << '\n';
    }
}
