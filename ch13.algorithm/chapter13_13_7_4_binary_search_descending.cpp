#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{30, 10, 40, 20};

    std::sort(values.begin(), values.end(), std::greater<>{});

    bool found = std::binary_search(
        values.begin(),
        values.end(),
        20,
        std::greater<>{});

    std::cout << std::boolalpha << found << '\n';
}
