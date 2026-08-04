#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30, 40};

    bool found = std::binary_search(values.begin(), values.end(), 30);
    std::cout << std::boolalpha << found << '\n';

    auto position = std::lower_bound(values.begin(), values.end(), 30);

    if (position != values.end() && *position == 30)
    {
        std::cout << "found\n";
    }
}
