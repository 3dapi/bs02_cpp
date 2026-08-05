#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{30, 10, 20, 10, 30, 20};

    std::sort(values.begin(), values.end());
    values.erase(
        std::unique(values.begin(), values.end()),
        values.end());

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
