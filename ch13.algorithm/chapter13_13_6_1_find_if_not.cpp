#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, -5, 30};

    auto position = std::find_if_not(
        values.begin(),
        values.end(),
        [](int value)
        {
            return value > 0;
        });

    if (position != values.end())
    {
        std::cout << *position << '\n';
    }
}
