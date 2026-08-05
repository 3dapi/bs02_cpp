#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 10, 20, 20, 10};

    auto newEnd = std::unique(values.begin(), values.end());
    values.erase(newEnd, values.end());

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
