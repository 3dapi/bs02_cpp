#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};

    for (auto iterator = values.begin(); iterator != values.end(); ++iterator)
    {
        std::cout << *iterator << ' ';
    }

    std::cout << "count="
              << std::distance(values.begin(), values.end())
              << '\n';
}
