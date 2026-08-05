#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> values{5, 2, 8, 2, 1};

    auto position = std::find(values.begin(), values.end(), 8);
    std::sort(values.begin(), values.end());
    int total = std::accumulate(values.begin(), values.end(), 0);

    if (position != values.end())
    {
        std::cout << "found\n";
    }

    std::cout << "total=" << total << '\n';
}
