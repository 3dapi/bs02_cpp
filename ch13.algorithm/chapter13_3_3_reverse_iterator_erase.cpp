#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30, 20};

    auto reversePosition = std::find(values.rbegin(), values.rend(), 20);

    if (reversePosition != values.rend())
    {
        values.erase(std::prev(reversePosition.base()));
    }

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
