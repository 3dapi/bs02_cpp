#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> values{30, 10, 20};
    std::sort(values.begin(), values.end(), std::greater<>{});

    std::plus<> add;

    std::cout << add(10, 20) << '\n';
    std::cout << add(1.5, 2.5) << '\n';
}
