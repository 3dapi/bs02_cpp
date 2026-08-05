#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> scores{70, 95, 80, 60, 100, 85};

    std::partial_sort(
        scores.begin(),
        scores.begin() + 3,
        scores.end(),
        std::greater<>{});

    for (auto iterator = scores.begin(); iterator != scores.begin() + 3; ++iterator)
    {
        std::cout << *iterator << ' ';
    }
}
