#include <algorithm>
#include <execution>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{5, 4, 3, 2, 1};

    std::sort(
        std::execution::par,
        values.begin(),
        values.end());

    for (int value : values)
    {
        std::cout << value << ' ';
    }
}
