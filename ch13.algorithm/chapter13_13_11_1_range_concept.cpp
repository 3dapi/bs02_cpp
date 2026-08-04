#include <iostream>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> values{10, 20, 30};

    static_assert(std::ranges::range<decltype(values)>);

    auto first = std::ranges::begin(values);
    auto last = std::ranges::end(values);

    for (; first != last; ++first)
    {
        std::cout << *first << ' ';
    }
}
