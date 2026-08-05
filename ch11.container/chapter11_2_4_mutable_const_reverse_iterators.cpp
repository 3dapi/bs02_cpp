#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};

    for (auto iterator = values.begin(); iterator != values.end(); ++iterator)
    {
        *iterator *= 2;
    }

    auto constIterator = values.cbegin();
    std::cout << *constIterator << '\n';

    for (auto iterator = values.rbegin(); iterator != values.rend(); ++iterator)
    {
        std::cout << *iterator << ' ';
    }

    std::cout << '\n';
}
