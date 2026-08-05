#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30, 20, 40};
    auto newEnd = std::remove(values.begin(), values.end(), 20);

    for (auto iterator = values.begin(); iterator != newEnd; ++iterator)
    {
        std::cout << *iterator << ' ';
    }

    std::cout << "\nsize=" << values.size() << '\n';
}
