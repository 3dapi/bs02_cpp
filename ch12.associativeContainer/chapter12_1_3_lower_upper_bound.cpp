#include <iostream>
#include <set>

int main()
{
    std::set<int> values{10, 20, 30, 40, 50};

    auto first = values.lower_bound(20);
    auto last = values.upper_bound(40);

    for (auto iterator = first; iterator != last; ++iterator)
    {
        std::cout << *iterator << ' ';
    }
    std::cout << '\n';
}
