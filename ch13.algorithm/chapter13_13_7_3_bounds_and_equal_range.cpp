#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 20, 20, 30, 40};

    auto lower = std::lower_bound(values.begin(), values.end(), 20);
    auto upper = std::upper_bound(values.begin(), values.end(), 20);
    auto [first, last] = std::equal_range(values.begin(), values.end(), 20);

    std::cout << std::distance(lower, upper) << '\n';
    std::cout << std::distance(first, last) << '\n';
}
